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
	// actually destroy our OpenGL information
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

	// create Shader (Do not release until VAO is created)
	m_program = new QOpenGLShaderProgram(this);
	m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
	m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
	m_program->link();
}

void Preview::resizeGL(int w, int h)
{
	this->setFixedSize(w, h);
	const qreal retinaScale = devicePixelRatio();
	glViewport(0.0f, 0.0f, float(width()) * retinaScale, float(height()) * retinaScale);
}

void Preview::paintGL()
{
	// clear
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	if (previewModel)
	{
		// setup matrices
		QMatrix4x4 projection;
		projection.setToIdentity();
		projection.perspective(60.0f, float(width()) / float(height()), 0.01f, 1000.0f);

		QMatrix4x4 view;
		view.setToIdentity();
		view.lookAt(QVector3D(0.0f, 2.0f, -2.0f), QVector3D(0.0f, 0.0f, 0.0f), QVector3D(0.0f, 1.0f, 0.0f));

		QMatrix4x4 model;
		model.setToIdentity();
		model.rotate(45.0f, QVector3D(0.0f, 1.0f, 0.0f));
		model.scale(previewModel->getNormalisingValue());

		// animate model
		rotate += 4.0f * 0.016f;
		if (rotate > 360.0f)
			rotate -= 360.0f;
		model.rotate(rotate, QVector3D(0.0f, 1.0f, 0.0f));

		// render using our shader
		m_program->bind();
		m_program->setUniformValue(m_program->uniformLocation("matrix"), projection * view * model);
		{
			previewModel->draw();
		}
		m_program->release();
	}
}

void Preview::animate()
{
	update();
}
