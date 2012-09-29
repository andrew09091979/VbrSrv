#ifndef CONFIG_H
#define CONFIG_H
#include <QString>
class Config
{
    QString cnfFile;
    Config();
public:

    Config(const QString &);
};

#endif // CONFIG_H
