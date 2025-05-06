#include "authwidget.h"
#include "ui_authwidget.h"
#include <QMessageBox>

AuthWidget::AuthWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuthWidget)
//    , networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    connect(ui->btnLogin, &QPushButton::clicked, this, &AuthWidget::onLoginClicked);
    connect(ui->btnRegister, &QPushButton::clicked, this, &AuthWidget::onRegisterClicked);
    connect(ui->btnSwitchToRegister, &QPushButton::clicked, this, &AuthWidget::switchToRegister);
    connect(ui->btnSwitchToLogin, &QPushButton::clicked, this, &AuthWidget::switchToLogin);
}

void AuthWidget::onLoginClicked()
{
    emit loginSuccess();
}

void AuthWidget::onRegisterClicked()
{
    // Реализация регистрации
    emit registerSuccess();
}

void AuthWidget::switchToLogin()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void AuthWidget::switchToRegister()
{
    ui->stackedWidget->setCurrentIndex(1);
}

AuthWidget::~AuthWidget()
{
    delete ui;
}
