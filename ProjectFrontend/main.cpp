#include "stdafx.h"
#include "ProjectFrontend.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication theApp(argc, argv);		//Application Init
	//To ensure that there is only one instance is running
	static QSharedMemory shmApp("Cafeteria");
	if (!shmApp.create(64))
	{
		QMessageBox::information(nullptr, "提示", "程序已运行！");
		return -1;
	}
	//Load Stylesheets
	QFile myStylesheets("MyUIOptimisation.css");
	myStylesheets.open(QFile::ReadOnly);
	QString theStyle = myStylesheets.readAll();
	theApp.setStyleSheet(theStyle);
	myStylesheets.close();
	//Show MainWindow
	ProjectFrontend theMainWindow;
	theMainWindow.show();
	return theApp.exec();
}
