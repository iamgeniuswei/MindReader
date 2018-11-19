/****************************************************************************
** Meta object code from reading C++ file 'mrarticleloader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mrarticleloader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mrarticleloader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MRArticleLoader_t {
    QByteArrayData data[8];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MRArticleLoader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MRArticleLoader_t qt_meta_stringdata_MRArticleLoader = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MRArticleLoader"
QT_MOC_LITERAL(1, 16, 8), // "docReady"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 3), // "ret"
QT_MOC_LITERAL(4, 30, 27), // "std::shared_ptr<MRDocument>"
QT_MOC_LITERAL(5, 58, 3), // "doc"
QT_MOC_LITERAL(6, 62, 10), // "indexReady"
QT_MOC_LITERAL(7, 73, 5) // "items"

    },
    "MRArticleLoader\0docReady\0\0ret\0"
    "std::shared_ptr<MRDocument>\0doc\0"
    "indexReady\0items"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MRArticleLoader[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,
       6,    1,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QStringList,    7,

       0        // eod
};

void MRArticleLoader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MRArticleLoader *_t = static_cast<MRArticleLoader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->docReady((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< std::shared_ptr<MRDocument>(*)>(_a[2]))); break;
        case 1: _t->indexReady((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MRArticleLoader::*)(bool , std::shared_ptr<MRDocument> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MRArticleLoader::docReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MRArticleLoader::*)(const QStringList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MRArticleLoader::indexReady)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MRArticleLoader::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_MRArticleLoader.data,
    qt_meta_data_MRArticleLoader,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MRArticleLoader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MRArticleLoader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MRArticleLoader.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int MRArticleLoader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void MRArticleLoader::docReady(bool _t1, std::shared_ptr<MRDocument> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MRArticleLoader::indexReady(const QStringList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
