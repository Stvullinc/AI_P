#include "ai.h"
#include "mainwindow.h"
#include <iostream>
#include <cstdlib>
#include <QString>
#include <curl/curl.h>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrl>
#include <QEventLoop>
#include <QString>
#include <QDebug>

QString MainWindow::ai_answer(QString question)
{
    QNetworkAccessManager manager;
    QNetworkRequest request(QUrl("http://192.168.8.183:5000/generate"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Создание JSON-объекта
    QJsonObject json;
    json["question"] = question;

    QJsonDocument jsonDoc(json);
    QByteArray jsonData = jsonDoc.toJson();

    // Отправка POST-запроса
    QNetworkReply* reply = manager.post(request, jsonData);

    // Ожидание ответа
    QEventLoop eventLoop;
    connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();

    // Обработка ответа
    QString answer;
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument responseDoc = QJsonDocument::fromJson(responseData);
        QJsonObject responseObj = responseDoc.object();

        // Извлечение ответа
        answer = responseObj["answer"].toString();
    } else {
        qDebug() << "Error:" << reply->errorString();
        answer = QString("Error: ") + reply->errorString();
    }

    reply->deleteLater(); // Освобождение ресурсов
    return answer;
}
