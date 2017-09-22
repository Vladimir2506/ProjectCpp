#include "stdafx.h"
#include "ProjectFrontend.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	//Application Init
	QApplication theApp(argc, argv);		
	
	//Load Stylesheets
	QFile myStylesheets("MyUI.css");
	myStylesheets.open(QFile::ReadOnly);
	QString theStyle = myStylesheets.readAll();
	theApp.setStyleSheet(theStyle);
	myStylesheets.close();

	//To ensure that there is only one instance is running
	static QSharedMemory shmApp("Cafeteria");
	if (!shmApp.create(1))
	{
		QMessageBox::information(nullptr, "提示", "程序已运行！");
		return -1;
	}

	//Show MainWindow
	ProjectFrontend theMainWindow;
	theMainWindow.show();
	return theApp.exec();
}
