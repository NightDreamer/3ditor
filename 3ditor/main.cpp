#include "editor.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
	QApplication application(argc, argv);

	QSurfaceFormat format;
	format.setVersion(3, 3);
	format.setProfile(QSurfaceFormat::OpenGLContextProfile::CoreProfile);
	format.setDepthBufferSize(24);
	format.setStencilBufferSize(8);
	format.setSamples(8);
	QSurfaceFormat::setDefaultFormat(format);

	Editor editor;
	editor.setAnimated(true);
	editor.showMaximized();

	return application.exec();
}
