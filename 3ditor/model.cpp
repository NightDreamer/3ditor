#include "model.h"
#include <QMessageBox>

Mesh::Mesh(QOpenGLShaderProgram* program, QString texturefilepath, GLuint numVertices, const void* data, int count)
{
	this->numVertices = numVertices;

	tex = new QOpenGLTexture(QImage(texturefilepath).mirrored());

	vao.create();
	vao.bind();

	vbo = QOpenGLBuffer(QOpenGLBuffer::Type::VertexBuffer);
	vbo.create();
	vbo.bind();
	vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	vbo.allocate(data, count);

	program->enableAttributeArray(0);
	program->setAttributeBuffer(0, GL_FLOAT, 0 * sizeof(float), 3, 5 * sizeof(float));
	program->enableAttributeArray(1);
	program->setAttributeBuffer(1, GL_FLOAT, 3 * sizeof(float), 2, 5 * sizeof(float));

	vbo.release();
	vao.release();
}

Mesh::~Mesh()
{
	tex->destroy();
	delete tex;

	vbo.destroy();
	vao.destroy();
}

void Mesh::draw()
{
	tex->bind();
	vao.bind();
	glDrawArrays(GL_TRIANGLES, 0, numVertices);
	vao.release();
	tex->release();
}

Model::Model(QOpenGLShaderProgram* program, QString directory, QString relativePath, QString filename)
{
	this->filepath = directory + relativePath + filename;
	qDebug("\nLoading model:");
	qDebug(filepath.toStdString().c_str());

	// Create an instance of the Importer class
	Assimp::Importer importer;

	// And have it read the given file with some postprocessing
	const aiScene* scene = importer.ReadFile(filepath.toStdString(), aiProcess_CalcTangentSpace | aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_SortByPType);

	// if the import failed, report it
	if (!scene)
	{
		QMessageBox msgBox;
		msgBox.setText("Failed to read file \'" + relativePath + filename + "\'!");
		msgBox.exec();
		return;
	}

	QVector3D highestVertex = QVector3D(0.0f, 0.0f, 0.0f);
	QVector3D lowestVertex = QVector3D(0.0f, 0.0f, 0.0f);

	// now we can access the file's contents.
	for (unsigned int m = 0; m < scene->mNumMeshes; m++)
	{
		const aiMesh* mesh = scene->mMeshes[m];
		const aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

		// gather texture
		aiString texturePath;
		if (material->GetTextureCount(aiTextureType_DIFFUSE) > 0 && material->GetTexture(aiTextureType_DIFFUSE, 0, &texturePath) != AI_SUCCESS)
		{
			QMessageBox msgBox;
			msgBox.setText("Model \'" + relativePath + filename + "\' has no available texture to load!");
			msgBox.exec();
			return;
		}

		// gather vertices
		if (!mesh->HasTextureCoords(0))
		{
			QMessageBox msgBox;
			msgBox.setText("Model \'" + relativePath + filename + "\' has no available texture coordinates!");
			msgBox.exec();
			return;
		}

		std::vector<Vertex> vertices = std::vector<Vertex>();
		for (unsigned int f = 0; f < mesh->mNumFaces; f++)
		{
			const aiFace& face = mesh->mFaces[f];

			for (unsigned int i = 0; i < face.mNumIndices; i++)
			{
				unsigned int index = face.mIndices[i];
				const aiVector3D& vertex = mesh->mVertices[index];
				const aiVector3D& texel = mesh->mTextureCoords[0][index];

				vertices.push_back(Vertex(vertex.x, vertex.y, vertex.z, texel.x, texel.y));

				if (vertex.y > highestVertex.y())
					highestVertex.setY(vertex.y);

				if (vertex.y < lowestVertex.y())
					lowestVertex.setY(vertex.y);
			}
		}

		normalize = 1.0f / float(highestVertex.y() - lowestVertex.y());

		// create Mesh
		QString texturefilepath = directory + relativePath + QString(texturePath.C_Str());
		qDebug("Texture file path:");
		qDebug(texturefilepath.toStdString().c_str());
		m_meshs.push_back(new Mesh(program, texturefilepath, vertices.size(), &vertices[0], sizeof(Vertex) * vertices.size()));
	}
	
	// We're done. Everything will be cleaned up by the importer destructor
}


Model::~Model()
{
	// Delete OpenGL stuff
	for (Mesh* m : m_meshs)
	{
		delete m;
	}
	m_meshs.clear();
}

void Model::draw()
{
	for (Mesh* m : m_meshs)
	{
		m->draw();
	}
}
