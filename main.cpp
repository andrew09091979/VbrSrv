#include <QtGui/QApplication>
#include <QPluginLoader>
#include <QDebug>
#include "mainwindow.h"
#include "config.h"

int main(int argc, char *argv[])
{

    Config cnfg("ServConfig.xml");
    QPluginLoader protocolPlugin("C:\\Projects\\QT\\plugins\\myPlugin.dll");
    protocolPlugin.load();
    if (!protocolPlugin.isLoaded())
    {
        qDebug() << QString("Error plugin loading");
    }
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    protocolPlugin.unload();
    return a.exec();
}
