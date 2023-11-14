#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "icsystem.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    ICSystem *icsystem = new ICSystem();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("icsystem", icsystem);

    const QUrl url(QStringLiteral("qrc:/qml/dashboard.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);


    return app.exec();
}
