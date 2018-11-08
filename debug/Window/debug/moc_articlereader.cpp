/****************************************************************************
** Meta object code from reading C++ file 'articlereader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Window/articlereader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'articlereader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ArticleReader_t {
    QByteArrayData data[14];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ArticleReader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ArticleReader_t qt_meta_stringdata_ArticleReader = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ArticleReader"
QT_MOC_LITERAL(1, 14, 14), // "selectionReady"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 4), // "page"
QT_MOC_LITERAL(4, 35, 6), // "pixmap"
QT_MOC_LITERAL(5, 42, 9), // "textReady"
QT_MOC_LITERAL(6, 52, 4), // "text"
QT_MOC_LITERAL(7, 57, 10), // "cursorType"
QT_MOC_LITERAL(8, 68, 6), // "CURSOR"
QT_MOC_LITERAL(9, 75, 6), // "cursor"
QT_MOC_LITERAL(10, 82, 10), // "setArticle"
QT_MOC_LITERAL(11, 93, 34), // "std::shared_ptr<MRArticleMeta..."
QT_MOC_LITERAL(12, 128, 7), // "article"
QT_MOC_LITERAL(13, 136, 12) // "resetArticle"

    },
    "ArticleReader\0selectionReady\0\0page\0"
    "pixmap\0textReady\0text\0cursorType\0"
    "CURSOR\0cursor\0setArticle\0"
    "std::shared_ptr<MRArticleMetaData>\0"
    "article\0resetArticle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ArticleReader[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       5,    2,   44,    2, 0x06 /* Public */,
       7,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   52,    2, 0x0a /* Public */,
      13,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QPixmap,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    6,
    QMetaType::Void, 0x80000000 | 8,    9,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 11,   12,
    QMetaType::Void,

       0        // eod
};

void ArticleReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ArticleReader *_t = static_cast<ArticleReader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectionReady((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 1: _t->textReady((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->cursorType((*reinterpret_cast< CURSOR(*)>(_a[1]))); break;
        case 3: { bool _r = _t->setArticle((*reinterpret_cast< std::shared_ptr<MRArticleMetaData>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->resetArticle(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ArticleReader::*)(int , const QPixmap & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArticleReader::selectionReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ArticleReader::*)(int , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArticleReader::textReady)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ArticleReader::*)(CURSOR );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArticleReader::cursorType)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ArticleReader::staticMetaObject = { {
    &UIWidget::staticMetaObject,
    qt_meta_stringdata_ArticleReader.data,
    qt_meta_data_ArticleReader,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ArticleReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ArticleReader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ArticleReader.stringdata0))
        return static_cast<void*>(this);
    return UIWidget::qt_metacast(_clname);
}

int ArticleReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = UIWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ArticleReader::selectionReady(int _t1, const QPixmap & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ArticleReader::textReady(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ArticleReader::cursorType(CURSOR _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
