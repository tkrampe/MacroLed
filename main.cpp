#include "androidrfcomm.h"
#include "controller.h"

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

static QObject *example_qobject_singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    Controller *example = new Controller();
    return example;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterSingletonType<Controller>("org.tyler.macroled", 1, 0, "Ctrl", example_qobject_singletontype_provider);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
