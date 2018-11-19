/****************************************************************************
** Meta object code from reading C++ file 'mrsinglepagedisplayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mrsinglepagedisplayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mrsinglepagedisplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MRSinglePageDisplayer_t {
    QByteArrayData data[20];
    char stringdata0[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MRSinglePageDisplayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MRSinglePageDisplayer_t qt_meta_stringdata_MRSinglePageDisplayer = {
    {
QT_MOC_LITERAL(0, 0, 21), // "MRSinglePageDisplayer"
QT_MOC_LITERAL(1, 22, 14), // "handleDocReady"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 3), // "ret"
QT_MOC_LITERAL(4, 42, 27), // "std::shared_ptr<MRDocument>"
QT_MOC_LITERAL(5, 70, 8), // "document"
QT_MOC_LITERAL(6, 79, 9), // "firstPage"
QT_MOC_LITERAL(7, 89, 8), // "prevPage"
QT_MOC_LITERAL(8, 98, 8), // "nextPage"
QT_MOC_LITERAL(9, 107, 8), // "lastPage"
QT_MOC_LITERAL(10, 116, 10), // "zoomInPage"
QT_MOC_LITERAL(11, 127, 11), // "zoomOutPage"
QT_MOC_LITERAL(12, 139, 11), // "displayPage"
QT_MOC_LITERAL(13, 151, 6), // "scaleX"
QT_MOC_LITERAL(14, 158, 6), // "scaleY"
QT_MOC_LITERAL(15, 165, 8), // "rotation"
QT_MOC_LITERAL(16, 174, 5), // "index"
QT_MOC_LITERAL(17, 180, 3), // "img"
QT_MOC_LITERAL(18, 184, 23), // "std::shared_ptr<MRPage>"
QT_MOC_LITERAL(19, 208, 3) // "src"

    },
    "MRSinglePageDisplayer\0handleDocReady\0"
    "\0ret\0std::shared_ptr<MRDocument>\0"
    "document\0firstPage\0prevPage\0nextPage\0"
    "lastPage\0zoomInPage\0zoomOutPage\0"
    "displayPage\0scaleX\0scaleY\0rotation\0"
    "index\0img\0std::shared_ptr<MRPage>\0src"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MRSinglePageDisplayer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x0a /* Public */,
       6,    0,   59,    2, 0x0a /* Public */,
       7,    0,   60,    2, 0x0a /* Public */,
       8,    0,   61,    2, 0x0a /* Public */,
       9,    0,   62,    2, 0x0a /* Public */,
      10,    0,   63,    2, 0x0a /* Public */,
      11,    0,   64,    2, 0x0a /* Public */,
      12,    6,   65,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4,    3,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Int, QMetaType::QImage, 0x80000000 | 18,   13,   14,   15,   16,   17,   19,

       0        // eod
};

void MRSinglePageDisplayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MRSinglePageDisplayer *_t = static_cast<MRSinglePageDisplayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleDocReady((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< std::shared_ptr<MRDocument>(*)>(_a[2]))); break;
        case 1: _t->firstPage(); break;
        case 2: _t->prevPage(); break;
        case 3: _t->nextPage(); break;
        case 4: _t->lastPage(); break;
        case 5: _t->zoomInPage(); break;
        case 6: _t->zoomOutPage(); break;
        case 7: _t->displayPage((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QImage(*)>(_a[5])),(*reinterpret_cast< std::shared_ptr<MRPage>(*)>(_a[6]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MRSinglePageDisplayer::staticMetaObject = { {
    &MRArticleCanvas::staticMetaObject,
    qt_meta_stringdata_MRSinglePageDisplayer.data,
    qt_meta_data_MRSinglePageDisplayer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MRSinglePageDisplayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MRSinglePageDisplayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MRSinglePageDisplayer.stringdata0))
        return static_cast<void*>(this);
    return MRArticleCanvas::qt_metacast(_clname);
}

int MRSinglePageDisplayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MRArticleCanvas::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
