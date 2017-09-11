#pragma once

#include <QDialog>
#include "ui_BrowseComment.h"

class BrowseComment : public QDialog
{
	Q_OBJECT

public:
	BrowseComment(const string &strCuisineId, QWidget *parent = Q_NULLPTR);
	~BrowseComment();
protected:
	void paintEvent(QPaintEvent *event) override;
private slots:
	void BackOne();
	void NextOne();
private:
	void PrepareComment();
	void SetStars(int nStars);
private:
	Ui::BrowseComment ui;
	vector<Comment> vecComments;
	vector<Comment>::iterator itThis;
	QPixmap pixStarFul;
	QPixmap pixStarNil;
	QPixmap PixEmpty;
	array<QLabel*, 5> arrStars;
};
