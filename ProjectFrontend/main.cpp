#include "stdafx.h"
#include "ProjectFrontend.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	static QSharedMemory shmApp("Cafeteria");
	if (!shmApp.create(64))
	{
		QMessageBox::information(nullptr, "��ʾ", "���������У�");
		return -1;
	}
	ProjectFrontend w;
	w.show();
	return a.exec();
}
