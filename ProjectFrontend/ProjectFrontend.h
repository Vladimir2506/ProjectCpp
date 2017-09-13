#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ProjectFrontend.h"

#include "RegisterForm.h"
#include "MaintainerView.h"
#include "CustomerView.h"
#include "CookView.h"
#include "WaitorView.h"
#include "ManagerView.h"

class ProjectFrontend : public QMainWindow
{
	Q_OBJECT

public:
	ProjectFrontend(QWidget *parent = Q_NULLPTR);
	~ProjectFrontend();
private slots:
	void OnRegClicked();
	void OnLogClicked();
private:
	bool CheckPhone();
	bool CheckPW();
protected:
	void paintEvent(QPaintEvent *event) override;
	void closeEvent(QCloseEvent *event) override;
private:
	Ui::ProjectFrontendClass ui;
	People *pPreload;				//Load the person info in advance
};
