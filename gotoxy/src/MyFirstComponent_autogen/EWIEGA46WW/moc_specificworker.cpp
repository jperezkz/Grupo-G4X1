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
    QByteArrayData data[13];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SpecificWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SpecificWorker_t qt_meta_stringdata_SpecificWorker = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SpecificWorker"
QT_MOC_LITERAL(1, 15, 16), // "calcularRotacion"
QT_MOC_LITERAL(2, 32, 15), // "Eigen::Vector2f"
QT_MOC_LITERAL(3, 48, 0), // ""
QT_MOC_LITERAL(4, 49, 2), // "Tw"
QT_MOC_LITERAL(5, 52, 2), // "Rw"
QT_MOC_LITERAL(6, 55, 5), // "alpha"
QT_MOC_LITERAL(7, 61, 6), // "float&"
QT_MOC_LITERAL(8, 68, 3), // "rot"
QT_MOC_LITERAL(9, 72, 7), // "compute"
QT_MOC_LITERAL(10, 80, 13), // "startup_check"
QT_MOC_LITERAL(11, 94, 10), // "initialize"
QT_MOC_LITERAL(12, 105, 6) // "period"

    },
    "SpecificWorker\0calcularRotacion\0"
    "Eigen::Vector2f\0\0Tw\0Rw\0alpha\0float&\0"
    "rot\0compute\0startup_check\0initialize\0"
    "period"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpecificWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   34,    3, 0x0a /* Public */,
       9,    0,   43,    3, 0x0a /* Public */,
      10,    0,   44,    3, 0x0a /* Public */,
      11,    1,   45,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2, 0x80000000 | 2, 0x80000000 | 2, QMetaType::Float, 0x80000000 | 7,    4,    5,    6,    8,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void SpecificWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SpecificWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { Eigen::Vector2f _r = _t->calcularRotacion((*reinterpret_cast< Eigen::Vector2f(*)>(_a[1])),(*reinterpret_cast< Eigen::Vector2f(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< Eigen::Vector2f*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->compute(); break;
        case 2: { int _r = _t->startup_check();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->initialize((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
