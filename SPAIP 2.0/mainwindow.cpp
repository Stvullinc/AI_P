#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDesktopServices>
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Инициализация стекового виджета
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    // Виджет авторизации
    authWidget = new AuthWidget();

    // Основной контент
    mainContent = new QWidget();
    QVBoxLayout *mainLayout = new QVBoxLayout(mainContent);

    // Перенос оригинальных элементов
    mainLayout->addWidget(ui->textBrowser);

    QHBoxLayout *inputLayout = new QHBoxLayout();
    inputLayout->addWidget(ui->lineEdit);
    inputLayout->addWidget(ui->pushButton);
    mainLayout->addLayout(inputLayout);

    // Добавление в стек
    stackedWidget->addWidget(authWidget);
    stackedWidget->addWidget(mainContent);

    // Соединение сигналов
    connect(authWidget, &AuthWidget::loginSuccess, this, &MainWindow::handleLoginSuccess);
    connect(authWidget, &AuthWidget::registerSuccess, this, &MainWindow::handleRegisterSuccess);
}

QString MainWindow::ai_answer(QString question)
{
    QString phrases[8] = {
        "ты справишься с этим!",
        "не сдавайся, ты на правильном пути!",
        "каждый день — это новый шанс!",
        "ты сильнее, чем думаешь!",
        "успех — это результат упорства!",
        "ты можешь достичь всего, что задумал!",
        "не бойся ошибок, они — часть пути!",
        "ты уникален и способен на многое!"
    };
    int a = rand() % 8;
    return phrases[a];
}

void MainWindow::handleLoginSuccess()
{
    stackedWidget->setCurrentIndex(1);
}

void MainWindow::handleRegisterSuccess()
{
    stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_clicked()
{
    QString question = ui->lineEdit->text();
    if(question.isEmpty()) return;

    appendToTextBrowser("Вы:", question, "black");

    QString answer = ai_answer(question);
    appendToTextBrowser("AI:", answer, "blue");

    ui->lineEdit->clear();
}

void MainWindow::appendToTextBrowser(const QString& label, const QString& message, const QString& color)
{
    QString formatted = QString("<p style='margin:5px 0;'><b>%1</b> <span style='color:%3;'>%2</span></p>")
    .arg(label)
        .arg(message.toHtmlEscaped())
        .arg(color);

    ui->textBrowser->append(formatted);

    // Прокрутка вниз
    QTextCursor cursor = ui->textBrowser->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->textBrowser->setTextCursor(cursor);
}

MainWindow::~MainWindow()
{
    delete ui;
}
