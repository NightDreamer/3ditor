/********************************************************************************
** Form generated from reading UI file 'editor.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITOR_H
#define UI_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "preview.h"

QT_BEGIN_NAMESPACE

class Ui_EditorClass
{
public:
    QAction *actionNew;
    QAction *actionQuit;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionJSON;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLineEdit *lineEditModelDirectory;
    QLabel *labelModelDirectory;
    QPushButton *browseButton;
    QFrame *line;
    QListWidget *listWidget;
    QFrame *line_2;
    QLabel *label;
    Preview *openGLWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuExport;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EditorClass)
    {
        if (EditorClass->objectName().isEmpty())
            EditorClass->setObjectName(QStringLiteral("EditorClass"));
        EditorClass->resize(1517, 915);
        EditorClass->setTabShape(QTabWidget::Triangular);
        actionNew = new QAction(EditorClass);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionQuit = new QAction(EditorClass);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionQuit->setPriority(QAction::NormalPriority);
        actionOpen = new QAction(EditorClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(EditorClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_as = new QAction(EditorClass);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionJSON = new QAction(EditorClass);
        actionJSON->setObjectName(QStringLiteral("actionJSON"));
        centralWidget = new QWidget(EditorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(9, 0, 221, 871));
        lineEditModelDirectory = new QLineEdit(groupBox);
        lineEditModelDirectory->setObjectName(QStringLiteral("lineEditModelDirectory"));
        lineEditModelDirectory->setGeometry(QRect(10, 40, 151, 21));
        lineEditModelDirectory->setFocusPolicy(Qt::ClickFocus);
        labelModelDirectory = new QLabel(groupBox);
        labelModelDirectory->setObjectName(QStringLiteral("labelModelDirectory"));
        labelModelDirectory->setGeometry(QRect(6, 16, 61, 20));
        browseButton = new QPushButton(groupBox);
        browseButton->setObjectName(QStringLiteral("browseButton"));
        browseButton->setGeometry(QRect(164, 42, 51, 21));
        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(-3, 69, 231, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        listWidget = new QListWidget(groupBox);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 90, 201, 521));
        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(-3, 620, 231, 21));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(6, 640, 61, 20));
        openGLWidget = new Preview(groupBox);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(10, 660, 201, 201));
        EditorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EditorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1517, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuExport = new QMenu(menuBar);
        menuExport->setObjectName(QStringLiteral("menuExport"));
        EditorClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(EditorClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        EditorClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuExport->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuExport->addAction(actionJSON);

        retranslateUi(EditorClass);

        QMetaObject::connectSlotsByName(EditorClass);
    } // setupUi

    void retranslateUi(QMainWindow *EditorClass)
    {
        EditorClass->setWindowTitle(QApplication::translate("EditorClass", "3ditor", 0));
        actionNew->setText(QApplication::translate("EditorClass", "New", 0));
        actionQuit->setText(QApplication::translate("EditorClass", "Quit", 0));
        actionOpen->setText(QApplication::translate("EditorClass", "Open", 0));
        actionSave->setText(QApplication::translate("EditorClass", "Save", 0));
        actionSave_as->setText(QApplication::translate("EditorClass", "Save as...", 0));
        actionJSON->setText(QApplication::translate("EditorClass", "JSON", 0));
        groupBox->setTitle(QApplication::translate("EditorClass", "Models", 0));
        labelModelDirectory->setText(QApplication::translate("EditorClass", "Directory:", 0));
        browseButton->setText(QApplication::translate("EditorClass", "Browse", 0));
        label->setText(QApplication::translate("EditorClass", "Preview:", 0));
        menuFile->setTitle(QApplication::translate("EditorClass", "File", 0));
        menuExport->setTitle(QApplication::translate("EditorClass", "Export", 0));
    } // retranslateUi

};

namespace Ui {
    class EditorClass: public Ui_EditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_H
