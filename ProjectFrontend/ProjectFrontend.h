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
	void CheckPhone(QString);		
	void CheckPW(QString);
protected:
	virtual void paintEvent(QPaintEvent *event) override;
	virtual void closeEvent(QCloseEvent *event) override;
private:
	Ui::ProjectFrontendClass ui;
	People *pPreload;				//Prepare a person to sign in
	bool bPhone;					//Is phone ok
	bool bPW;						//Is password ok
};
