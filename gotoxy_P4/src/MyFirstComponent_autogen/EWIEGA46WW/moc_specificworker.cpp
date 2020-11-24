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
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SpecificWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SpecificWorker_t qt_meta_stringdata_SpecificWorker = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SpecificWorker"
QT_MOC_LITERAL(1, 15, 7), // "compute"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 15), // "generarPoligono"
QT_MOC_LITERAL(4, 40, 10), // "QPolygonF&"
QT_MOC_LITERAL(5, 51, 1), // "p"
QT_MOC_LITERAL(6, 53, 13), // "calculoPuntos"
QT_MOC_LITERAL(7, 67, 7), // "vOrigen"
QT_MOC_LITERAL(8, 75, 7), // "rOrigen"
QT_MOC_LITERAL(9, 83, 19), // "std::vector<tupla>&"
QT_MOC_LITERAL(10, 103, 6), // "tuplas"
QT_MOC_LITERAL(11, 110, 13), // "ordenarPuntos"
QT_MOC_LITERAL(12, 124, 5), // "nuevo"
QT_MOC_LITERAL(13, 130, 15), // "Eigen::Vector2f"
QT_MOC_LITERAL(14, 146, 1), // "T"
QT_MOC_LITERAL(15, 148, 13), // "startup_check"
QT_MOC_LITERAL(16, 162, 10), // "initialize"
QT_MOC_LITERAL(17, 173, 6) // "period"

    },
    "SpecificWorker\0compute\0\0generarPoligono\0"
    "QPolygonF&\0p\0calculoPuntos\0vOrigen\0"
    "rOrigen\0std::vector<tupla>&\0tuplas\0"
    "ordenarPuntos\0nuevo\0Eigen::Vector2f\0"
    "T\0startup_check\0initialize\0period"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpecificWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    1,   45,    2, 0x0a /* Public */,
       6,    3,   48,    2, 0x0a /* Public */,
      11,    4,   55,    2, 0x0a /* Public */,
      15,    0,   64,    2, 0x0a /* Public */,
      16,    1,   65,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, 0x80000000 | 9,    7,    8,   10,
    QMetaType::Void, QMetaType::QPolygonF, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 13,    5,   10,   12,   14,
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
        case 0: _t->compute(); break;
        case 1: _t->generarPoligono((*reinterpret_cast< QPolygonF(*)>(_a[1]))); break;
        case 2: _t->calculoPuntos((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< std::vector<tupla>(*)>(_a[3]))); break;
        case 3: _t->ordenarPuntos((*reinterpret_cast< QPolygonF(*)>(_a[1])),(*reinterpret_cast< std::vector<tupla>(*)>(_a[2])),(*reinterpret_cast< std::vector<tupla>(*)>(_a[3])),(*reinterpret_cast< Eigen::Vector2f(*)>(_a[4]))); break;
        case 4: { int _r = _t->startup_check();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->initialize((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
