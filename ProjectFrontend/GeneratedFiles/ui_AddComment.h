/********************************************************************************
** Form generated from reading UI file 'AddComment.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCOMMENT_H
#define UI_ADDCOMMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AddComment
{
public:
    QGroupBox *gbStars;
    QLabel *lbls3;
    QLabel *lbls5;
    QLabel *lbls4;
    QLabel *lbls2;
    QLabel *lbls1;
    QSpinBox *sbStars;
    QGroupBox *gbContent;
    QTextEdit *teContent;
    QPushButton *btnBack;
    QPushButton *btnNext;
    QPushButton *btnCommit;
    QGroupBox *gbTitle;
    QLineEdit *leTitle;
    QLabel *lblName;

    void setupUi(QDialog *AddComment)
    {
        if (AddComment->objectName().isEmpty())
            AddComment->setObjectName(QStringLiteral("AddComment"));
        AddComment->resize(500, 600);
        AddComment->setMinimumSize(QSize(500, 600));
        AddComment->setMaximumSize(QSize(500, 600));
        gbStars = new QGroupBox(AddComment);
        gbStars->setObjectName(QStringLiteral("gbStars"));
        gbStars->setGeometry(QRect(50, 125, 400, 75));
        lbls3 = new QLabel(gbStars);
        lbls3->setObjectName(QStringLiteral("lbls3"));
        lbls3->setGeometry(QRect(230, 25, 30, 30));
        lbls5 = new QLabel(gbStars);
        lbls5->setObjectName(QStringLiteral("lbls5"));
        lbls5->setGeometry(QRect(310, 25, 31, 30));
        lbls4 = new QLabel(gbStars);
        lbls4->setObjectName(QStringLiteral("lbls4"));
        lbls4->setGeometry(QRect(270, 25, 30, 30));
        lbls2 = new QLabel(gbStars);
        lbls2->setObjectName(QStringLiteral("lbls2"));
        lbls2->setGeometry(QRect(190, 25, 30, 30));
        lbls1 = new QLabel(gbStars);
        lbls1->setObjectName(QStringLiteral("lbls1"));
        lbls1->setGeometry(QRect(150, 25, 30, 30));
        sbStars = new QSpinBox(gbStars);
        sbStars->setObjectName(QStringLiteral("sbStars"));
        sbStars->setGeometry(QRect(50, 30, 60, 25));
        sbStars->setMaximum(5);
        sbStars->setValue(0);
        gbContent = new QGroupBox(AddComment);
        gbContent->setObjectName(QStringLiteral("gbContent"));
        gbContent->setGeometry(QRect(50, 225, 400, 350));
        teContent = new QTextEdit(gbContent);
        teContent->setObjectName(QStringLiteral("teContent"));
        teContent->setGeometry(QRect(25, 25, 350, 300));
        teContent->setReadOnly(false);
        btnBack = new QPushButton(AddComment);
        btnBack->setObjectName(QStringLiteral("btnBack"));
        btnBack->setGeometry(QRect(50, 60, 40, 40));
        QIcon icon;
        icon.addFile(QStringLiteral("back.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnBack->setIcon(icon);
        btnBack->setIconSize(QSize(25, 25));
        btnNext = new QPushButton(AddComment);
        btnNext->setObjectName(QStringLiteral("btnNext"));
        btnNext->setGeometry(QRect(150, 60, 40, 40));
        QIcon icon1;
        icon1.addFile(QStringLiteral("next.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNext->setIcon(icon1);
        btnNext->setIconSize(QSize(25, 25));
        btnCommit = new QPushButton(AddComment);
        btnCommit->setObjectName(QStringLiteral("btnCommit"));
        btnCommit->setGeometry(QRect(100, 60, 40, 40));
        QIcon icon2;
        icon2.addFile(QStringLiteral("submit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCommit->setIcon(icon2);
        btnCommit->setIconSize(QSize(25, 25));
        gbTitle = new QGroupBox(AddComment);
        gbTitle->setObjectName(QStringLiteral("gbTitle"));
        gbTitle->setGeometry(QRect(225, 25, 225, 90));
        leTitle = new QLineEdit(gbTitle);
        leTitle->setObjectName(QStringLiteral("leTitle"));
        leTitle->setGeometry(QRect(25, 40, 175, 25));
        lblName = new QLabel(AddComment);
        lblName->setObjectName(QStringLiteral("lblName"));
        lblName->setGeometry(QRect(50, 25, 150, 25));
        lblName->setAlignment(Qt::AlignCenter);

        retranslateUi(AddComment);
        QObject::connect(sbStars, SIGNAL(valueChanged(int)), AddComment, SLOT(SetStars(int)));
        QObject::connect(leTitle, SIGNAL(textChanged(QString)), AddComment, SLOT(OnDelta()));
        QObject::connect(teContent, SIGNAL(textChanged()), AddComment, SLOT(OnDelta()));
        QObject::connect(sbStars, SIGNAL(valueChanged(int)), AddComment, SLOT(OnDelta()));
        QObject::connect(btnBack, SIGNAL(clicked()), AddComment, SLOT(BackOne()));
        QObject::connect(btnNext, SIGNAL(clicked()), AddComment, SLOT(NextOne()));
        QObject::connect(btnCommit, SIGNAL(clicked()), AddComment, SLOT(OnCommit()));

        QMetaObject::connectSlotsByName(AddComment);
    } // setupUi

    void retranslateUi(QDialog *AddComment)
    {
        AddComment->setWindowTitle(QApplication::translate("AddComment", "\350\257\204\350\256\272\350\217\234\345\223\201", Q_NULLPTR));
        gbStars->setTitle(QApplication::translate("AddComment", "\350\257\204\344\273\267\346\230\237\347\272\247", Q_NULLPTR));
        lbls3->setText(QString());
        lbls5->setText(QString());
        lbls4->setText(QString());
        lbls2->setText(QString());
        lbls1->setText(QString());
        gbContent->setTitle(QApplication::translate("AddComment", "\350\257\204\344\273\267\345\206\205\345\256\271", Q_NULLPTR));
        btnBack->setText(QString());
        btnNext->setText(QString());
        btnCommit->setText(QString());
        gbTitle->setTitle(QApplication::translate("AddComment", "\350\257\204\350\256\272\346\240\207\351\242\230", Q_NULLPTR));
        lblName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddComment: public Ui_AddComment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOMMENT_H
