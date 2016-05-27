#include "editor.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication application(argc, argv);

	QSurfaceFormat format;
	format.setVersion(3, 3);
	format.setProfile(QSurfaceFormat::OpenGLContextProfile::CompatibilityProfile);
	format.setDepthBufferSize(24);
	format.setStencilBufferSize(8);
	format.setSamples(8);
	QSurfaceFormat::setDefaultFormat(format);

	Editor editor;
	editor.setAnimated(true);
	editor.showMaximized();

	return application.exec();
}
