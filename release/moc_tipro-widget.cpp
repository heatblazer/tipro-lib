/****************************************************************************
** Meta object code from reading C++ file 'tipro-widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tipro-lib/tipro-widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tipro-widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_tipro__TiproWidget_t {
    QByteArrayData data[15];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tipro__TiproWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tipro__TiproWidget_t qt_meta_stringdata_tipro__TiproWidget = {
    {
QT_MOC_LITERAL(0, 0, 18), // "tipro::TiproWidget"
QT_MOC_LITERAL(1, 19, 4), // "led1"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 4), // "led2"
QT_MOC_LITERAL(4, 30, 4), // "led3"
QT_MOC_LITERAL(5, 35, 4), // "led4"
QT_MOC_LITERAL(6, 40, 13), // "toggleLedTest"
QT_MOC_LITERAL(7, 54, 11), // "testAllLeds"
QT_MOC_LITERAL(8, 66, 13), // "setBrightness"
QT_MOC_LITERAL(9, 80, 5), // "level"
QT_MOC_LITERAL(10, 86, 13), // "turnOffScreen"
QT_MOC_LITERAL(11, 100, 12), // "turnOnScreen"
QT_MOC_LITERAL(12, 113, 11), // "hTextChange"
QT_MOC_LITERAL(13, 125, 7), // "cleanup"
QT_MOC_LITERAL(14, 133, 8) // "showInfo"

    },
    "tipro::TiproWidget\0led1\0\0led2\0led3\0"
    "led4\0toggleLedTest\0testAllLeds\0"
    "setBrightness\0level\0turnOffScreen\0"
    "turnOnScreen\0hTextChange\0cleanup\0"
    "showInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tipro__TiproWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    1,   80,    2, 0x08 /* Private */,
      10,    0,   83,    2, 0x08 /* Private */,
      11,    0,   84,    2, 0x08 /* Private */,
      12,    0,   85,    2, 0x08 /* Private */,
      13,    0,   86,    2, 0x08 /* Private */,
      14,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void tipro::TiproWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TiproWidget *_t = static_cast<TiproWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->led1();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { int _r = _t->led2();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: { int _r = _t->led3();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->led4();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: _t->toggleLedTest(); break;
        case 5: _t->testAllLeds(); break;
        case 6: { int _r = _t->setBrightness((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 7: _t->turnOffScreen(); break;
        case 8: _t->turnOnScreen(); break;
        case 9: _t->hTextChange(); break;
        case 10: _t->cleanup(); break;
        case 11: _t->showInfo(); break;
        default: ;
        }
    }
}

const QMetaObject tipro::TiproWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_tipro__TiproWidget.data,
      qt_meta_data_tipro__TiproWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *tipro::TiproWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tipro::TiproWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_tipro__TiproWidget.stringdata0))
        return static_cast<void*>(const_cast< TiproWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int tipro::TiproWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
