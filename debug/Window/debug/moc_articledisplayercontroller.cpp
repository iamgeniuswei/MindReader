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
    QByteArrayData data[8];
    char stringdata0[122];
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
QT_MOC_LITERAL(7, 107, 14) // "zoomOutClicked"

    },
    "ArticleDisplayerController\0firstPageClicked\0"
    "\0prevPageClicked\0nextPageClicked\0"
    "lastPageClicked\0zoomInClicked\0"
    "zoomOutClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ArticleDisplayerController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,
       6,    0,   48,    2, 0x06 /* Public */,
       7,    0,   49,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
    }
    Q_UNUSED(_a);
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
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
