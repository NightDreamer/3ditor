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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "preview.h"
#include "scene.h"

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
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tabWidgetPage1;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEditModelDirectory;
    QPushButton *browseButton;
    QFrame *line;
    QCheckBox *checkBoxAutorotate;
    QLabel *labelModelDirectory;
    QLabel *label;
    Preview *openGLWidget;
    QFrame *line_2;
    QListWidget *listWidget;
    QWidget *tab;
    Scene *openGLWidget_2;
    QGroupBox *groupBox_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuExport;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EditorClass)
    {
        if (EditorClass->objectName().isEmpty())
            EditorClass->setObjectName(QStringLiteral("EditorClass"));
        EditorClass->resize(1515, 926);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EditorClass->sizePolicy().hasHeightForWidth());
        EditorClass->setSizePolicy(sizePolicy);
        EditorClass->setMinimumSize(QSize(1280, 720));
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
        centralWidget->setEnabled(true);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(221, 0));
        tabWidget->setMaximumSize(QSize(221, 16777215));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidgetPage1 = new QWidget();
        tabWidgetPage1->setObjectName(QStringLiteral("tabWidgetPage1"));
        gridLayout_2 = new QGridLayout(tabWidgetPage1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lineEditModelDirectory = new QLineEdit(tabWidgetPage1);
        lineEditModelDirectory->setObjectName(QStringLiteral("lineEditModelDirectory"));
        lineEditModelDirectory->setFocusPolicy(Qt::ClickFocus);

        gridLayout_2->addWidget(lineEditModelDirectory, 1, 0, 1, 2);

        browseButton = new QPushButton(tabWidgetPage1);
        browseButton->setObjectName(QStringLiteral("browseButton"));

        gridLayout_2->addWidget(browseButton, 1, 2, 1, 1);

        line = new QFrame(tabWidgetPage1);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 2, 0, 1, 3);

        checkBoxAutorotate = new QCheckBox(tabWidgetPage1);
        checkBoxAutorotate->setObjectName(QStringLiteral("checkBoxAutorotate"));
        checkBoxAutorotate->setLayoutDirection(Qt::LeftToRight);
        checkBoxAutorotate->setChecked(true);

        gridLayout_2->addWidget(checkBoxAutorotate, 5, 1, 1, 2);

        labelModelDirectory = new QLabel(tabWidgetPage1);
        labelModelDirectory->setObjectName(QStringLiteral("labelModelDirectory"));

        gridLayout_2->addWidget(labelModelDirectory, 0, 0, 1, 1);

        label = new QLabel(tabWidgetPage1);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 5, 0, 1, 1);

        openGLWidget = new Preview(tabWidgetPage1);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy2);
        openGLWidget->setMinimumSize(QSize(197, 197));
        openGLWidget->setMaximumSize(QSize(197, 197));

        gridLayout_2->addWidget(openGLWidget, 6, 0, 1, 3);

        line_2 = new QFrame(tabWidgetPage1);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 4, 0, 1, 3);

        listWidget = new QListWidget(tabWidgetPage1);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(listWidget, 3, 0, 1, 3);

        tabWidget->addTab(tabWidgetPage1, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tab->setEnabled(false);
        tabWidget->addTab(tab, QString());

        horizontalLayout->addWidget(tabWidget);

        openGLWidget_2 = new Scene(centralWidget);
        openGLWidget_2->setObjectName(QStringLiteral("openGLWidget_2"));
        sizePolicy.setHeightForWidth(openGLWidget_2->sizePolicy().hasHeightForWidth());
        openGLWidget_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(openGLWidget_2);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setMinimumSize(QSize(221, 0));
        groupBox_2->setMaximumSize(QSize(221, 16777215));

        horizontalLayout->addWidget(groupBox_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        EditorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EditorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1515, 21));
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

        tabWidget->setCurrentIndex(0);


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
        browseButton->setText(QApplication::translate("EditorClass", "Browse", 0));
        checkBoxAutorotate->setText(QApplication::translate("EditorClass", "Autorotate", 0));
        labelModelDirectory->setText(QApplication::translate("EditorClass", "Directory:", 0));
        label->setText(QApplication::translate("EditorClass", "Preview:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabWidgetPage1), QApplication::translate("EditorClass", "Model", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("EditorClass", "Creator", 0));
        groupBox_2->setTitle(QApplication::translate("EditorClass", "Scene", 0));
        menuFile->setTitle(QApplication::translate("EditorClass", "File", 0));
        menuExport->setTitle(QApplication::translate("EditorClass", "Export", 0));
    } // retranslateUi

};

namespace Ui {
    class EditorClass: public Ui_EditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_H
