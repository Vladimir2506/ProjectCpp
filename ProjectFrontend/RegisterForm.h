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
	void OnDelta();
	void BindSelect(int nSel);
	void SubmitReg();
protected:
	virtual void paintEvent(QPaintEvent *event) override;
private:
	bool CheckPW();
	bool CheckPhone();
	bool CheckDeux();
	bool CheckName();
private:
	Ui::RegisterForm ui;
	//Icons
	QPixmap pixRight;
	QPixmap pixWrong;
	QPixmap pixNil;
	//cbChar selection
	QStringList lstCharaters;
	int nSelect;
	//Edit flags
	bool bDelta;
};
