#include "tipro-lib.h"

#include <iostream>

namespace tipro {

QLibrary* TiproLib::s_inst = nullptr;
TiproLib*   TiproLib::s_selfRef = nullptr;

bool TiproLib::loadLib(const QString &src)
{
    if (s_selfRef == nullptr) {
        s_selfRef = new TiproLib;
    }
    static QLibrary s_lib(src);
    s_lib.load();
    if(s_lib.isLoaded()) {
        s_inst = &s_lib; // take a ptr to this static var
        if (_loadAll()) {
            std::cout << "All is OK!!!" << std::endl;
            return true;
        } else {
            std::cout << "Failed load symbols!" << std::endl;
        }
    }
    return false;
}

TiproLib &TiproLib::Instance()
{
    // must load library before ! no point to call
    // it alpne, user won`t be able to use this class
    // anyway
    return *s_selfRef;
}

void TiproLib::disableTouchScreen()
{
    if (_disableTouchScreen) {
        _disableTouchScreen();
    }
}

void TiproLib::enableTouchScreen()
{
    if(_enableTouchScreen) {
        _enableTouchScreen();
    }
}

int TiproLib::setLeds(int n)
{
    if(_setLeds) {
        return _setLeds(n);
    }
    return -1;
}

int TiproLib::setBrightness(int level)
{
    if (_setLuminace) {
        return _setLuminace(level);
    }
    return -1;
}

int TiproLib::enumDevices()
{
    if(_enumModules) {
        return _enumModules();
    }
    return -1;
}

int TiproLib::detectDevices()
{
    if(_detectDevices) {
        return _detectDevices();
    }
}

bool TiproLib::_loadAll()
{
    bool allIsOk = true;
    s_selfRef->_disableTouchScreen = (HIDTouchscreenDisable)
                s_inst->resolve("HIDTouchscreenDisable");
    if (!s_selfRef->_disableTouchScreen) {
        allIsOk &= false;
    }
    s_selfRef->_enableTouchScreen = (HIDTouchscreenEnable)
                s_inst->resolve("HIDTouchscreenEnable");
    if (!s_selfRef->_enableTouchScreen) {
        allIsOk &= false;
    }

    s_selfRef->_setLuminace = (HIDSetLuminance)
            s_inst->resolve("HIDSetLuminance");
    if (!s_selfRef->_setLuminace) {
        allIsOk &= false;
    }

    s_selfRef->_setLeds = (HIDSetLeds)
            s_inst->resolve("HIDSetLeds");
    if (!s_selfRef->_setLeds) {
        allIsOk &= false;
    }

    s_selfRef->_detectDevices = (HIDDetectDevices)
            s_inst->resolve("HIDDetectDevices");
    if(!s_selfRef->_detectDevices) {
        allIsOk &= false;
    }

    s_selfRef->_enumModules = (HIDEnumerateModules)
            s_inst->resolve("HIDEnumerateModules");
    if(!s_selfRef->_enumModules) {
        allIsOk &= false;
    }

    return allIsOk;
}


} // namespace tipro

