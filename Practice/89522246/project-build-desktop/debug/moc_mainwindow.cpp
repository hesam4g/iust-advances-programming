/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun Jul 3 17:57:00 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../project/mainwindow.h"
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
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      18,   11,   11,   11, 0x0a,
      27,   11,   11,   11, 0x0a,
      40,   11,   11,   11, 0x0a,
      55,   11,   11,   11, 0x0a,
      71,   11,   11,   11, 0x0a,
      84,   11,   11,   11, 0x0a,
      97,   11,   11,   11, 0x0a,
     110,   11,   11,   11, 0x0a,
     123,   11,   11,   11, 0x0a,
     134,   11,   11,   11, 0x0a,
     148,   11,   11,   11, 0x0a,
     155,   11,   11,   11, 0x0a,
     168,   11,   11,   11, 0x0a,
     179,   11,   11,   11, 0x0a,
     193,   11,   11,   11, 0x0a,
     210,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0buy()\0cancel()\0seeAllPass()\0"
    "seeAllFlight()\0seeFlightInfo()\0"
    "makeFlight()\0editFlight()\0searchPass()\0"
    "buyATicket()\0doCancel()\0seeAllPass1()\0"
    "save()\0editWindow()\0saveEdit()\0"
    "information()\0passWithNumber()\0"
    "passWithName()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
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
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: buy(); break;
        case 1: cancel(); break;
        case 2: seeAllPass(); break;
        case 3: seeAllFlight(); break;
        case 4: seeFlightInfo(); break;
        case 5: makeFlight(); break;
        case 6: editFlight(); break;
        case 7: searchPass(); break;
        case 8: buyATicket(); break;
        case 9: doCancel(); break;
        case 10: seeAllPass1(); break;
        case 11: save(); break;
        case 12: editWindow(); break;
        case 13: saveEdit(); break;
        case 14: information(); break;
        case 15: passWithNumber(); break;
        case 16: passWithName(); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
