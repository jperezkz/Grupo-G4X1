/****************************************************************************
** Meta object code from reading C++ file 'specificworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "specificworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'specificworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SpecificWorker_t {
    QByteArrayData data[18];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SpecificWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SpecificWorker_t qt_meta_stringdata_SpecificWorker = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SpecificWorker"
QT_MOC_LITERAL(1, 15, 13), // "initializeMap"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 3), // "key"
QT_MOC_LITERAL(4, 34, 5), // "clave"
QT_MOC_LITERAL(5, 40, 1), // "x"
QT_MOC_LITERAL(6, 42, 1), // "y"
QT_MOC_LITERAL(7, 44, 11), // "getLocation"
QT_MOC_LITERAL(8, 56, 1), // "p"
QT_MOC_LITERAL(9, 58, 12), // "marcarCeldas"
QT_MOC_LITERAL(10, 71, 15), // "calcularSeccion"
QT_MOC_LITERAL(11, 87, 10), // "calculoRot"
QT_MOC_LITERAL(12, 98, 25), // "RoboCompLaser::TLaserData"
QT_MOC_LITERAL(13, 124, 5), // "rdata"
QT_MOC_LITERAL(14, 130, 7), // "compute"
QT_MOC_LITERAL(15, 138, 13), // "startup_check"
QT_MOC_LITERAL(16, 152, 10), // "initialize"
QT_MOC_LITERAL(17, 163, 6) // "period"

    },
    "SpecificWorker\0initializeMap\0\0key\0"
    "clave\0x\0y\0getLocation\0p\0marcarCeldas\0"
    "calcularSeccion\0calculoRot\0"
    "RoboCompLaser::TLaserData\0rdata\0compute\0"
    "startup_check\0initialize\0period"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpecificWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    2,   60,    2, 0x0a /* Public */,
       7,    1,   65,    2, 0x0a /* Public */,
       9,    1,   68,    2, 0x0a /* Public */,
      10,    2,   71,    2, 0x0a /* Public */,
      11,    1,   76,    2, 0x0a /* Public */,
      14,    0,   79,    2, 0x0a /* Public */,
      15,    0,   80,    2, 0x0a /* Public */,
      16,    1,   81,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    0x80000000 | 4, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Int, 0x80000000 | 4,    8,
    QMetaType::Void, 0x80000000 | 4,    8,
    QMetaType::Bool, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Float, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   17,

       0        // eod
};

void SpecificWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SpecificWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initializeMap(); break;
        case 1: { clave _r = _t->key((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< clave*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->getLocation((*reinterpret_cast< clave(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->marcarCeldas((*reinterpret_cast< clave(*)>(_a[1]))); break;
        case 4: { bool _r = _t->calcularSeccion((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { float _r = _t->calculoRot((*reinterpret_cast< RoboCompLaser::TLaserData(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->compute(); break;
        case 7: { int _r = _t->startup_check();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->initialize((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SpecificWorker::staticMetaObject = { {
    &GenericWorker::staticMetaObject,
    qt_meta_stringdata_SpecificWorker.data,
    qt_meta_data_SpecificWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SpecificWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpecificWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SpecificWorker.stringdata0))
        return static_cast<void*>(this);
    return GenericWorker::qt_metacast(_clname);
}

int SpecificWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GenericWorker::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
