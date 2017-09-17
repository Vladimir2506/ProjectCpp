/********************************************************************************
** Form generated from reading UI file 'CommentSupervise.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMENTSUPERVISE_H
#define UI_COMMENTSUPERVISE_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_CommentSupervise
{
public:
    QPushButton *btnBack;
    QPushButton *btnNext;
    QGroupBox *gbComment;
    QTextEdit *teContent;
    QSpinBox *sbStar;
    QLabel *lblStar;
    QLabel *lbls1;
    QLabel *lbls2;
    QLabel *lbls3;
    QLabel *lbls5;
    QLabel *lbls4;
    QLabel *lblContent;
    QGroupBox *gbProperty;
    QDateEdit *deDate;
    QLineEdit *leDestId;
    QLineEdit *leSrcId;
    QLineEdit *leComId;
    QLabel *lblComId;
    QLabel *lblSrcId;
    QLabel *lblDestId;
    QLabel *lblDate;
    QLabel *lblTitle;
    QLineEdit *leTitle;
    QPushButton *btnSave;
    QPushButton *btnUndo;
    QPushButton *btnDel;
    QPushButton *btnAdd;
    QLabel *lblCommSVBGN;

    void setupUi(QDialog *CommentSupervise)
    {
        if (CommentSupervise->objectName().isEmpty())
            CommentSupervise->setObjectName(QStringLiteral("CommentSupervise"));
        CommentSupervise->resize(900, 650);
        CommentSupervise->setMinimumSize(QSize(900, 650));
        CommentSupervise->setMaximumSize(QSize(900, 650));
        btnBack = new QPushButton(CommentSupervise);
        btnBack->setObjectName(QStringLiteral("btnBack"));
        btnBack->setGeometry(QRect(25, 175, 40, 40));
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnBack->setIcon(icon);
        btnBack->setIconSize(QSize(25, 25));
        btnNext = new QPushButton(CommentSupervise);
        btnNext->setObjectName(QStringLiteral("btnNext"));
        btnNext->setGeometry(QRect(395, 175, 40, 40));
        QIcon icon1;
        icon1.addFile(QStringLiteral("Resources/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNext->setIcon(icon1);
        btnNext->setIconSize(QSize(25, 25));
        gbComment = new QGroupBox(CommentSupervise);
        gbComment->setObjectName(QStringLiteral("gbComment"));
        gbComment->setGeometry(QRect(450, 175, 425, 450));
        teContent = new QTextEdit(gbComment);
        teContent->setObjectName(QStringLiteral("teContent"));
        teContent->setGeometry(QRect(50, 200, 325, 225));
        sbStar = new QSpinBox(gbComment);
        sbStar->setObjectName(QStringLiteral("sbStar"));
        sbStar->setGeometry(QRect(150, 50, 50, 25));
        sbStar->setWrapping(false);
        sbStar->setMaximum(5);
        sbStar->setValue(0);
        lblStar = new QLabel(gbComment);
        lblStar->setObjectName(QStringLiteral("lblStar"));
        lblStar->setGeometry(QRect(50, 50, 75, 25));
        lbls1 = new QLabel(gbComment);
        lbls1->setObjectName(QStringLiteral("lbls1"));
        lbls1->setGeometry(QRect(100, 100, 30, 30));
        lbls2 = new QLabel(gbComment);
        lbls2->setObjectName(QStringLiteral("lbls2"));
        lbls2->setGeometry(QRect(140, 100, 30, 30));
        lbls3 = new QLabel(gbComment);
        lbls3->setObjectName(QStringLiteral("lbls3"));
        lbls3->setGeometry(QRect(180, 100, 30, 30));
        lbls5 = new QLabel(gbComment);
        lbls5->setObjectName(QStringLiteral("lbls5"));
        lbls5->setGeometry(QRect(260, 100, 30, 30));
        lbls4 = new QLabel(gbComment);
        lbls4->setObjectName(QStringLiteral("lbls4"));
        lbls4->setGeometry(QRect(220, 100, 30, 30));
        lblContent = new QLabel(gbComment);
        lblContent->setObjectName(QStringLiteral("lblContent"));
        lblContent->setGeometry(QRect(50, 150, 125, 25));
        gbProperty = new QGroupBox(CommentSupervise);
        gbProperty->setObjectName(QStringLiteral("gbProperty"));
        gbProperty->setGeometry(QRect(25, 225, 410, 400));
        deDate = new QDateEdit(gbProperty);
        deDate->setObjectName(QStringLiteral("deDate"));
        deDate->setGeometry(QRect(200, 275, 150, 25));
        deDate->setAlignment(Qt::AlignCenter);
        deDate->setTimeSpec(Qt::TimeZone);
        deDate->setDate(QDate(2017, 9, 1));
        leDestId = new QLineEdit(gbProperty);
        leDestId->setObjectName(QStringLiteral("leDestId"));
        leDestId->setGeometry(QRect(200, 200, 150, 25));
        leSrcId = new QLineEdit(gbProperty);
        leSrcId->setObjectName(QStringLiteral("leSrcId"));
        leSrcId->setGeometry(QRect(200, 125, 150, 25));
        leComId = new QLineEdit(gbProperty);
        leComId->setObjectName(QStringLiteral("leComId"));
        leComId->setGeometry(QRect(200, 50, 150, 25));
        lblComId = new QLabel(gbProperty);
        lblComId->setObjectName(QStringLiteral("lblComId"));
        lblComId->setGeometry(QRect(50, 50, 125, 25));
        lblSrcId = new QLabel(gbProperty);
        lblSrcId->setObjectName(QStringLiteral("lblSrcId"));
        lblSrcId->setGeometry(QRect(50, 125, 125, 25));
        lblDestId = new QLabel(gbProperty);
        lblDestId->setObjectName(QStringLiteral("lblDestId"));
        lblDestId->setGeometry(QRect(50, 200, 125, 25));
        lblDate = new QLabel(gbProperty);
        lblDate->setObjectName(QStringLiteral("lblDate"));
        lblDate->setGeometry(QRect(50, 275, 125, 25));
        lblTitle = new QLabel(gbProperty);
        lblTitle->setObjectName(QStringLiteral("lblTitle"));
        lblTitle->setGeometry(QRect(50, 350, 125, 25));
        leTitle = new QLineEdit(gbProperty);
        leTitle->setObjectName(QStringLiteral("leTitle"));
        leTitle->setGeometry(QRect(200, 350, 150, 25));
        btnSave = new QPushButton(CommentSupervise);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        btnSave->setGeometry(QRect(125, 175, 100, 40));
        btnUndo = new QPushButton(CommentSupervise);
        btnUndo->setObjectName(QStringLiteral("btnUndo"));
        btnUndo->setGeometry(QRect(235, 175, 100, 40));
        btnDel = new QPushButton(CommentSupervise);
        btnDel->setObjectName(QStringLiteral("btnDel"));
        btnDel->setGeometry(QRect(345, 175, 40, 40));
        QIcon icon2;
        icon2.addFile(QStringLiteral("Resources/subtract.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDel->setIcon(icon2);
        btnDel->setIconSize(QSize(25, 25));
        btnAdd = new QPushButton(CommentSupervise);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));
        btnAdd->setGeometry(QRect(75, 175, 40, 40));
        QIcon icon3;
        icon3.addFile(QStringLiteral("Resources/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAdd->setIcon(icon3);
        btnAdd->setIconSize(QSize(25, 25));
        lblCommSVBGN = new QLabel(CommentSupervise);
        lblCommSVBGN->setObjectName(QStringLiteral("lblCommSVBGN"));
        lblCommSVBGN->setGeometry(QRect(0, 0, 900, 650));
        lblCommSVBGN->raise();
        btnBack->raise();
        btnNext->raise();
        gbComment->raise();
        gbProperty->raise();
        btnSave->raise();
        btnUndo->raise();
        btnDel->raise();
        btnAdd->raise();

        retranslateUi(CommentSupervise);
        QObject::connect(sbStar, SIGNAL(valueChanged(int)), CommentSupervise, SLOT(SetStars(int)));
        QObject::connect(btnDel, SIGNAL(clicked()), CommentSupervise, SLOT(OnDelClick()));
        QObject::connect(btnSave, SIGNAL(clicked()), CommentSupervise, SLOT(OnSaveClick()));
        QObject::connect(btnUndo, SIGNAL(clicked()), CommentSupervise, SLOT(OnUndoClick()));
        QObject::connect(btnAdd, SIGNAL(clicked()), CommentSupervise, SLOT(OnAddClick()));
        QObject::connect(btnBack, SIGNAL(clicked()), CommentSupervise, SLOT(BackOne()));
        QObject::connect(btnNext, SIGNAL(clicked()), CommentSupervise, SLOT(NextOne()));
        QObject::connect(leComId, SIGNAL(textEdited(QString)), CommentSupervise, SLOT(OnDelta()));
        QObject::connect(leSrcId, SIGNAL(textEdited(QString)), CommentSupervise, SLOT(OnDelta()));
        QObject::connect(leDestId, SIGNAL(textEdited(QString)), CommentSupervise, SLOT(OnDelta()));
        QObject::connect(leTitle, SIGNAL(textEdited(QString)), CommentSupervise, SLOT(OnDelta()));
        QObject::connect(deDate, SIGNAL(userDateChanged(QDate)), CommentSupervise, SLOT(OnDelta()));
        QObject::connect(sbStar, SIGNAL(valueChanged(int)), CommentSupervise, SLOT(OnDelta()));
        QObject::connect(teContent, SIGNAL(textChanged()), CommentSupervise, SLOT(OnDelta()));

        QMetaObject::connectSlotsByName(CommentSupervise);
    } // setupUi

    void retranslateUi(QDialog *CommentSupervise)
    {
        CommentSupervise->setWindowTitle(QApplication::translate("CommentSupervise", "\350\257\204\350\256\272\347\256\241\347\220\206", Q_NULLPTR));
        btnBack->setText(QString());
        btnNext->setText(QString());
        gbComment->setTitle(QString());
        lblStar->setText(QApplication::translate("CommentSupervise", "\350\257\204\344\273\267\346\230\237\347\272\247\357\274\232", Q_NULLPTR));
        lblContent->setText(QApplication::translate("CommentSupervise", "\346\226\207\345\255\227\345\206\205\345\256\271\357\274\232", Q_NULLPTR));
        gbProperty->setTitle(QString());
        deDate->setDisplayFormat(QApplication::translate("CommentSupervise", "yyyy/MM/dd", Q_NULLPTR));
        lblComId->setText(QApplication::translate("CommentSupervise", "\350\257\204\350\256\272ID\357\274\232", Q_NULLPTR));
        lblSrcId->setText(QApplication::translate("CommentSupervise", "\350\257\204\350\256\272\350\200\205ID\357\274\232", Q_NULLPTR));
        lblDestId->setText(QApplication::translate("CommentSupervise", "\350\257\204\350\256\272\345\257\271\350\261\241ID\357\274\232", Q_NULLPTR));
        lblDate->setText(QApplication::translate("CommentSupervise", "\350\257\204\350\256\272\346\227\245\346\234\237\357\274\232", Q_NULLPTR));
        lblTitle->setText(QApplication::translate("CommentSupervise", "\350\257\204\350\256\272\346\240\207\351\242\230\357\274\232", Q_NULLPTR));
        btnSave->setText(QApplication::translate("CommentSupervise", "\344\277\235\345\255\230\346\224\271\345\212\250", Q_NULLPTR));
        btnUndo->setText(QApplication::translate("CommentSupervise", "\346\222\244\351\224\200\346\224\271\345\212\250", Q_NULLPTR));
        btnDel->setText(QString());
        btnAdd->setText(QString());
        lblCommSVBGN->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CommentSupervise: public Ui_CommentSupervise {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMENTSUPERVISE_H
