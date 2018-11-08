/****************************************************************************
** Meta object code from reading C++ file 'mrlibrarytree.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Window/mrlibrarytree.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mrlibrarytree.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MRLibraryTree_t {
    QByteArrayData data[12];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MRLibraryTree_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MRLibraryTree_t qt_meta_stringdata_MRLibraryTree = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MRLibraryTree"
QT_MOC_LITERAL(1, 14, 16), // "showArticleInDir"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 12), // "relative_dir"
QT_MOC_LITERAL(4, 45, 9), // "addFolder"
QT_MOC_LITERAL(5, 55, 4), // "name"
QT_MOC_LITERAL(6, 60, 22), // "on_articleTree_clicked"
QT_MOC_LITERAL(7, 83, 11), // "QModelIndex"
QT_MOC_LITERAL(8, 95, 5), // "index"
QT_MOC_LITERAL(9, 101, 14), // "getRelativeDir"
QT_MOC_LITERAL(10, 116, 14), // "QStandardItem*"
QT_MOC_LITERAL(11, 131, 4) // "item"

    },
    "MRLibraryTree\0showArticleInDir\0\0"
    "relative_dir\0addFolder\0name\0"
    "on_articleTree_clicked\0QModelIndex\0"
    "index\0getRelativeDir\0QStandardItem*\0"
    "item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MRLibraryTree[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x0a /* Public */,
       6,    1,   40,    2, 0x08 /* Private */,
       9,    1,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::QString, 0x80000000 | 10,   11,

       0        // eod
};

void MRLibraryTree::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MRLibraryTree *_t = static_cast<MRLibraryTree *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showArticleInDir((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->addFolder((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_articleTree_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: { QString _r = _t->getRelativeDir((*reinterpret_cast< QStandardItem*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MRLibraryTree::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MRLibraryTree::showArticleInDir)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MRLibraryTree::staticMetaObject = { {
    &UIWidget::staticMetaObject,
    qt_meta_stringdata_MRLibraryTree.data,
    qt_meta_data_MRLibraryTree,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MRLibraryTree::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MRLibraryTree::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MRLibraryTree.stringdata0))
        return static_cast<void*>(this);
    return UIWidget::qt_metacast(_clname);
}

int MRLibraryTree::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = UIWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void MRLibraryTree::showArticleInDir(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
