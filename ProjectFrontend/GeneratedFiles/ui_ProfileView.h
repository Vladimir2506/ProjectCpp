/********************************************************************************
** Form generated from reading UI file 'ProfileView.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEVIEW_H
#define UI_PROFILEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_ProfileView
{
public:
    QGroupBox *gbProfile;
    QLabel *lblID;
    QLabel *lblPhone;
    QLabel *lblPassword;
    QLabel *lblDeux;
    QLineEdit *lePassword;
    QLineEdit *leDeux;
    QLineEdit *lePhone;
    QLineEdit *leID;
    QLabel *lblState1;
    QLabel *lblState2;
    QLabel *lblState3;
    QPushButton *btnSave;
    QPushButton *btnUndo;
    QLabel *lblName;
    QLineEdit *leName;
    QLabel *lblState4;
    QGroupBox *gbOrders;
    QTableView *tbOrders;
    QLabel *lblOrders;
    QComboBox *cbOrders;
    QLabel *lblDate;
    QGroupBox *gbComments;
    QTableView *tbComments;
    QLabel *lblProfBGN;

    void setupUi(QDialog *ProfileView)
    {
        if (ProfileView->objectName().isEmpty())
            ProfileView->setObjectName(QStringLiteral("ProfileView"));
        ProfileView->resize(1036, 824);
        gbProfile = new QGroupBox(ProfileView);
        gbProfile->setObjectName(QStringLiteral("gbProfile"));
        gbProfile->setGeometry(QRect(20, 175, 450, 325));
        lblID = new QLabel(gbProfile);
        lblID->setObjectName(QStringLiteral("lblID"));
        lblID->setGeometry(QRect(50, 25, 125, 25));
        lblPhone = new QLabel(gbProfile);
        lblPhone->setObjectName(QStringLiteral("lblPhone"));
        lblPhone->setGeometry(QRect(50, 75, 125, 25));
        lblPassword = new QLabel(gbProfile);
        lblPassword->setObjectName(QStringLiteral("lblPassword"));
        lblPassword->setGeometry(QRect(50, 175, 125, 25));
        lblDeux = new QLabel(gbProfile);
        lblDeux->setObjectName(QStringLiteral("lblDeux"));
        lblDeux->setGeometry(QRect(50, 225, 125, 25));
        lePassword = new QLineEdit(gbProfile);
        lePassword->setObjectName(QStringLiteral("lePassword"));
        lePassword->setGeometry(QRect(200, 175, 150, 25));
        lePassword->setMaxLength(8);
        lePassword->setEchoMode(QLineEdit::Password);
        leDeux = new QLineEdit(gbProfile);
        leDeux->setObjectName(QStringLiteral("leDeux"));
        leDeux->setGeometry(QRect(200, 225, 150, 25));
        leDeux->setMaxLength(8);
        leDeux->setEchoMode(QLineEdit::Password);
        lePhone = new QLineEdit(gbProfile);
        lePhone->setObjectName(QStringLiteral("lePhone"));
        lePhone->setGeometry(QRect(200, 75, 150, 25));
        lePhone->setMaxLength(11);
        leID = new QLineEdit(gbProfile);
        leID->setObjectName(QStringLiteral("leID"));
        leID->setGeometry(QRect(200, 25, 150, 25));
        leID->setReadOnly(true);
        lblState1 = new QLabel(gbProfile);
        lblState1->setObjectName(QStringLiteral("lblState1"));
        lblState1->setGeometry(QRect(375, 75, 25, 25));
        lblState2 = new QLabel(gbProfile);
        lblState2->setObjectName(QStringLiteral("lblState2"));
        lblState2->setGeometry(QRect(375, 175, 25, 25));
        lblState3 = new QLabel(gbProfile);
        lblState3->setObjectName(QStringLiteral("lblState3"));
        lblState3->setGeometry(QRect(375, 225, 25, 25));
        btnSave = new QPushButton(gbProfile);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        btnSave->setGeometry(QRect(75, 275, 100, 40));
        btnUndo = new QPushButton(gbProfile);
        btnUndo->setObjectName(QStringLiteral("btnUndo"));
        btnUndo->setGeometry(QRect(255, 275, 100, 40));
        lblName = new QLabel(gbProfile);
        lblName->setObjectName(QStringLiteral("lblName"));
        lblName->setGeometry(QRect(50, 125, 125, 25));
        leName = new QLineEdit(gbProfile);
        leName->setObjectName(QStringLiteral("leName"));
        leName->setGeometry(QRect(200, 125, 150, 25));
        leName->setMaxLength(10);
        lblState4 = new QLabel(gbProfile);
        lblState4->setObjectName(QStringLiteral("lblState4"));
        lblState4->setGeometry(QRect(375, 125, 25, 25));
        gbOrders = new QGroupBox(ProfileView);
        gbOrders->setObjectName(QStringLiteral("gbOrders"));
        gbOrders->setGeometry(QRect(520, 175, 450, 325));
        gbOrders->setAlignment(Qt::AlignCenter);
        tbOrders = new QTableView(gbOrders);
        tbOrders->setObjectName(QStringLiteral("tbOrders"));
        tbOrders->setGeometry(QRect(25, 150, 400, 150));
        tbOrders->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbOrders->setSelectionMode(QAbstractItemView::NoSelection);
        tbOrders->setSelectionBehavior(QAbstractItemView::SelectRows);
        lblOrders = new QLabel(gbOrders);
        lblOrders->setObjectName(QStringLiteral("lblOrders"));
        lblOrders->setGeometry(QRect(75, 50, 125, 25));
        cbOrders = new QComboBox(gbOrders);
        cbOrders->setObjectName(QStringLiteral("cbOrders"));
        cbOrders->setGeometry(QRect(250, 50, 125, 25));
        lblDate = new QLabel(gbOrders);
        lblDate->setObjectName(QStringLiteral("lblDate"));
        lblDate->setGeometry(QRect(150, 100, 150, 25));
        gbComments = new QGroupBox(ProfileView);
        gbComments->setObjectName(QStringLiteral("gbComments"));
        gbComments->setGeometry(QRect(20, 550, 950, 225));
        gbComments->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        tbComments = new QTableView(gbComments);
        tbComments->setObjectName(QStringLiteral("tbComments"));
        tbComments->setGeometry(QRect(25, 30, 900, 175));
        tbComments->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbComments->setSelectionMode(QAbstractItemView::NoSelection);
        lblProfBGN = new QLabel(ProfileView);
        lblProfBGN->setObjectName(QStringLiteral("lblProfBGN"));
        lblProfBGN->setGeometry(QRect(0, 0, 1000, 800));
        lblProfBGN->raise();
        gbProfile->raise();
        gbOrders->raise();
        gbComments->raise();
        QWidget::setTabOrder(lePhone, leName);
        QWidget::setTabOrder(leName, lePassword);
        QWidget::setTabOrder(lePassword, leDeux);
        QWidget::setTabOrder(leDeux, btnSave);
        QWidget::setTabOrder(btnSave, btnUndo);
        QWidget::setTabOrder(btnUndo, leID);
        QWidget::setTabOrder(leID, tbOrders);
        QWidget::setTabOrder(tbOrders, cbOrders);
        QWidget::setTabOrder(cbOrders, tbComments);

        retranslateUi(ProfileView);
        QObject::connect(lePhone, SIGNAL(textEdited(QString)), ProfileView, SLOT(OnDelta()));
        QObject::connect(lePassword, SIGNAL(textEdited(QString)), ProfileView, SLOT(OnDelta()));
        QObject::connect(leDeux, SIGNAL(textEdited(QString)), ProfileView, SLOT(OnDelta()));
        QObject::connect(btnSave, SIGNAL(clicked()), ProfileView, SLOT(OnSave()));
        QObject::connect(btnUndo, SIGNAL(clicked()), ProfileView, SLOT(OnUndo()));
        QObject::connect(cbOrders, SIGNAL(currentIndexChanged(QString)), ProfileView, SLOT(BindOrder(QString)));

        QMetaObject::connectSlotsByName(ProfileView);
    } // setupUi

    void retranslateUi(QDialog *ProfileView)
    {
        ProfileView->setWindowTitle(QApplication::translate("ProfileView", "\344\270\252\344\272\272\350\265\204\346\226\231", Q_NULLPTR));
        gbProfile->setTitle(QString());
        lblID->setText(QApplication::translate("ProfileView", "\347\224\250\346\210\267ID\357\274\232", Q_NULLPTR));
        lblPhone->setText(QApplication::translate("ProfileView", "\347\224\250\346\210\267\347\224\265\350\257\235\345\217\267\347\240\201\357\274\232", Q_NULLPTR));
        lblPassword->setText(QApplication::translate("ProfileView", "\347\224\250\346\210\267\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        lblDeux->setText(QApplication::translate("ProfileView", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        lePassword->setPlaceholderText(QApplication::translate("ProfileView", "8\344\275\215\345\257\206\347\240\201", Q_NULLPTR));
        leDeux->setPlaceholderText(QApplication::translate("ProfileView", "8\344\275\215\345\257\206\347\240\201", Q_NULLPTR));
        lePhone->setPlaceholderText(QApplication::translate("ProfileView", "11\344\275\215\346\211\213\346\234\272\345\217\267\347\240\201", Q_NULLPTR));
        lblState1->setText(QString());
        lblState2->setText(QString());
        lblState3->setText(QString());
        btnSave->setText(QApplication::translate("ProfileView", "\344\277\235\345\255\230\344\277\256\346\224\271", Q_NULLPTR));
        btnUndo->setText(QApplication::translate("ProfileView", "\346\222\244\351\224\200\346\224\271\345\212\250", Q_NULLPTR));
        lblName->setText(QApplication::translate("ProfileView", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        leName->setPlaceholderText(QApplication::translate("ProfileView", "10\344\270\252\345\255\227\347\254\246\344\271\213\345\206\205", Q_NULLPTR));
        lblState4->setText(QString());
        gbOrders->setTitle(QApplication::translate("ProfileView", "\346\237\245\347\234\213\345\216\206\345\217\262\350\256\242\345\215\225", Q_NULLPTR));
        lblOrders->setText(QApplication::translate("ProfileView", "\350\257\267\351\200\211\346\213\251\350\256\242\345\215\225\345\217\267\357\274\232", Q_NULLPTR));
        lblDate->setText(QString());
        gbComments->setTitle(QApplication::translate("ProfileView", "\346\237\245\347\234\213\345\216\206\345\217\262\350\257\204\350\256\272", Q_NULLPTR));
        lblProfBGN->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ProfileView: public Ui_ProfileView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEVIEW_H
