#ifndef AUTHWIDGET_H
#define AUTHWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class AuthWidget; }
QT_END_NAMESPACE

class AuthWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AuthWidget(QWidget *parent = nullptr);
    ~AuthWidget();

signals:
    void loginSuccess();
    void registerSuccess();

private slots:
    void onLoginClicked();
    void onRegisterClicked();
    void switchToLogin();
    void switchToRegister();

private:
    Ui::AuthWidget *ui;
    // QNetworkAccessManager *networkManager;
};

#endif // AUTHWIDGET_H
