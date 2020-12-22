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
    QByteArrayData data[25];
    char stringdata0[321];
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
QT_MOC_LITERAL(6, 53, 25), // "RoboCompLaser::TLaserData"
QT_MOC_LITERAL(7, 79, 5), // "ldata"
QT_MOC_LITERAL(8, 85, 13), // "calculoPuntos"
QT_MOC_LITERAL(9, 99, 31), // "RoboCompGenericBase::TBaseState"
QT_MOC_LITERAL(10, 131, 5), // "tBase"
QT_MOC_LITERAL(11, 137, 19), // "std::vector<tupla>&"
QT_MOC_LITERAL(12, 157, 6), // "tuplas"
QT_MOC_LITERAL(13, 164, 13), // "ordenarPuntos"
QT_MOC_LITERAL(14, 178, 18), // "std::vector<tupla>"
QT_MOC_LITERAL(15, 197, 6), // "vector"
QT_MOC_LITERAL(16, 204, 15), // "Eigen::Vector2f"
QT_MOC_LITERAL(17, 220, 1), // "T"
QT_MOC_LITERAL(18, 222, 16), // "vectorResultados"
QT_MOC_LITERAL(19, 239, 10), // "obstaculos"
QT_MOC_LITERAL(20, 250, 34), // "std::vector<SpecificWorker::t..."
QT_MOC_LITERAL(21, 285, 3), // "aph"
QT_MOC_LITERAL(22, 289, 13), // "startup_check"
QT_MOC_LITERAL(23, 303, 10), // "initialize"
QT_MOC_LITERAL(24, 314, 6) // "period"

    },
    "SpecificWorker\0compute\0\0generarPoligono\0"
    "QPolygonF&\0p\0RoboCompLaser::TLaserData\0"
    "ldata\0calculoPuntos\0RoboCompGenericBase::TBaseState\0"
    "tBase\0std::vector<tupla>&\0tuplas\0"
    "ordenarPuntos\0std::vector<tupla>\0"
    "vector\0Eigen::Vector2f\0T\0vectorResultados\0"
    "obstaculos\0std::vector<SpecificWorker::tupla>\0"
    "aph\0startup_check\0initialize\0period"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpecificWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    2,   50,    2, 0x0a /* Public */,
       8,    2,   55,    2, 0x0a /* Public */,
      13,    3,   60,    2, 0x0a /* Public */,
      19,    3,   67,    2, 0x0a /* Public */,
      22,    0,   74,    2, 0x0a /* Public */,
      23,    1,   75,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    5,    7,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 11,   10,   12,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 16, 0x80000000 | 11,   15,   17,   18,
    0x80000000 | 20, 0x80000000 | 14, QMetaType::Float, 0x80000000 | 6,   15,   21,    7,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   24,

       0        // eod
};

void SpecificWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SpecificWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->compute(); break;
        case 1: _t->generarPoligono((*reinterpret_cast< QPolygonF(*)>(_a[1])),(*reinterpret_cast< const RoboCompLaser::TLaserData(*)>(_a[2]))); break;
        case 2: _t->calculoPuntos((*reinterpret_cast< RoboCompGenericBase::TBaseState(*)>(_a[1])),(*reinterpret_cast< std::vector<tupla>(*)>(_a[2]))); break;
        case 3: _t->ordenarPuntos((*reinterpret_cast< std::vector<tupla>(*)>(_a[1])),(*reinterpret_cast< Eigen::Vector2f(*)>(_a[2])),(*reinterpret_cast< std::vector<tupla>(*)>(_a[3]))); break;
        case 4: { std::vector<SpecificWorker::tupla> _r = _t->obstaculos((*reinterpret_cast< std::vector<tupla>(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< const RoboCompLaser::TLaserData(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< std::vector<SpecificWorker::tupla>*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->startup_check();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->initialize((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
