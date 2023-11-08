#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "VehicleStatusClient.hpp"

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    VehicleStatusClient *vehiclestatusclient = new VehicleStatusClient();
    vehiclestatusclient->run();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("vehicle", vehiclestatusclient);

    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);


    return app.exec();
}
