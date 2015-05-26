/****************************************************************************
** Meta object code from reading C++ file 'imgur.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../imgur.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imgur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Imgur_t {
    QByteArrayData data[14];
    char stringdata[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Imgur_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Imgur_t qt_meta_stringdata_Imgur = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Imgur"
QT_MOC_LITERAL(1, 6, 15), // "changedClientID"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "changedUrl"
QT_MOC_LITERAL(4, 34, 13), // "finishedQuery"
QT_MOC_LITERAL(5, 48, 5), // "QUrl&"
QT_MOC_LITERAL(6, 54, 12), // "requestFired"
QT_MOC_LITERAL(7, 67, 11), // "setClientID"
QT_MOC_LITERAL(8, 79, 2), // "id"
QT_MOC_LITERAL(9, 82, 6), // "setUrl"
QT_MOC_LITERAL(10, 89, 3), // "url"
QT_MOC_LITERAL(11, 93, 10), // "onResponse"
QT_MOC_LITERAL(12, 104, 14), // "QNetworkReply*"
QT_MOC_LITERAL(13, 119, 5) // "reply"

    },
    "Imgur\0changedClientID\0\0changedUrl\0"
    "finishedQuery\0QUrl&\0requestFired\0"
    "setClientID\0id\0setUrl\0url\0onResponse\0"
    "QNetworkReply*\0reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Imgur[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    1,   52,    2, 0x06 /* Public */,
       4,    1,   55,    2, 0x06 /* Public */,
       6,    0,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   59,    2, 0x0a /* Public */,
       9,    1,   62,    2, 0x0a /* Public */,
      11,    1,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void Imgur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Imgur *_t = static_cast<Imgur *>(_o);
        switch (_id) {
        case 0: _t->changedClientID((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->changedUrl((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->finishedQuery((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 3: _t->requestFired(); break;
        case 4: _t->setClientID((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->setUrl((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->onResponse((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Imgur::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Imgur::changedClientID)) {
                *result = 0;
            }
        }
        {
            typedef void (Imgur::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Imgur::changedUrl)) {
                *result = 1;
            }
        }
        {
            typedef void (Imgur::*_t)(QUrl & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Imgur::finishedQuery)) {
                *result = 2;
            }
        }
        {
            typedef void (Imgur::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Imgur::requestFired)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Imgur::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Imgur.data,
      qt_meta_data_Imgur,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Imgur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Imgur::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Imgur.stringdata))
        return static_cast<void*>(const_cast< Imgur*>(this));
    return QObject::qt_metacast(_clname);
}

int Imgur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Imgur::changedClientID(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Imgur::changedUrl(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Imgur::finishedQuery(QUrl & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Imgur::requestFired()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
