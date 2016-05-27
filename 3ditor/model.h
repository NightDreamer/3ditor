#pragma once

#include <QString>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLTexture>
#include <QOpenGLShaderProgram>
#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

struct Vertex {
	Vertex(float x, float y, float z, float u, float v) : position(x, y, z), texel(u, v) {};

	QVector3D position;
	QVector2D texel;
};

class Mesh
{
public:
	Mesh(QOpenGLShaderProgram* program, QString texturefilepath, GLuint numVertices, const void* data, int count);
	~Mesh();

	void draw();

private:
	GLuint numVertices;
	QOpenGLVertexArrayObject vao;
	QOpenGLBuffer vbo;
	QOpenGLTexture* tex;
};

class Model
{
public:
	Model(QOpenGLShaderProgram* program, QString directory, QString relativePath, QString filename);
	~Model();

	void draw();

	float getNormalisingValue() { return normalize; };

public:
	QString filepath;

private:
	std::vector<Mesh*> m_meshs = std::vector<Mesh*>();
	float normalize = 0.0f;
};

