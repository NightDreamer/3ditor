#pragma once

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QWheelEvent>
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
	void wheelEvent(QWheelEvent* event);

	void setModel(Model* model);
	void setAutoRotation(bool autoRotation);

	void bindShader() { m_program->bind(); };
	void releaseShader() { m_program->release(); };

public slots:
	void animate() { update(); };

public:
	QOpenGLShaderProgram* m_program;

private:
	Model* previewModel = nullptr;

	QMatrix4x4 m_projection;
	QMatrix4x4 m_model;
	QMatrix4x4 m_view;
	float fov = 60.0f;
	bool autoRotation = true;
};

