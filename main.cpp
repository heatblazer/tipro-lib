#include <QApplication>
#include <QLibrary>
#include <iostream>
//#include <windef.h>


#include "tipro-lib.h"

#ifdef TIPROHIDAPI_EXPORTS
#define TIPROHIDAPI_API __declspec(dllexport)
#else
#define TIPROHIDAPI_API __declspec(dllimport)
#endif

#include "tipro-widget.h"


int main(int argc, char *argv[])
{
#ifdef TEST1
    bool res = tipro::TiproLib::loadLib("TiproHidApi.dll");
    if (res) {
        int devices = tipro::TiproLib::Instance().enumDevices();
        int detected = tipro::TiproLib::Instance().detectDevices();

        std::cout << devices << " " << detected << std::endl;
    }
#endif


    QApplication a(argc, argv);
    tipro::TiproWidget myWidget;
    myWidget.show();

    return a.exec();

}
