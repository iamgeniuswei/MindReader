/****************************************************************************
** Meta object code from reading C++ file 'articledisplayercontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Window/articledisplayercontroller.h"
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
    QByteArrayData data[14];
    char stringdata0[222];
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
QT_MOC_LITERAL(8, 122, 18), // "changeToSinglePage"
QT_MOC_LITERAL(9, 141, 22), // "changeToContinuousPage"
QT_MOC_LITERAL(10, 164, 14), // "updateADCIndex"
QT_MOC_LITERAL(11, 179, 5), // "items"
QT_MOC_LITERAL(12, 185, 15), // "on_page_clicked"
QT_MOC_LITERAL(13, 201, 20) // "on_pageBreak_clicked"

    },
    "ArticleDisplayerController\0firstPageClicked\0"
    "\0prevPageClicked\0nextPageClicked\0"
    "lastPageClicked\0zoomInClicked\0"
    "zoomOutClicked\0changeToSinglePage\0"
    "changeToContinuousPage\0updateADCIndex\0"
    "items\0on_page_clicked\0on_pageBreak_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ArticleDisplayerController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    0,   71,    2, 0x06 /* Public */,
       5,    0,   72,    2, 0x06 /* Public */,
       6,    0,   73,    2, 0x06 /* Public */,
       7,    0,   74,    2, 0x06 /* Public */,
       8,    0,   75,    2, 0x06 /* Public */,
       9,    0,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   77,    2, 0x0a /* Public */,
      12,    0,   80,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,   11,
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
        case 6: _t->changeToSinglePage(); break;
        case 7: _t->changeToContinuousPage(); break;
        case 8: _t->updateADCIndex((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 9: _t->on_page_clicked(); break;
        case 10: _t->on_pageBreak_clicked(); break;
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
            using _t = void (ArticleDisplayerController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArticleDisplayerController::changeToSinglePage)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ArticleDisplayerController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArticleDisplayerController::changeToContinuousPage)) {
                *result = 7;
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
void ArticleDisplayerController::changeToSinglePage()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void ArticleDisplayerController::changeToContinuousPage()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
