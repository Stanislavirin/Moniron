/****************************************************************************
** Meta object code from reading C++ file 'addnewacc.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../addnewacc.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addnewacc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_addNewAcc_t {
    QByteArrayData data[19];
    char stringdata0[363];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_addNewAcc_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_addNewAcc_t qt_meta_stringdata_addNewAcc = {
    {
QT_MOC_LITERAL(0, 0, 9), // "addNewAcc"
QT_MOC_LITERAL(1, 10, 24), // "on_btnAddNewUser_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 28), // "createFileAndRegisterfromDOM"
QT_MOC_LITERAL(4, 65, 35), // "getDocFromTestFileAndSaveInRe..."
QT_MOC_LITERAL(5, 101, 13), // "QDomDocument*"
QT_MOC_LITERAL(6, 115, 16), // "showAccoutsTable"
QT_MOC_LITERAL(7, 132, 13), // "InputDocument"
QT_MOC_LITERAL(8, 146, 30), // "chekTableForPassAndLoginLength"
QT_MOC_LITERAL(9, 177, 16), // "on_btnOk_clicked"
QT_MOC_LITERAL(10, 194, 20), // "on_btnCancel_clicked"
QT_MOC_LITERAL(11, 215, 19), // "on_btnApply_clicked"
QT_MOC_LITERAL(12, 235, 26), // "on_tableWidget_cellChanged"
QT_MOC_LITERAL(13, 262, 3), // "row"
QT_MOC_LITERAL(14, 266, 6), // "column"
QT_MOC_LITERAL(15, 273, 34), // "checkForEmptyRowsAndAdminExis..."
QT_MOC_LITERAL(16, 308, 27), // "writeAdminOrOperatorToTable"
QT_MOC_LITERAL(17, 336, 4), // "text"
QT_MOC_LITERAL(18, 341, 21) // "on_pushButton_clicked"

    },
    "addNewAcc\0on_btnAddNewUser_clicked\0\0"
    "createFileAndRegisterfromDOM\0"
    "getDocFromTestFileAndSaveInRegister\0"
    "QDomDocument*\0showAccoutsTable\0"
    "InputDocument\0chekTableForPassAndLoginLength\0"
    "on_btnOk_clicked\0on_btnCancel_clicked\0"
    "on_btnApply_clicked\0on_tableWidget_cellChanged\0"
    "row\0column\0checkForEmptyRowsAndAdminExistence\0"
    "writeAdminOrOperatorToTable\0text\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_addNewAcc[] = {

 // content:
       8,       // revision
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
       6,    1,   77,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    2,   84,    2, 0x08 /* Private */,
      15,    0,   89,    2, 0x08 /* Private */,
      16,    1,   90,    2, 0x08 /* Private */,
      18,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 5,
    0x80000000 | 5, 0x80000000 | 5,    7,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   13,   14,
    QMetaType::Int,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,

       0        // eod
};

void addNewAcc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<addNewAcc *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnAddNewUser_clicked(); break;
        case 1: _t->createFileAndRegisterfromDOM(); break;
        case 2: { QDomDocument* _r = _t->getDocFromTestFileAndSaveInRegister();
            if (_a[0]) *reinterpret_cast< QDomDocument**>(_a[0]) = std::move(_r); }  break;
        case 3: { QDomDocument* _r = _t->showAccoutsTable((*reinterpret_cast< QDomDocument*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDomDocument**>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->chekTableForPassAndLoginLength();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->on_btnOk_clicked(); break;
        case 6: _t->on_btnCancel_clicked(); break;
        case 7: _t->on_btnApply_clicked(); break;
        case 8: _t->on_tableWidget_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: { int _r = _t->checkForEmptyRowsAndAdminExistence();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->writeAdminOrOperatorToTable((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject addNewAcc::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_addNewAcc.data,
    qt_meta_data_addNewAcc,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *addNewAcc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *addNewAcc::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_addNewAcc.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int addNewAcc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
