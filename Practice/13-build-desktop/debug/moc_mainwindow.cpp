/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Fri Jun 10 17:09:04 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../13/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      21,   11,   11,   11, 0x08,
      30,   11,   11,   11, 0x08,
      39,   11,   11,   11, 0x08,
      48,   11,   11,   11, 0x08,
      57,   11,   11,   11, 0x08,
      66,   11,   11,   11, 0x08,
      75,   11,   11,   11, 0x08,
      84,   11,   11,   11, 0x08,
      93,   11,   11,   11, 0x08,
     102,   11,   11,   11, 0x08,
     111,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0khoruj()\0print1()\0print2()\0"
    "print3()\0print4()\0print5()\0print6()\0"
    "print7()\0print8()\0print9()\0print0()\0"
    "printDOT()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: khoruj(); break;
        case 1: print1(); break;
        case 2: print2(); break;
        case 3: print3(); break;
        case 4: print4(); break;
        case 5: print5(); break;
        case 6: print6(); break;
        case 7: print7(); break;
        case 8: print8(); break;
        case 9: print9(); break;
        case 10: print0(); break;
        case 11: printDOT(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
