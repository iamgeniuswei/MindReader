/****************************************************************************
** Meta object code from reading C++ file 'mrreadertoolbar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Window/mrreadertoolbar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mrreadertoolbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MRReaderToolBar_t {
    QByteArrayData data[12];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MRReaderToolBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MRReaderToolBar_t qt_meta_stringdata_MRReaderToolBar = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MRReaderToolBar"
QT_MOC_LITERAL(1, 16, 15), // "hideNoteClicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 18), // "backLibraryClicked"
QT_MOC_LITERAL(4, 52, 10), // "cursorType"
QT_MOC_LITERAL(5, 63, 6), // "CURSOR"
QT_MOC_LITERAL(6, 70, 6), // "cursor"
QT_MOC_LITERAL(7, 77, 15), // "on_hand_clicked"
QT_MOC_LITERAL(8, 93, 17), // "on_select_clicked"
QT_MOC_LITERAL(9, 111, 15), // "on_line_clicked"
QT_MOC_LITERAL(10, 127, 20), // "on_rectangle_clicked"
QT_MOC_LITERAL(11, 148, 15) // "on_text_clicked"

    },
    "MRReaderToolBar\0hideNoteClicked\0\0"
    "backLibraryClicked\0cursorType\0CURSOR\0"
    "cursor\0on_hand_clicked\0on_select_clicked\0"
    "on_line_clicked\0on_rectangle_clicked\0"
    "on_text_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MRReaderToolBar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    1,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,
      10,    0,   62,    2, 0x08 /* Private */,
      11,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MRReaderToolBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MRReaderToolBar *_t = static_cast<MRReaderToolBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->hideNoteClicked(); break;
        case 1: _t->backLibraryClicked(); break;
        case 2: _t->cursorType((*reinterpret_cast< CURSOR(*)>(_a[1]))); break;
        case 3: _t->on_hand_clicked(); break;
        case 4: _t->on_select_clicked(); break;
        case 5: _t->on_line_clicked(); break;
        case 6: _t->on_rectangle_clicked(); break;
        case 7: _t->on_text_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MRReaderToolBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MRReaderToolBar::hideNoteClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MRReaderToolBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MRReaderToolBar::backLibraryClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MRReaderToolBar::*)(CURSOR );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MRReaderToolBar::cursorType)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MRReaderToolBar::staticMetaObject = { {
    &UIWidget::staticMetaObject,
    qt_meta_stringdata_MRReaderToolBar.data,
    qt_meta_data_MRReaderToolBar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MRReaderToolBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MRReaderToolBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MRReaderToolBar.stringdata0))
        return static_cast<void*>(this);
    return UIWidget::qt_metacast(_clname);
}

int MRReaderToolBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = UIWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void MRReaderToolBar::hideNoteClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MRReaderToolBar::backLibraryClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MRReaderToolBar::cursorType(CURSOR _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
