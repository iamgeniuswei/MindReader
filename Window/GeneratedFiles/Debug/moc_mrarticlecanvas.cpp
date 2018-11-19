/****************************************************************************
** Meta object code from reading C++ file 'mrarticlecanvas.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mrarticlecanvas.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mrarticlecanvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MRArticleCanvas_t {
    QByteArrayData data[34];
    char stringdata0[341];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MRArticleCanvas_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MRArticleCanvas_t qt_meta_stringdata_MRArticleCanvas = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MRArticleCanvas"
QT_MOC_LITERAL(1, 16, 10), // "imageReady"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 4), // "page"
QT_MOC_LITERAL(4, 33, 6), // "pixmap"
QT_MOC_LITERAL(5, 40, 9), // "textReady"
QT_MOC_LITERAL(6, 50, 4), // "text"
QT_MOC_LITERAL(7, 55, 11), // "cursorReady"
QT_MOC_LITERAL(8, 67, 6), // "CURSOR"
QT_MOC_LITERAL(9, 74, 6), // "cursor"
QT_MOC_LITERAL(10, 81, 10), // "colorReady"
QT_MOC_LITERAL(11, 92, 5), // "color"
QT_MOC_LITERAL(12, 98, 18), // "ADCIndexItemsReady"
QT_MOC_LITERAL(13, 117, 5), // "items"
QT_MOC_LITERAL(14, 123, 9), // "firstPage"
QT_MOC_LITERAL(15, 133, 8), // "prevPage"
QT_MOC_LITERAL(16, 142, 8), // "nextPage"
QT_MOC_LITERAL(17, 151, 8), // "lastPage"
QT_MOC_LITERAL(18, 160, 10), // "zoomInPage"
QT_MOC_LITERAL(19, 171, 11), // "zoomOutPage"
QT_MOC_LITERAL(20, 183, 11), // "displayPage"
QT_MOC_LITERAL(21, 195, 6), // "scaleX"
QT_MOC_LITERAL(22, 202, 6), // "scaleY"
QT_MOC_LITERAL(23, 209, 8), // "rotation"
QT_MOC_LITERAL(24, 218, 5), // "index"
QT_MOC_LITERAL(25, 224, 3), // "img"
QT_MOC_LITERAL(26, 228, 23), // "std::shared_ptr<MRPage>"
QT_MOC_LITERAL(27, 252, 3), // "src"
QT_MOC_LITERAL(28, 256, 14), // "handleDocReady"
QT_MOC_LITERAL(29, 271, 3), // "ret"
QT_MOC_LITERAL(30, 275, 27), // "std::shared_ptr<MRDocument>"
QT_MOC_LITERAL(31, 303, 8), // "document"
QT_MOC_LITERAL(32, 312, 22), // "handleScrollBarChanged"
QT_MOC_LITERAL(33, 335, 5) // "value"

    },
    "MRArticleCanvas\0imageReady\0\0page\0"
    "pixmap\0textReady\0text\0cursorReady\0"
    "CURSOR\0cursor\0colorReady\0color\0"
    "ADCIndexItemsReady\0items\0firstPage\0"
    "prevPage\0nextPage\0lastPage\0zoomInPage\0"
    "zoomOutPage\0displayPage\0scaleX\0scaleY\0"
    "rotation\0index\0img\0std::shared_ptr<MRPage>\0"
    "src\0handleDocReady\0ret\0"
    "std::shared_ptr<MRDocument>\0document\0"
    "handleScrollBarChanged\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MRArticleCanvas[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x06 /* Public */,
       5,    2,   89,    2, 0x06 /* Public */,
       7,    1,   94,    2, 0x06 /* Public */,
      10,    1,   97,    2, 0x06 /* Public */,
      12,    1,  100,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  103,    2, 0x0a /* Public */,
      15,    0,  104,    2, 0x0a /* Public */,
      16,    0,  105,    2, 0x0a /* Public */,
      17,    0,  106,    2, 0x0a /* Public */,
      18,    0,  107,    2, 0x0a /* Public */,
      19,    0,  108,    2, 0x0a /* Public */,
      20,    6,  109,    2, 0x0a /* Public */,
      28,    2,  122,    2, 0x08 /* Private */,
      32,    1,  127,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QPixmap,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QColor,   11,
    QMetaType::Void, QMetaType::QStringList,   13,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Int, QMetaType::QImage, 0x80000000 | 26,   21,   22,   23,   24,   25,   27,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 30,   29,   31,
    QMetaType::Void, QMetaType::Int,   33,

       0        // eod
};

void MRArticleCanvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MRArticleCanvas *_t = static_cast<MRArticleCanvas *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->imageReady((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 1: _t->textReady((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->cursorReady((*reinterpret_cast< CURSOR(*)>(_a[1]))); break;
        case 3: _t->colorReady((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 4: _t->ADCIndexItemsReady((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 5: _t->firstPage(); break;
        case 6: _t->prevPage(); break;
        case 7: _t->nextPage(); break;
        case 8: _t->lastPage(); break;
        case 9: _t->zoomInPage(); break;
        case 10: _t->zoomOutPage(); break;
        case 11: _t->displayPage((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QImage(*)>(_a[5])),(*reinterpret_cast< std::shared_ptr<MRPage>(*)>(_a[6]))); break;
        case 12: _t->handleDocReady((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< std::shared_ptr<MRDocument>(*)>(_a[2]))); break;
        case 13: _t->handleScrollBarChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MRArticleCanvas::*)(int , const QPixmap & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MRArticleCanvas::imageReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MRArticleCanvas::*)(int , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MRArticleCanvas::textReady)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MRArticleCanvas::*)(CURSOR );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MRArticleCanvas::cursorReady)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MRArticleCanvas::*)(const QColor & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MRArticleCanvas::colorReady)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MRArticleCanvas::*)(const QStringList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MRArticleCanvas::ADCIndexItemsReady)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MRArticleCanvas::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_MRArticleCanvas.data,
    qt_meta_data_MRArticleCanvas,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MRArticleCanvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MRArticleCanvas::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MRArticleCanvas.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MRArticleCanvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MRArticleCanvas::imageReady(int _t1, const QPixmap & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MRArticleCanvas::textReady(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MRArticleCanvas::cursorReady(CURSOR _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MRArticleCanvas::colorReady(const QColor & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MRArticleCanvas::ADCIndexItemsReady(const QStringList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
