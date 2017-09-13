/********************************************************************************
** Form generated from reading UI file 'RegisterForm.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERFORM_H
#define UI_REGISTERFORM_H

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

QT_BEGIN_NAMESPACE

class Ui_RegisterForm
{
public:
    QGroupBox *gbRegister;
    QLabel *lblPhone;
    QLabel *lblPW;
    QLabel *lblState1;
    QLabel *lblState2;
    QLineEdit *lePhone;
    QLineEdit *lePW;
    QPushButton *btnSubmit;
    QPushButton *btnCancel;
    QLabel *lblErrMsg;
    QLabel *lblPWDeux;
    QLabel *lblState3;
    QLineEdit *lePWDeux;
    QLabel *lblChar;
    QComboBox *cbChar;
    QLabel *lblName;
    QLineEdit *leName;
    QLabel *lblState4;

    void setupUi(QDialog *RegisterForm)
    {
        if (RegisterForm->objectName().isEmpty())
            RegisterForm->setObjectName(QStringLiteral("RegisterForm"));
        RegisterForm->setWindowModality(Qt::WindowModal);
        RegisterForm->setEnabled(true);
        RegisterForm->resize(500, 500);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RegisterForm->sizePolicy().hasHeightForWidth());
        RegisterForm->setSizePolicy(sizePolicy);
        RegisterForm->setMinimumSize(QSize(500, 500));
        RegisterForm->setMaximumSize(QSize(500, 500));
        gbRegister = new QGroupBox(RegisterForm);
        gbRegister->setObjectName(QStringLiteral("gbRegister"));
        gbRegister->setGeometry(QRect(25, 25, 450, 450));
        gbRegister->setMinimumSize(QSize(450, 450));
        gbRegister->setMaximumSize(QSize(450, 450));
        gbRegister->setAlignment(Qt::AlignCenter);
        lblPhone = new QLabel(gbRegister);
        lblPhone->setObjectName(QStringLiteral("lblPhone"));
        lblPhone->setGeometry(QRect(50, 50, 150, 25));
        lblPhone->setFrameShape(QFrame::NoFrame);
        lblPW = new QLabel(gbRegister);
        lblPW->setObjectName(QStringLiteral("lblPW"));
        lblPW->setGeometry(QRect(50, 100, 150, 25));
        lblState1 = new QLabel(gbRegister);
        lblState1->setObjectName(QStringLiteral("lblState1"));
        lblState1->setGeometry(QRect(375, 50, 25, 25));
        lblState2 = new QLabel(gbRegister);
        lblState2->setObjectName(QStringLiteral("lblState2"));
        lblState2->setGeometry(QRect(375, 100, 25, 25));
        lePhone = new QLineEdit(gbRegister);
        lePhone->setObjectName(QStringLiteral("lePhone"));
        lePhone->setGeometry(QRect(200, 50, 150, 25));
        lePhone->setMaxLength(11);
        lePW = new QLineEdit(gbRegister);
        lePW->setObjectName(QStringLiteral("lePW"));
        lePW->setGeometry(QRect(200, 100, 150, 25));
        lePW->setMaxLength(8);
        lePW->setEchoMode(QLineEdit::Password);
        btnSubmit = new QPushButton(gbRegister);
        btnSubmit->setObjectName(QStringLiteral("btnSubmit"));
        btnSubmit->setGeometry(QRect(75, 350, 100, 50));
        btnCancel = new QPushButton(gbRegister);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(260, 350, 100, 50));
        lblErrMsg = new QLabel(gbRegister);
        lblErrMsg->setObjectName(QStringLiteral("lblErrMsg"));
        lblErrMsg->setGeometry(QRect(50, 300, 350, 25));
        lblPWDeux = new QLabel(gbRegister);
        lblPWDeux->setObjectName(QStringLiteral("lblPWDeux"));
        lblPWDeux->setGeometry(QRect(50, 150, 150, 25));
        lblState3 = new QLabel(gbRegister);
        lblState3->setObjectName(QStringLiteral("lblState3"));
        lblState3->setGeometry(QRect(375, 150, 25, 25));
        lePWDeux = new QLineEdit(gbRegister);
        lePWDeux->setObjectName(QStringLiteral("lePWDeux"));
        lePWDeux->setGeometry(QRect(200, 150, 150, 25));
        lePWDeux->setMaxLength(8);
        lePWDeux->setEchoMode(QLineEdit::Password);
        lblChar = new QLabel(gbRegister);
        lblChar->setObjectName(QStringLiteral("lblChar"));
        lblChar->setGeometry(QRect(50, 200, 150, 25));
        cbChar = new QComboBox(gbRegister);
        cbChar->setObjectName(QStringLiteral("cbChar"));
        cbChar->setGeometry(QRect(200, 200, 150, 25));
        cbChar->setEditable(false);
        lblName = new QLabel(gbRegister);
        lblName->setObjectName(QStringLiteral("lblName"));
        lblName->setGeometry(QRect(50, 250, 150, 25));
        leName = new QLineEdit(gbRegister);
        leName->setObjectName(QStringLiteral("leName"));
        leName->setGeometry(QRect(200, 250, 150, 25));
        lblState4 = new QLabel(gbRegister);
        lblState4->setObjectName(QStringLiteral("lblState4"));
        lblState4->setGeometry(QRect(375, 250, 25, 25));
        QWidget::setTabOrder(lePhone, lePW);
        QWidget::setTabOrder(lePW, lePWDeux);
        QWidget::setTabOrder(lePWDeux, cbChar);
        QWidget::setTabOrder(cbChar, btnSubmit);
        QWidget::setTabOrder(btnSubmit, btnCancel);

        retranslateUi(RegisterForm);
        QObject::connect(btnCancel, SIGNAL(clicked()), RegisterForm, SLOT(reject()));
        QObject::connect(btnSubmit, SIGNAL(clicked()), RegisterForm, SLOT(SubmitReg()));
        QObject::connect(cbChar, SIGNAL(currentIndexChanged(int)), RegisterForm, SLOT(BindSelect(int)));
        QObject::connect(leName, SIGNAL(textChanged(QString)), RegisterForm, SLOT(OnDelta()));
        QObject::connect(lePWDeux, SIGNAL(textChanged(QString)), RegisterForm, SLOT(OnDelta()));
        QObject::connect(lePW, SIGNAL(textChanged(QString)), RegisterForm, SLOT(OnDelta()));
        QObject::connect(lePhone, SIGNAL(textChanged(QString)), RegisterForm, SLOT(OnDelta()));

        cbChar->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(RegisterForm);
    } // setupUi

    void retranslateUi(QDialog *RegisterForm)
    {
        RegisterForm->setWindowTitle(QApplication::translate("RegisterForm", "\346\263\250\345\206\214\350\264\246\345\217\267", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        gbRegister->setWhatsThis(QApplication::translate("RegisterForm", "\347\224\261\346\225\260\345\255\227\345\222\214\345\255\227\346\257\215\347\273\204\346\210\220", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        gbRegister->setTitle(QApplication::translate("RegisterForm", "\346\263\250\345\206\214\350\264\246\345\217\267", Q_NULLPTR));
        lblPhone->setText(QApplication::translate("RegisterForm", "\350\257\267\350\276\223\345\205\245\346\202\250\347\232\204\347\224\265\350\257\235\345\217\267\347\240\201\357\274\232", Q_NULLPTR));
        lblPW->setText(QApplication::translate("RegisterForm", "\350\257\267\350\256\276\347\275\256\346\202\250\347\232\204\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        lblState1->setText(QString());
        lblState2->setText(QString());
        lePhone->setText(QString());
        lePhone->setPlaceholderText(QApplication::translate("RegisterForm", "11\344\275\215\346\211\213\346\234\272\345\217\267\347\240\201", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        lePW->setWhatsThis(QApplication::translate("RegisterForm", "\347\224\261\346\225\260\345\255\227\345\222\214\345\255\227\346\257\215\347\273\204\346\210\220", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        lePW->setPlaceholderText(QApplication::translate("RegisterForm", "8\344\275\215\345\257\206\347\240\201", Q_NULLPTR));
        btnSubmit->setText(QApplication::translate("RegisterForm", "\345\256\214\346\210\220", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("RegisterForm", "\345\217\226\346\266\210", Q_NULLPTR));
        lblErrMsg->setText(QString());
        lblPWDeux->setText(QApplication::translate("RegisterForm", "\350\257\267\347\241\256\350\256\244\346\202\250\347\232\204\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        lblState3->setText(QString());
#ifndef QT_NO_WHATSTHIS
        lePWDeux->setWhatsThis(QApplication::translate("RegisterForm", "\347\224\261\346\225\260\345\255\227\345\222\214\345\255\227\346\257\215\347\273\204\346\210\220", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        lePWDeux->setPlaceholderText(QApplication::translate("RegisterForm", "8\344\275\215\345\257\206\347\240\201", Q_NULLPTR));
        lblChar->setText(QApplication::translate("RegisterForm", "\350\257\267\351\200\211\346\213\251\346\202\250\347\232\204\350\272\253\344\273\275\357\274\232", Q_NULLPTR));
        cbChar->setCurrentText(QString());
        lblName->setText(QApplication::translate("RegisterForm", "\350\257\267\350\276\223\345\205\245\346\202\250\347\232\204\345\220\215\345\255\227\357\274\232", Q_NULLPTR));
        leName->setPlaceholderText(QApplication::translate("RegisterForm", "10\344\270\252\345\255\227\347\254\246\344\271\213\345\206\205", Q_NULLPTR));
        lblState4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RegisterForm: public Ui_RegisterForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERFORM_H
