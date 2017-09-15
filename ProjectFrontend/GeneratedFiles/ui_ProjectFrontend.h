/********************************************************************************
** Form generated from reading UI file 'ProjectFrontend.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTFRONTEND_H
#define UI_PROJECTFRONTEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjectFrontendClass
{
public:
    QWidget *centralWidget;
    QGroupBox *gbLogin;
    QPushButton *btnSignUp;
    QPushButton *btnSignIn;
    QLabel *lblPhone;
    QLabel *lblPW;
    QLineEdit *lePhone;
    QLineEdit *lePW;
    QLabel *lblLoginBGN;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProjectFrontendClass)
    {
        if (ProjectFrontendClass->objectName().isEmpty())
            ProjectFrontendClass->setObjectName(QStringLiteral("ProjectFrontendClass"));
        ProjectFrontendClass->resize(600, 450);
        ProjectFrontendClass->setMinimumSize(QSize(600, 450));
        ProjectFrontendClass->setMaximumSize(QSize(600, 450));
        centralWidget = new QWidget(ProjectFrontendClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gbLogin = new QGroupBox(centralWidget);
        gbLogin->setObjectName(QStringLiteral("gbLogin"));
        gbLogin->setGeometry(QRect(50, 180, 500, 225));
        gbLogin->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        btnSignUp = new QPushButton(gbLogin);
        btnSignUp->setObjectName(QStringLiteral("btnSignUp"));
        btnSignUp->setGeometry(QRect(280, 150, 100, 50));
        btnSignIn = new QPushButton(gbLogin);
        btnSignIn->setObjectName(QStringLiteral("btnSignIn"));
        btnSignIn->setGeometry(QRect(120, 150, 100, 50));
        lblPhone = new QLabel(gbLogin);
        lblPhone->setObjectName(QStringLiteral("lblPhone"));
        lblPhone->setGeometry(QRect(75, 50, 155, 25));
        lblPW = new QLabel(gbLogin);
        lblPW->setObjectName(QStringLiteral("lblPW"));
        lblPW->setGeometry(QRect(75, 100, 155, 25));
        lePhone = new QLineEdit(gbLogin);
        lePhone->setObjectName(QStringLiteral("lePhone"));
        lePhone->setGeometry(QRect(250, 50, 150, 25));
        lePhone->setMaxLength(11);
        lePW = new QLineEdit(gbLogin);
        lePW->setObjectName(QStringLiteral("lePW"));
        lePW->setGeometry(QRect(250, 100, 150, 25));
        lePW->setMaxLength(8);
        lePW->setEchoMode(QLineEdit::Password);
        lblLoginBGN = new QLabel(centralWidget);
        lblLoginBGN->setObjectName(QStringLiteral("lblLoginBGN"));
        lblLoginBGN->setGeometry(QRect(0, 0, 600, 450));
        ProjectFrontendClass->setCentralWidget(centralWidget);
        lblLoginBGN->raise();
        gbLogin->raise();
        statusBar = new QStatusBar(ProjectFrontendClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ProjectFrontendClass->setStatusBar(statusBar);

        retranslateUi(ProjectFrontendClass);
        QObject::connect(btnSignUp, SIGNAL(clicked()), ProjectFrontendClass, SLOT(OnRegClicked()));
        QObject::connect(lePhone, SIGNAL(textChanged(QString)), ProjectFrontendClass, SLOT(CheckPhone(QString)));
        QObject::connect(lePW, SIGNAL(textChanged(QString)), ProjectFrontendClass, SLOT(CheckPW(QString)));
        QObject::connect(btnSignIn, SIGNAL(clicked()), ProjectFrontendClass, SLOT(OnLogClicked()));
        QObject::connect(lePW, SIGNAL(returnPressed()), btnSignIn, SLOT(click()));
        QObject::connect(lePhone, SIGNAL(returnPressed()), btnSignIn, SLOT(click()));

        QMetaObject::connectSlotsByName(ProjectFrontendClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProjectFrontendClass)
    {
        ProjectFrontendClass->setWindowTitle(QApplication::translate("ProjectFrontendClass", "\351\244\220\345\216\205\347\263\273\347\273\237", Q_NULLPTR));
        gbLogin->setTitle(QString());
        btnSignUp->setText(QApplication::translate("ProjectFrontendClass", "\346\263\250\345\206\214\350\264\246\345\217\267", Q_NULLPTR));
        btnSignIn->setText(QApplication::translate("ProjectFrontendClass", "\347\231\273\345\275\225\347\263\273\347\273\237", Q_NULLPTR));
        lblPhone->setText(QApplication::translate("ProjectFrontendClass", "\350\257\267\350\276\223\345\205\245\346\202\250\347\232\204\347\224\265\350\257\235\345\217\267\347\240\201\357\274\232", Q_NULLPTR));
        lblPW->setText(QApplication::translate("ProjectFrontendClass", "\350\257\267\350\276\223\345\205\245\346\202\250\347\232\204\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        lePhone->setText(QString());
        lePhone->setPlaceholderText(QApplication::translate("ProjectFrontendClass", "11\344\275\215\346\211\213\346\234\272\345\217\267", Q_NULLPTR));
        lePW->setText(QString());
        lePW->setPlaceholderText(QApplication::translate("ProjectFrontendClass", "8\344\275\215\345\257\206\347\240\201", Q_NULLPTR));
        lblLoginBGN->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ProjectFrontendClass: public Ui_ProjectFrontendClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTFRONTEND_H
