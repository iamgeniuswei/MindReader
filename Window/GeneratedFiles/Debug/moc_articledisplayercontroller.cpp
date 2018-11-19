/****************************************************************************
** Meta object code from reading C++ file 'articledisplayercontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../articledisplayercontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'articledisplayercontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ArticleDisplayerController_t {
    QByteArrayData data[15];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ArticleDisplayerController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ArticleDisplayerController_t qt_meta_stringdata_ArticleDisplayerController = {
    {
QT_MOC_LITERAL(0, 0, 26), // "ArticleDisplayerController"
QT_MOC_LITERAL(1, 27, 16), // "firstPageClicked"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 15), // "prevPageClicked"
QT_MOC_LITERAL(4, 61, 15), // "nextPageClicked"
QT_MOC_LITERAL(5, 77, 15), // "lastPageClicked"
QT_MOC_LITERAL(6, 93, 13), // "zoomInClicked"
QT_MOC_LITERAL(7, 107, 14), // "zoomOutClicked"
QT_MOC_LITERAL(8, 122, 14), // "changePageForm"
QT_MOC_LITERAL(9, 137, 8), // "PAGEFORM"
QT_MOC_LITERAL(10, 146, 4), // "form"
QT_MOC_LITERAL(11, 151, 14), // "updateADCIndex"
QT_MOC_LITERAL(12, 166, 5), // "items"
QT_MOC_LITERAL(13, 172, 15), // "on_page_clicked"
QT_MOC_LITERAL(14, 188, 20) // "on_pageBreak_clicked"

    },
    "ArticleDisplayerController\0firstPageClicked\0"
    "\0prevPageClicked\0nextPageClicked\0"
    "lastPageClicked\0zoomInClicked\0"
    "zoomOutClicked\0changePageForm\0PAGEFORM\0"
    "form\0updateADCIndex\0items\0on_page_clicked\0"
    "on_pageBreak_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ArticleDisplayerController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,
       6,    0,   68,    2, 0x06 /* Public */,
       7,    0,   69,    2, 0x06 /* Public */,
       8,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   73,    2, 0x0a /* Public */,
      13,    0,   76,    2, 0x08 /* Private */,
      14,    0,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ArticleDisplayerController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ArticleDisplayerController *_t = static_cast<ArticleDisplayerController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->firstPageClicked(); break;
        case 1: _t->prevPageClicked(); break;
        case 2: _t->nextPageClicked(); break;
        case 3: _t->lastPageClicked(); break;
        case 4: _t->zoomInClicked(); break;
        case 5: _t->zoomOutClicked(); break;
        case 6: _t->changePageForm((*reinterpret_cast< PAGEFORM(*)>(_a[1]))); break;
        case 7: _t->updateADCIndex((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 8: _t->on_page_clicked(); break;
        case 9: _t->on_pageBreak_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ArticleDisplayerController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArticleDisplayerController::firstPageClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ArticleDisplayerController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArticleDisplayerController::prevPageClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ArticleDisplayerController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArticleDisplayerController::nextPageClicked)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ArticleDisplayerController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArticleDisplayerController::lastPageClicked)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ArticleDisplayerController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArticleDisplayerController::zoomInClicked)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ArticleDisplayerController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArticleDisplayerController::zoomOutClicked)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ArticleDisplayerController::*)(PAGEFORM );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArticleDisplayerController::changePageForm)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ArticleDisplayerController::staticMetaObject = { {
    &UIWidget::staticMetaObject,
    qt_meta_stringdata_ArticleDisplayerController.data,
    qt_meta_data_ArticleDisplayerController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ArticleDisplayerController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ArticleDisplayerController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ArticleDisplayerController.stringdata0))
        return static_cast<void*>(this);
    return UIWidget::qt_metacast(_clname);
}

int ArticleDisplayerController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ArticleDisplayerController::firstPageClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ArticleDisplayerController::prevPageClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ArticleDisplayerController::nextPageClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ArticleDisplayerController::lastPageClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ArticleDisplayerController::zoomInClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ArticleDisplayerController::zoomOutClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ArticleDisplayerController::changePageForm(PAGEFORM _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
