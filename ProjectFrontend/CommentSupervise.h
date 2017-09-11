#pragma once

#include <QDialog>
#include "ui_CommentSupervise.h"

class CommentSupervise : public QDialog
{
	Q_OBJECT

public:
	CommentSupervise(QWidget *parent = Q_NULLPTR);
	~CommentSupervise();
protected:
	virtual void paintEvent(QPaintEvent *event) override;
private slots:
	void SetStars(int nStar);
	void OnDelClick();
	void OnSaveClick();
	void OnUndoClick();
	void OnAddClick();
	void BackOne();
	void NextOne();
	void OnDelta();
private:
	void PrepareComment();
	void EmptyNow();
	bool IsNowEmpty();
	bool IsNowFull();
private:
	Ui::CommentSupervise ui;
	//Stars
	QPixmap pixStarFul;
	QPixmap pixStarNil;
	array<QLabel*, 5> lblStars;
	//Comment Status
	map<string, Comment>::iterator itThis;
	bool bDelta;
};
