/****************************************************************************
** Meta object code from reading C++ file 'connectionobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../connectionobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connectionobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConnectionObject_t {
    QByteArrayData data[13];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConnectionObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConnectionObject_t qt_meta_stringdata_ConnectionObject = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ConnectionObject"
QT_MOC_LITERAL(1, 17, 8), // "finished"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "runningChanged"
QT_MOC_LITERAL(4, 42, 7), // "running"
QT_MOC_LITERAL(5, 50, 14), // "messageChanged"
QT_MOC_LITERAL(6, 65, 7), // "message"
QT_MOC_LITERAL(7, 73, 17), // "ShowYesConnection"
QT_MOC_LITERAL(8, 91, 16), // "ShowNoConnection"
QT_MOC_LITERAL(9, 108, 3), // "run"
QT_MOC_LITERAL(10, 112, 10), // "setRunning"
QT_MOC_LITERAL(11, 123, 10), // "setMessage"
QT_MOC_LITERAL(12, 134, 7) // "Connect"

    },
    "ConnectionObject\0finished\0\0runningChanged\0"
    "running\0messageChanged\0message\0"
    "ShowYesConnection\0ShowNoConnection\0"
    "run\0setRunning\0setMessage\0Connect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConnectionObject[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       2,   76, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    1,   60,    2, 0x06 /* Public */,
       5,    1,   63,    2, 0x06 /* Public */,
       7,    0,   66,    2, 0x06 /* Public */,
       8,    0,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   68,    2, 0x0a /* Public */,
      10,    1,   69,    2, 0x0a /* Public */,
      11,    1,   72,    2, 0x0a /* Public */,
      12,    0,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

 // properties: name, type, flags
       4, QMetaType::Bool, 0x00495103,
       6, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       1,
       2,

       0        // eod
};

void ConnectionObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConnectionObject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->runningChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->messageChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->ShowYesConnection(); break;
        case 4: _t->ShowNoConnection(); break;
        case 5: _t->run(); break;
        case 6: _t->setRunning((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->setMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->Connect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ConnectionObject::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConnectionObject::finished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ConnectionObject::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConnectionObject::runningChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ConnectionObject::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConnectionObject::messageChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ConnectionObject::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConnectionObject::ShowYesConnection)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ConnectionObject::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConnectionObject::ShowNoConnection)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ConnectionObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->running(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->message(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ConnectionObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRunning(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setMessage(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ConnectionObject::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ConnectionObject.data,
    qt_meta_data_ConnectionObject,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ConnectionObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConnectionObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConnectionObject.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ConnectionObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ConnectionObject::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ConnectionObject::runningChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ConnectionObject::messageChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ConnectionObject::ShowYesConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ConnectionObject::ShowNoConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
