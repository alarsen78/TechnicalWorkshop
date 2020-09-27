#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "albumreader.h"


int main(int argc, char *argv[])
{

    qmlRegisterType<AlbumReader>("com.gmail.larand78", 1, 0, "AlbumReader");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    printf("app.exec()\n");
    fflush(stdout);

    return app.exec();
}
