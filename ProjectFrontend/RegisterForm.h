#pragma once

#include <QDialog>
#include "ui_RegisterForm.h"

class RegisterForm : public QDialog
{
	Q_OBJECT

public:
	RegisterForm(QWidget *parent = Q_NULLPTR);
	~RegisterForm();
private slots :
	void CheckPhone(QString qstrPhone);
	void CheckPW(QString qstrPW);
	void CheckDeux(QString qstrDeux);
	void BindSelect(int nSel);
	void SubmitReg();
protected:
	virtual void paintEvent(QPaintEvent *event) override;
private:
	Ui::RegisterForm ui;
	//Icons
	QPixmap pixRight;
	QPixmap pixWrong;
	QPixmap pixNil;
	//Check validity
	bool bPhone;
	bool bPW;
	bool bDeux;
	bool bUnique;
	//cbChar selection
	QStringList lstCharaters;
	int nSelect;
};
