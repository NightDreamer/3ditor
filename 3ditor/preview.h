#pragma once

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QMatrix4x4>
#include "model.h"

class Preview : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
	Preview(QWidget* parent = 0);
	~Preview();

	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();

	void bindShader() { m_program->bind(); };
	void releaseShader() { m_program->release(); };

public slots:
	void animate();

public:
	Model* previewModel = nullptr;
	QOpenGLShaderProgram* m_program;

private:
	float rotate = 0.0f;
	int elapsed = 0;
};

