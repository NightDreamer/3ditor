#include "preview.h"
#include <QTimer>

static const char* vertexShaderSource =
"#version 330 core \n"
"layout(location = 0) in vec3 position; \n"
"layout(location = 1) in vec2 uv; \n"
"uniform mat4 matrix;\n"
"out vec2 texCoord; \n"
"\n"
"void main()\n"
"{\n"
"	gl_Position = matrix * vec4(position, 1.0); \n"
"	texCoord = uv; \n"
"}\n";

static const char* fragmentShaderSource =
"#version 330 core \n"
"in vec2 texCoord; \n"
"out vec4 fColor; \n"
"uniform sampler2D tex; \n"
"\n"
"void main() \n"
"{\n"
"	fColor = texture(tex, texCoord); \n"
"}\n";

Preview::Preview(QWidget* parent) : QOpenGLWidget(parent)
{
	this->setUpdateBehavior(QOpenGLWidget::UpdateBehavior::NoPartialUpdate);

	QTimer* timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &Preview::animate);
	timer->start(16);
}

Preview::~Preview()
{
	// erase model pointer
	previewModel = nullptr;

	// erase previous created VAOs
	while (m_vaos.size() > 0)
	{
		m_vaos.back()->destroy();
		delete m_vaos.back();
		m_vaos.pop_back();
	}

	// destroy our shader object
	delete m_program;
}

void Preview::initializeGL()
{
	// initialise
	initializeOpenGLFunctions();
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glViewport(0.0f, 0.0f, float(width()) * devicePixelRatio(), float(height()) * devicePixelRatio());
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	// create shader object
	m_program = new QOpenGLShaderProgram(this);
	m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
	m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
	m_program->link();

	// setup matrices
	m_projection.setToIdentity();
	m_projection.perspective(fov, float(width()) / float(height()), 0.01f, 1000.0f);

	m_view.setToIdentity();
	m_view.lookAt(QVector3D(0.0f, 2.0f, -2.0f), QVector3D(0.0f, 0.0f, 0.0f), QVector3D(0.0f, 1.0f, 0.0f));
}

void Preview::resizeGL(int w, int h)
{
	const qreal retinaScale = devicePixelRatio();
	glViewport(0.0f, 0.0f, float(width()) * retinaScale, float(height()) * retinaScale);
}

void Preview::paintGL()
{
	// clear
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	if (previewModel)
	{
		// animate model
		if (autoRotation)
			m_model.rotate(8.0f * 0.016f, QVector3D(0.0f, 1.0f, 0.0f));

		// render using our shader
		m_program->bind();
		m_program->setUniformValue(m_program->uniformLocation("matrix"), m_projection * m_view * m_model);
		{
			for (unsigned int i = 0; i < previewModel->getMeshs().size(); i++)
			{
				m_vaos[i]->bind();
				previewModel->getMeshs()[i]->getTexture()->bind();
				glDrawArrays(GL_TRIANGLES, 0, previewModel->getMeshs()[i]->getNumVertices());
				previewModel->getMeshs()[i]->getTexture()->release();
				m_vaos[i]->release();
			}
		}
		m_program->release();
	}
}

void Preview::wheelEvent(QWheelEvent* event)
{
	// calculate new fov for zoom in/out
	fov -= event->angleDelta().y()  * 0.016f;

	// recalculate projection matrix
	m_projection.setToIdentity();
	m_projection.perspective(fov, float(width()) / float(height()), 0.01f, 1000.0f);
}

void Preview::setModel(Model* model)
{
	// bind context and shader
	makeCurrent();
	m_program->bind();

	// store model
	previewModel = model;

	// erase previous created VAOs
	while (m_vaos.size() > 0)
	{
		m_vaos.back()->destroy();
		delete m_vaos.back();
		m_vaos.pop_back();
	}

	// if model is valid
	if (model)
	{
		// setup model matrix
		m_model.setToIdentity();
		m_model.rotate(45.0f, QVector3D(0.0f, 1.0f, 0.0f));
		m_model.scale(previewModel->getNormalisingValue());

		// setup VAOs
		for (unsigned int i = 0; i < model->getMeshs().size(); i++)
		{
			m_vaos.push_back(new QOpenGLVertexArrayObject());
			m_vaos.back()->create();
			if (m_vaos.back()->isCreated())
			{
				m_vaos.back()->bind();
				model->getMeshs()[i]->getVertexBufferObject().bind();
				m_program->enableAttributeArray(0);
				m_program->setAttributeBuffer(0, GL_FLOAT, 0 * sizeof(float), 3, 5 * sizeof(float));
				m_program->enableAttributeArray(1);
				m_program->setAttributeBuffer(1, GL_FLOAT, 3 * sizeof(float), 2, 5 * sizeof(float));
				model->getMeshs()[i]->getVertexBufferObject().release();
				m_vaos.back()->release();
			}
			else
			{
				qDebug() << "Couldn't create VAO!\n";
			}
		}
	}

	// unbind shader and context
	m_program->release();
	doneCurrent();
}

void Preview::setAutoRotation(bool autoRotation)
{
	this->autoRotation = autoRotation;
}
