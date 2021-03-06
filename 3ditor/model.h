#pragma once

#include <QString>
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
	Mesh(QString texturefilepath, GLuint numVertices, const void* data, int count);
	~Mesh();

	GLuint getNumVertices() { return numVertices; };
	QOpenGLBuffer& getVertexBufferObject() { return vbo; };
	QOpenGLTexture* getTexture() { return tex; };

private:
	GLuint numVertices;
	QOpenGLBuffer vbo;
	QOpenGLTexture* tex;
};

class Model
{
public:
	Model(QString directory, QString relativePath, QString filename);
	~Model();

	float getNormalisingValue() { return normalize; };
	std::vector<Mesh*>& getMeshs() { return m_meshs; };

public:
	QString filepath;

private:
	std::vector<Mesh*> m_meshs = std::vector<Mesh*>();
	float normalize = 0.0f;
};

