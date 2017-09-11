/********************************************************************************
** Form generated from reading UI file 'BrowseComment.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BROWSECOMMENT_H
#define UI_BROWSECOMMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_BrowseComment
{
public:
    QPushButton *btnBack;
    QPushButton *btnNext;
    QGroupBox *groupBox;
    QLabel *lbls3;
    QLabel *lbls5;
    QLabel *lbls4;
    QLabel *lbls2;
    QLabel *lbls1;
    QGroupBox *gbContent;
    QTextEdit *teContent;
    QLabel *lblDate;
    QLabel *lblTitle;

    void setupUi(QDialog *BrowseComment)
    {
        if (BrowseComment->objectName().isEmpty())
            BrowseComment->setObjectName(QStringLiteral("BrowseComment"));
        BrowseComment->resize(500, 600);
        BrowseComment->setMinimumSize(QSize(500, 600));
        BrowseComment->setMaximumSize(QSize(500, 600));
        btnBack = new QPushButton(BrowseComment);
        btnBack->setObjectName(QStringLiteral("btnBack"));
        btnBack->setGeometry(QRect(50, 35, 40, 40));
        QIcon icon;
        icon.addFile(QStringLiteral("back.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnBack->setIcon(icon);
        btnBack->setIconSize(QSize(25, 25));
        btnNext = new QPushButton(BrowseComment);
        btnNext->setObjectName(QStringLiteral("btnNext"));
        btnNext->setGeometry(QRect(125, 35, 40, 40));
        QIcon icon1;
        icon1.addFile(QStringLiteral("next.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNext->setIcon(icon1);
        btnNext->setIconSize(QSize(25, 25));
        groupBox = new QGroupBox(BrowseComment);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(50, 125, 400, 80));
        lbls3 = new QLabel(groupBox);
        lbls3->setObjectName(QStringLiteral("lbls3"));
        lbls3->setGeometry(QRect(180, 30, 30, 30));
        lbls5 = new QLabel(groupBox);
        lbls5->setObjectName(QStringLiteral("lbls5"));
        lbls5->setGeometry(QRect(260, 30, 30, 30));
        lbls4 = new QLabel(groupBox);
        lbls4->setObjectName(QStringLiteral("lbls4"));
        lbls4->setGeometry(QRect(220, 30, 30, 30));
        lbls2 = new QLabel(groupBox);
        lbls2->setObjectName(QStringLiteral("lbls2"));
        lbls2->setGeometry(QRect(140, 30, 30, 30));
        lbls1 = new QLabel(groupBox);
        lbls1->setObjectName(QStringLiteral("lbls1"));
        lbls1->setGeometry(QRect(100, 30, 30, 30));
        gbContent = new QGroupBox(BrowseComment);
        gbContent->setObjectName(QStringLiteral("gbContent"));
        gbContent->setGeometry(QRect(50, 225, 400, 350));
        teContent = new QTextEdit(gbContent);
        teContent->setObjectName(QStringLiteral("teContent"));
        teContent->setGeometry(QRect(25, 25, 350, 300));
        teContent->setReadOnly(true);
        lblDate = new QLabel(BrowseComment);
        lblDate->setObjectName(QStringLiteral("lblDate"));
        lblDate->setGeometry(QRect(225, 75, 200, 25));
        lblDate->setAlignment(Qt::AlignCenter);
        lblTitle = new QLabel(BrowseComment);
        lblTitle->setObjectName(QStringLiteral("lblTitle"));
        lblTitle->setGeometry(QRect(225, 25, 200, 25));
        lblTitle->setAlignment(Qt::AlignCenter);
        gbContent->raise();
        btnBack->raise();
        btnNext->raise();
        groupBox->raise();
        lblDate->raise();
        lblTitle->raise();

        retranslateUi(BrowseComment);
        QObject::connect(btnBack, SIGNAL(clicked()), BrowseComment, SLOT(BackOne()));
        QObject::connect(btnNext, SIGNAL(clicked()), BrowseComment, SLOT(NextOne()));

        QMetaObject::connectSlotsByName(BrowseComment);
    } // setupUi

    void retranslateUi(QDialog *BrowseComment)
    {
        BrowseComment->setWindowTitle(QApplication::translate("BrowseComment", "\346\237\245\347\234\213\350\257\204\350\256\272", Q_NULLPTR));
        btnBack->setText(QString());
        btnNext->setText(QString());
        groupBox->setTitle(QApplication::translate("BrowseComment", "\350\257\204\344\273\267\346\230\237\347\272\247", Q_NULLPTR));
        lbls3->setText(QString());
        lbls5->setText(QString());
        lbls4->setText(QString());
        lbls2->setText(QString());
        lbls1->setText(QString());
        gbContent->setTitle(QApplication::translate("BrowseComment", "\350\257\204\344\273\267\345\206\205\345\256\271", Q_NULLPTR));
        lblDate->setText(QString());
        lblTitle->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BrowseComment: public Ui_BrowseComment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BROWSECOMMENT_H
