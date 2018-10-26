/****************************************************************************
** Meta object code from reading C++ file 'fqqconfigview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../fqqconfigview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fqqconfigview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_fqqConfigView_t {
    QByteArrayData data[10];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_fqqConfigView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_fqqConfigView_t qt_meta_stringdata_fqqConfigView = {
    {
QT_MOC_LITERAL(0, 0, 13), // "fqqConfigView"
QT_MOC_LITERAL(1, 14, 17), // "sig__SliderChange"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 10), // "slotChange"
QT_MOC_LITERAL(4, 44, 8), // "slotSave"
QT_MOC_LITERAL(5, 53, 11), // "slotSlider1"
QT_MOC_LITERAL(6, 65, 7), // "_inline"
QT_MOC_LITERAL(7, 73, 6), // "iValue"
QT_MOC_LITERAL(8, 80, 11), // "slotSlider2"
QT_MOC_LITERAL(9, 92, 11) // "slotSlider3"

    },
    "fqqConfigView\0sig__SliderChange\0\0"
    "slotChange\0slotSave\0slotSlider1\0_inline\0"
    "iValue\0slotSlider2\0slotSlider3"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_fqqConfigView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   45,    2, 0x0a /* Public */,
       4,    0,   48,    2, 0x0a /* Public */,
       5,    1,   49,    6, 0x0a /* Public */,
       8,    1,   52,    6, 0x0a /* Public */,
       9,    1,   55,    6, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void fqqConfigView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        fqqConfigView *_t = static_cast<fqqConfigView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig__SliderChange(); break;
        case 1: _t->slotChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->slotSave(); break;
        case 3: _t->slotSlider1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->slotSlider2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->slotSlider3((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (fqqConfigView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&fqqConfigView::sig__SliderChange)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject fqqConfigView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_fqqConfigView.data,
      qt_meta_data_fqqConfigView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *fqqConfigView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *fqqConfigView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_fqqConfigView.stringdata0))
        return static_cast<void*>(const_cast< fqqConfigView*>(this));
    return QWidget::qt_metacast(_clname);
}

int fqqConfigView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void fqqConfigView::sig__SliderChange()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
