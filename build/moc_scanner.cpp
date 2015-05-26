/****************************************************************************
** Meta object code from reading C++ file 'scanner.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../scanner.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scanner.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Scanner_t {
    QByteArrayData data[20];
    char stringdata[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Scanner_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Scanner_t qt_meta_stringdata_Scanner = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Scanner"
QT_MOC_LITERAL(1, 8, 10), // "onDownload"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 14), // "QNetworkReply*"
QT_MOC_LITERAL(4, 35, 5), // "reply"
QT_MOC_LITERAL(5, 41, 13), // "BeginDownload"
QT_MOC_LITERAL(6, 55, 8), // "onReddit"
QT_MOC_LITERAL(7, 64, 11), // "QJsonArray&"
QT_MOC_LITERAL(8, 76, 7), // "onImgur"
QT_MOC_LITERAL(9, 84, 5), // "QUrl&"
QT_MOC_LITERAL(10, 90, 13), // "recordRequest"
QT_MOC_LITERAL(11, 104, 6), // "setUrl"
QT_MOC_LITERAL(12, 111, 3), // "url"
QT_MOC_LITERAL(13, 115, 8), // "setLimit"
QT_MOC_LITERAL(14, 124, 5), // "limit"
QT_MOC_LITERAL(15, 130, 11), // "setClientID"
QT_MOC_LITERAL(16, 142, 2), // "id"
QT_MOC_LITERAL(17, 145, 7), // "setPath"
QT_MOC_LITERAL(18, 153, 4), // "path"
QT_MOC_LITERAL(19, 158, 4) // "scan"

    },
    "Scanner\0onDownload\0\0QNetworkReply*\0"
    "reply\0BeginDownload\0onReddit\0QJsonArray&\0"
    "onImgur\0QUrl&\0recordRequest\0setUrl\0"
    "url\0setLimit\0limit\0setClientID\0id\0"
    "setPath\0path\0scan"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Scanner[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    1,   73,    2, 0x08 /* Private */,
       8,    1,   76,    2, 0x08 /* Private */,
      10,    0,   79,    2, 0x08 /* Private */,
      11,    1,   80,    2, 0x0a /* Public */,
      13,    1,   83,    2, 0x0a /* Public */,
      15,    1,   86,    2, 0x0a /* Public */,
      17,    1,   89,    2, 0x0a /* Public */,
      19,    0,   92,    2, 0x0a /* Public */,
      19,    1,   93,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,

       0        // eod
};

void Scanner::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Scanner *_t = static_cast<Scanner *>(_o);
        switch (_id) {
        case 0: _t->onDownload((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 1: _t->BeginDownload(); break;
        case 2: _t->onReddit((*reinterpret_cast< QJsonArray(*)>(_a[1]))); break;
        case 3: _t->onImgur((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 4: _t->recordRequest(); break;
        case 5: _t->setUrl((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 6: _t->setLimit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setClientID((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->setPath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->scan(); break;
        case 10: _t->scan((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject Scanner::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Scanner.data,
      qt_meta_data_Scanner,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Scanner::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Scanner::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Scanner.stringdata))
        return static_cast<void*>(const_cast< Scanner*>(this));
    return QObject::qt_metacast(_clname);
}

int Scanner::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
