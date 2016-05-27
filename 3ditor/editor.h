#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>
#include <vector>
#include "ui_editor.h"
#include "model.h"

class Editor : public QMainWindow
{
	Q_OBJECT

public:
	Editor(QWidget *parent = 0);
	~Editor();

private slots:
	void on_actionNew_triggered();
	void on_actionOpen_triggered();
	void on_actionSave_triggered();
	void on_actionSave_as_triggered();
	void on_actionQuit_triggered();

	void on_browseButton_clicked();
	void on_listWidget_currentTextChanged(const QString& currentText);

private:
	Ui::EditorClass ui;
	std::vector<Model*> models;
};

#endif // EDITOR_H
