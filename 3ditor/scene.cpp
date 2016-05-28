#include "scene.h"
#include <QTimer>


Scene::Scene(QWidget* parent) : QOpenGLWidget(parent)
{
	this->setUpdateBehavior(QOpenGLWidget::UpdateBehavior::NoPartialUpdate);

	QTimer* timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &Scene::animate);
	timer->start(16);
}


Scene::~Scene()
{
}

void Scene::initializeGL()
{
	// initialise
	initializeOpenGLFunctions();
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glViewport(0.0f, 0.0f, float(width()) * devicePixelRatio(), float(height()) * devicePixelRatio());
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	// create Shader (Do not release until VAO is created)
	/*m_program = new QOpenGLShaderProgram(this);
	m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
	m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
	m_program->link();*/
}

void Scene::resizeGL(int w, int h)
{
	this->setFixedSize(w, h);
	const qreal retinaScale = devicePixelRatio();
	glViewport(0.0f, 0.0f, float(width()) * retinaScale, float(height()) * retinaScale);
}

void Scene::paintGL()
{
	// clear
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void Scene::animate()
{
	update();
}