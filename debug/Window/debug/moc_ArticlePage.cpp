/****************************************************************************
** Meta object code from reading C++ file 'ArticlePage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Window/ArticlePage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ArticlePage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MRArticlePageDisplayer_t {
    QByteArrayData data[10];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MRArticlePageDisplayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MRArticlePageDisplayer_t qt_meta_stringdata_MRArticlePageDisplayer = {
    {
QT_MOC_LITERAL(0, 0, 22), // "MRArticlePageDisplayer"
QT_MOC_LITERAL(1, 23, 14), // "selectionReady"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 4), // "page"
QT_MOC_LITERAL(4, 44, 6), // "pixmap"
QT_MOC_LITERAL(5, 51, 9), // "textReady"
QT_MOC_LITERAL(6, 61, 4), // "text"
QT_MOC_LITERAL(7, 66, 16), // "handleCursorType"
QT_MOC_LITERAL(8, 83, 6), // "CURSOR"
QT_MOC_LITERAL(9, 90, 6) // "cursor"

    },
    "MRArticlePageDisplayer\0selectionReady\0"
    "\0page\0pixmap\0textReady\0text\0"
    "handleCursorType\0CURSOR\0cursor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MRArticlePageDisplayer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       5,    2,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QPixmap,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void MRArticlePageDisplayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MRArticlePageDisplayer *_t = static_cast<MRArticlePageDisplayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectionReady((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 1: _t->textReady((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->handleCursorType((*reinterpret_cast< CURSOR(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MRArticlePageDisplayer::*)(int , const QPixmap & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MRArticlePageDisplayer::selectionReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MRArticlePageDisplayer::*)(int , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MRArticlePageDisplayer::textReady)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MRArticlePageDisplayer::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_MRArticlePageDisplayer.data,
    qt_meta_data_MRArticlePageDisplayer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MRArticlePageDisplayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MRArticlePageDisplayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MRArticlePageDisplayer.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int MRArticlePageDisplayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MRArticlePageDisplayer::selectionReady(int _t1, const QPixmap & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MRArticlePageDisplayer::textReady(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
