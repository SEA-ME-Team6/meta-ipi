#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "husystem.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    HUSystem *husystem = new HUSystem();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("husystem", husystem);
    
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
