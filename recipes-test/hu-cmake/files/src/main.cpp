#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "GearSelectionServer.hpp"

using namespace v1::commonapi;

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    GearSelectionServer *server = new GearSelectionServer();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("server", server);

    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

