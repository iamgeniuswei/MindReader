/****************************************************************************
** Meta object code from reading C++ file 'mrarticlereader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mrarticlereader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mrarticlereader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MRArticleReader_t {
    QByteArrayData data[19];
    char stringdata0[230];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MRArticleReader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MRArticleReader_t qt_meta_stringdata_MRArticleReader = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MRArticleReader"
QT_MOC_LITERAL(1, 16, 14), // "selectionReady"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 4), // "page"
QT_MOC_LITERAL(4, 37, 6), // "pixmap"
QT_MOC_LITERAL(5, 44, 9), // "textReady"
QT_MOC_LITERAL(6, 54, 4), // "text"
QT_MOC_LITERAL(7, 59, 10), // "cursorType"
QT_MOC_LITERAL(8, 70, 6), // "CURSOR"
QT_MOC_LITERAL(9, 77, 6), // "cursor"
QT_MOC_LITERAL(10, 84, 13), // "backToLibrary"
QT_MOC_LITERAL(11, 98, 10), // "setArticle"
QT_MOC_LITERAL(12, 109, 34), // "std::shared_ptr<MRArticleMeta..."
QT_MOC_LITERAL(13, 144, 7), // "article"
QT_MOC_LITERAL(14, 152, 12), // "resetArticle"
QT_MOC_LITERAL(15, 165, 16), // "displayFirstPage"
QT_MOC_LITERAL(16, 182, 15), // "displayPrevPage"
QT_MOC_LITERAL(17, 198, 15), // "displayNextPage"
QT_MOC_LITERAL(18, 214, 15) // "displayLastPage"

    },
    "MRArticleReader\0selectionReady\0\0page\0"
    "pixmap\0textReady\0text\0cursorType\0"
    "CURSOR\0cursor\0backToLibrary\0setArticle\0"
    "std::shared_ptr<MRArticleMetaData>\0"
    "article\0resetArticle\0displayFirstPage\0"
    "displayPrevPage\0displayNextPage\0"
    "displayLastPage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MRArticleReader[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       5,    2,   69,    2, 0x06 /* Public */,
       7,    1,   74,    2, 0x06 /* Public */,
      10,    0,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   78,    2, 0x0a /* Public */,
      14,    0,   81,    2, 0x0a /* Public */,
      15,    0,   82,    2, 0x0a /* Public */,
      16,    0,   83,    2, 0x0a /* Public */,
      17,    0,   84,    2, 0x0a /* Public */,
      18,    0,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QPixmap,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MRArticleReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MRArticleReader *_t = static_cast<MRArticleReader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectionReady((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 1: _t->textReady((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->cursorType((*reinterpret_cast< CURSOR(*)>(_a[1]))); break;
        case 3: _t->backToLibrary(); break;
        case 4: { bool _r = _t->setArticle((*reinterpret_cast< std::shared_ptr<MRArticleMetaData>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->resetArticle(); break;
        case 6: _t->displayFirstPage(); break;
        case 7: _t->displayPrevPage(); break;
        case 8: _t->displayNextPage(); break;
        case 9: _t->displayLastPage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MRArticleReader::*)(int , const QPixmap & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MRArticleReader::selectionReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MRArticleReader::*)(int , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MRArticleReader::textReady)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MRArticleReader::*)(CURSOR );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MRArticleReader::cursorType)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MRArticleReader::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MRArticleReader::backToLibrary)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MRArticleReader::staticMetaObject = { {
    &UIWidget::staticMetaObject,
    qt_meta_stringdata_MRArticleReader.data,
    qt_meta_data_MRArticleReader,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MRArticleReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MRArticleReader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MRArticleReader.stringdata0))
        return static_cast<void*>(this);
    return UIWidget::qt_metacast(_clname);
}

int MRArticleReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = UIWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void MRArticleReader::selectionReady(int _t1, const QPixmap & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MRArticleReader::textReady(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MRArticleReader::cursorType(CURSOR _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MRArticleReader::backToLibrary()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
