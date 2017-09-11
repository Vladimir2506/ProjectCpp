#pragma once

#include <QDialog>
#include "ui_AddComment.h"

class AddComment : public QDialog
{
	Q_OBJECT

public:
	AddComment(int nIdMode, Customer *p, QWidget *parent = Q_NULLPTR);
	~AddComment();
protected:
	void paintEvent(QPaintEvent *event) override;
private slots:
	void SetStars(int nStars);
	void OnDelta();
	void OnCommit();
	void BackOne();
	void NextOne();
private:
	bool IsEmptyAll();
	bool IsFullAll();
	void PrepareComment();
private:
	Ui::AddComment ui;
	bool bDelta;
	array<QLabel*, 5> arrStars;
	QPixmap pixStarFul;
	QPixmap pixStarNil;
	map<string, string> *pComm;
	map<string, string>::iterator itThis;
	map<string, string>::iterator itEnd;
	Customer *pCustomer;
	int nMode;
};
