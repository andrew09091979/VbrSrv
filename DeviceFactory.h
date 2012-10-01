#ifndef DEVICEFACTORY_H
#define DEVICEFACTORY_H

#include <map>
#include <string>

template <class BaseClass>
class DeviceFactory
{
private:
    template <typename T>
    static BaseClass* NewDevCreator();

    typedef BaseClass* (*PCreateFunc)();

    std::map<std::string, PCreateFunc> m_CreateFuncs;

public:
    DeviceFactory();
    DeviceFactory(int);
    ~DeviceFactory();
    DeviceFactory(const DeviceFactory&);
    DeviceFactory& operator=(const DeviceFactory&);

    template <class T>
    bool RegisterDev(std::string);

    BaseClass * CreateDev(std::string name);
};

template <class BaseClass>
DeviceFactory<BaseClass>::DeviceFactory()
{
}

template <class BaseClass>
DeviceFactory<BaseClass>::~DeviceFactory()
{
}
template <class BaseClass>
DeviceFactory<BaseClass>& DeviceFactory<BaseClass>::operator =(const DeviceFactory&)
{
    return (*this);
}

template <class BaseClass>
DeviceFactory<BaseClass>::DeviceFactory(const DeviceFactory &)
{
}

template <class BaseClass>
template <class T>
bool DeviceFactory<BaseClass>::RegisterDev(std::string name)
{
    bool bRes = true;
    m_CreateFuncs[name] = &NewDevCreator<T>;
    return bRes;
}

template <class BaseClass>
template <class T>
BaseClass* DeviceFactory<BaseClass>::NewDevCreator()
{
    return (new T);
}

template <class BaseClass>
BaseClass * DeviceFactory<BaseClass>::CreateDev(std::string name)
{
    PCreateFunc pCreateFunc;
    pCreateFunc = m_CreateFuncs[name];
    return (*pCreateFunc)();
}

#endif // DEVICEFACTORY_H
