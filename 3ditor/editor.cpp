#include "editor.h"

#include <QFileDialog>
#include <QDirIterator>
#include <QListWidget>
#include <QProgressDialog>
#include <QTimer>

Editor::Editor(QWidget *parent)	: QMainWindow(parent)
{
	ui.setupUi(this);	
}

Editor::~Editor()
{
	while (models.size() > 0)
	{
		delete models.back();
		models.pop_back();
	}
}

void Editor::on_actionNew_triggered()
{

}

void Editor::on_actionOpen_triggered()
{
	QString file = QFileDialog::getOpenFileName(this, QString("Open File"), QDir::currentPath());

}

void Editor::on_actionSave_triggered()
{
	
}

void Editor::on_actionSave_as_triggered()
{
	QString file = QFileDialog::getSaveFileName(this, QString("Save File As"), QDir::currentPath());
}

void Editor::on_actionQuit_triggered()
{
	qApp->quit();
}

void Editor::on_browseButton_clicked()
{
	// FOR DEBUG PURPOSES ONLY:
	// check if the QOpenGLWidgets have shared contexts
	qDebug() << "Shared context between both QOpenGLWidgets: " << QOpenGLContext::areSharing(ui.openGLWidget->context(), ui.openGLWidget_2->context());

	// let the user choose the directory
	QString baseDirectory = QFileDialog::getExistingDirectory(this, QString("Choose Folder"), QDir::currentPath());

	// check if the user didn't hit cancel
	if (!baseDirectory.isNull() && ui.lineEditModelDirectory->text().compare(baseDirectory) != 0)
	{
		// delete old models
		ui.openGLWidget->setModel(nullptr);

		while (models.size() > 0)
		{
			delete models.back();
			models.pop_back();
		}

		// clear list of previously loaded models
		ui.listWidget->clear();
		
		// store new directory path in the line edit field
		ui.lineEditModelDirectory->setText(baseDirectory);

		//	use preview context for model loading
		ui.openGLWidget->makeCurrent();

		// find and retrieve all models found within the previous selected directory
		QDirIterator it(baseDirectory, QDir::Files, QDirIterator::Subdirectories);
		while (it.hasNext()) {
			QString absolutefilePath = it.next();
			QString relativeFilePath = absolutefilePath.replace(0, baseDirectory.length(), "");
			QString filename = it.fileName();
			relativeFilePath.chop(filename.length());

			if (filename.endsWith(".fbx") || filename.endsWith(".obj"))
			{
				qDebug(absolutefilePath.toStdString().c_str());
				qDebug(relativeFilePath.toStdString().c_str());
				qDebug(filename.toStdString().c_str());

				Model* model = new Model(baseDirectory, relativeFilePath, filename);
				models.push_back(model);

				ui.listWidget->addItem(filename);
			}
		}

		// done loading models, so context can be unbound
		ui.openGLWidget->doneCurrent();
	}	
}

void Editor::on_checkBoxAutorotate_stateChanged(int state)
{
	ui.openGLWidget->setAutoRotation(state);
}

void Editor::on_listWidget_currentTextChanged(const QString& currentText)
{
	for (Model* m : models)
	{
		if (m->filepath.endsWith(currentText, Qt::CaseInsensitive))
		{
			ui.openGLWidget->setModel(m);
			break;
		}
	}
}
