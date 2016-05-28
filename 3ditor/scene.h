#pragma once

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include "model.h"

class Scene : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
	Scene(QWidget* parent = 0);
	~Scene();

	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();

public slots:
	void animate();

private:
	QOpenGLShaderProgram* m_program;
};

