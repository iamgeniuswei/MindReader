/****************************************************************************
** Meta object code from reading C++ file 'notedisplayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Window/notedisplayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notedisplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NoteDisplayer_t {
    QByteArrayData data[9];
    char stringdata0[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NoteDisplayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NoteDisplayer_t qt_meta_stringdata_NoteDisplayer = {
    {
QT_MOC_LITERAL(0, 0, 13), // "NoteDisplayer"
QT_MOC_LITERAL(1, 14, 7), // "addCard"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "index"
QT_MOC_LITERAL(4, 29, 4), // "text"
QT_MOC_LITERAL(5, 34, 5), // "title"
QT_MOC_LITERAL(6, 40, 11), // "addTextCard"
QT_MOC_LITERAL(7, 52, 13), // "addPixmapCard"
QT_MOC_LITERAL(8, 66, 6) // "pixmap"

    },
    "NoteDisplayer\0addCard\0\0index\0text\0"
    "title\0addTextCard\0addPixmapCard\0pixmap"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NoteDisplayer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x0a /* Public */,
       1,    2,   41,    2, 0x2a /* Public | MethodCloned */,
       6,    2,   46,    2, 0x0a /* Public */,
       7,    2,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QPixmap,    3,    8,

       0        // eod
};

void NoteDisplayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NoteDisplayer *_t = static_cast<NoteDisplayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addCard((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: _t->addCard((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->addTextCard((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->addPixmapCard((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NoteDisplayer::staticMetaObject = { {
    &QScrollArea::staticMetaObject,
    qt_meta_stringdata_NoteDisplayer.data,
    qt_meta_data_NoteDisplayer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NoteDisplayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NoteDisplayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NoteDisplayer.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "WidgetInterface"))
        return static_cast< WidgetInterface*>(this);
    return QScrollArea::qt_metacast(_clname);
}

int NoteDisplayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
