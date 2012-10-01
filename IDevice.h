#ifndef IDEVICE_H
#define IDEVICE_H
#include <string>
#include <QDebug>
class IDevice
{

public:
    //IDevice();//{};
    virtual ~IDevice() {};
    virtual const std::string& GetName() const = 0;
};

class Regigraf : public IDevice
{
    std::string name;
public:
    Regigraf():name("Regigraf"){};
    ~Regigraf(){};
    const std::string& GetName() const {qDebug()<<"regigraf\n";return name;};
};

#endif // IDEVICE_H
