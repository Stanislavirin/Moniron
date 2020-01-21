/****************************************************************************
** Meta object code from reading C++ file 'videostreamobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../videostreamobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videostreamobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VideoStreamObject_t {
    QByteArrayData data[11];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoStreamObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoStreamObject_t qt_meta_stringdata_VideoStreamObject = {
    {
QT_MOC_LITERAL(0, 0, 17), // "VideoStreamObject"
QT_MOC_LITERAL(1, 18, 8), // "finished"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14), // "runningChanged"
QT_MOC_LITERAL(4, 43, 7), // "running"
QT_MOC_LITERAL(5, 51, 14), // "messageChanged"
QT_MOC_LITERAL(6, 66, 3), // "WId"
QT_MOC_LITERAL(7, 70, 8), // "widgetID"
QT_MOC_LITERAL(8, 79, 3), // "run"
QT_MOC_LITERAL(9, 83, 10), // "setRunning"
QT_MOC_LITERAL(10, 94, 10) // "setMessage"

    },
    "VideoStreamObject\0finished\0\0runningChanged\0"
    "running\0messageChanged\0WId\0widgetID\0"
    "run\0setRunning\0setMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoStreamObject[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       2,   58, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,
       5,    1,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   51,    2, 0x0a /* Public */,
       9,    1,   52,    2, 0x0a /* Public */,
      10,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // properties: name, type, flags
       4, QMetaType::Bool, 0x00495103,
       7, 0x80000000 | 6, 0x0049500b,

 // properties: notify_signal_id
       1,
       2,

       0        // eod
};

void VideoStreamObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VideoStreamObject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->runningChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->messageChanged((*reinterpret_cast< WId(*)>(_a[1]))); break;
        case 3: _t->run(); break;
        case 4: _t->setRunning((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->setMessage((*reinterpret_cast< WId(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VideoStreamObject::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoStreamObject::finished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VideoStreamObject::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoStreamObject::runningChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (VideoStreamObject::*)(WId );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoStreamObject::messageChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<VideoStreamObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->running(); break;
        case 1: *reinterpret_cast< WId*>(_v) = _t->message(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<VideoStreamObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRunning(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setMessage(*reinterpret_cast< WId*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject VideoStreamObject::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_VideoStreamObject.data,
    qt_meta_data_VideoStreamObject,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VideoStreamObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoStreamObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VideoStreamObject.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int VideoStreamObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void VideoStreamObject::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VideoStreamObject::runningChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VideoStreamObject::messageChanged(WId _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
