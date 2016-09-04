#ifndef TIPROLIB_H
#define TIPROLIB_H

// qt library loader //
#include <QLibrary>

// tipro types //
#include "types.h"

namespace tipro
{

class TiproLib
{

public:
    static bool loadLib(const QString& src);
    static TiproLib &Instance(/*special one*/);
    void disableTouchScreen();
    void enableTouchScreen();
    int setLeds(int n);
    int setBrightness(int level);
    int enumDevices(void);
    int detectDevices(void);


private:
    static bool _loadAll(void);

private:
    HIDTouchscreenDisable _disableTouchScreen;
    HIDSetLuminance _setLuminace;
    HIDTouchscreenEnable _enableTouchScreen;
    HIDSetLeds _setLeds;
    HIDDetectDevices _detectDevices;
    HIDEnumerateModules _enumModules;
    HIDGetControllerInfo _getControllerInfo;
    HIDGetModuleVersion _getModuleVer;



private:
    // static inst
    static QLibrary* s_inst;
    static TiproLib* s_selfRef;
};


}

#endif // TIPROLIB_H
