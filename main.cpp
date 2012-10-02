#include <QtGui/QApplication>
#include <QPluginLoader>
#include <QDebug>
#include "mainwindow.h"
#include "config.h"
#include "DeviceFactory.h"
#include "IDevice.h"

int main(int argc, char *argv[])
{
    DeviceFactory<IDevice> devFactory;

    devFactory.RegisterDev<Regigraf>("Regigraf");

    IDevice * dev = devFactory.CreateDev("Regigraf");
    dev->GetName();
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
