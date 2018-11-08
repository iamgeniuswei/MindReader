/****************************************************************************
** Meta object code from reading C++ file 'mrarticledisplayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Window/mrarticledisplayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mrarticledisplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MRArticleDisplayer_t {
    QByteArrayData data[19];
    char stringdata0[213];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MRArticleDisplayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MRArticleDisplayer_t qt_meta_stringdata_MRArticleDisplayer = {
    {
QT_MOC_LITERAL(0, 0, 18), // "MRArticleDisplayer"
QT_MOC_LITERAL(1, 19, 14), // "selectionReady"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 4), // "page"
QT_MOC_LITERAL(4, 40, 6), // "pixmap"
QT_MOC_LITERAL(5, 47, 9), // "textReady"
QT_MOC_LITERAL(6, 57, 4), // "text"
QT_MOC_LITERAL(7, 62, 10), // "cursorType"
QT_MOC_LITERAL(8, 73, 6), // "CURSOR"
QT_MOC_LITERAL(9, 80, 6), // "cursor"
QT_MOC_LITERAL(10, 87, 18), // "ADCIndexItemsReady"
QT_MOC_LITERAL(11, 106, 5), // "items"
QT_MOC_LITERAL(12, 112, 16), // "displayFirstPage"
QT_MOC_LITERAL(13, 129, 15), // "displayPrevPage"
QT_MOC_LITERAL(14, 145, 15), // "displayNextPage"
QT_MOC_LITERAL(15, 161, 15), // "displayLastPage"
QT_MOC_LITERAL(16, 177, 10), // "zoomInPage"
QT_MOC_LITERAL(17, 188, 11), // "zoomOutPage"
QT_MOC_LITERAL(18, 200, 12) // "resetArticle"

    },
    "MRArticleDisplayer\0selectionReady\0\0"
    "page\0pixmap\0textReady\0text\0cursorType\0"
    "CURSOR\0cursor\0ADCIndexItemsReady\0items\0"
    "displayFirstPage\0displayPrevPage\0"
    "displayNextPage\0displayLastPage\0"
    "zoomInPage\0zoomOutPage\0resetArticle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MRArticleDisplayer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       5,    2,   74,    2, 0x06 /* Public */,
       7,    1,   79,    2, 0x06 /* Public */,
      10,    1,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   85,    2, 0x0a /* Public */,
      13,    0,   86,    2, 0x0a /* Public */,
      14,    0,   87,    2, 0x0a /* Public */,
      15,    0,   88,    2, 0x0a /* Public */,
      16,    0,   89,    2, 0x0a /* Public */,
      17,    0,   90,    2, 0x0a /* Public */,
      18,    0,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QPixmap,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QStringList,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MRArticleDisplayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MRArticleDisplayer *_t = static_cast<MRArticleDisplayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectionReady((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 1: _t->textReady((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->cursorType((*reinterpret_cast< CURSOR(*)>(_a[1]))); break;
        case 3: _t->ADCIndexItemsReady((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 4: _t->displayFirstPage(); break;
        case 5: _t->displayPrevPage(); break;
        case 6: _t->displayNextPage(); break;
        case 7: _t->displayLastPage(); break;
        case 8: _t->zoomInPage(); break;
        case 9: _t->zoomOutPage(); break;
        case 10: _t->resetArticle(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MRArticleDisplayer::*)(int , const QPixmap & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MRArticleDisplayer::selectionReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MRArticleDisplayer::*)(int , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MRArticleDisplayer::textReady)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MRArticleDisplayer::*)(CURSOR );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MRArticleDisplayer::cursorType)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MRArticleDisplayer::*)(const QStringList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MRArticleDisplayer::ADCIndexItemsReady)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MRArticleDisplayer::staticMetaObject = { {
    &QScrollArea::staticMetaObject,
    qt_meta_stringdata_MRArticleDisplayer.data,
    qt_meta_data_MRArticleDisplayer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MRArticleDisplayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MRArticleDisplayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MRArticleDisplayer.stringdata0))
        return static_cast<void*>(this);
    return QScrollArea::qt_metacast(_clname);
}

int MRArticleDisplayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MRArticleDisplayer::selectionReady(int _t1, const QPixmap & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MRArticleDisplayer::textReady(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MRArticleDisplayer::cursorType(CURSOR _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MRArticleDisplayer::ADCIndexItemsReady(const QStringList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
