/****************************************************************************
** Meta object code from reading C++ file 'portfolioManager.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "portfolioManager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'portfolioManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PortfolioManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      35,   17,   17,   17, 0x08,
      50,   17,   17,   17, 0x08,
      64,   17,   17,   17, 0x08,
      81,   17,   17,   17, 0x08,
      96,   17,   17,   17, 0x08,
     108,   17,   17,   17, 0x08,
     129,   17,   17,   17, 0x08,
     144,   17,   17,   17, 0x08,
     151,   17,   17,   17, 0x08,
     165,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PortfolioManager[] = {
    "PortfolioManager\0\0manageProperty()\0"
    "cancelManage()\0addProperty()\0"
    "updateProperty()\0manageTenant()\0"
    "addTenant()\0cancelTenantManage()\0"
    "updateTenant()\0save()\0saveAndQuit()\0"
    "quit()\0"
};

void PortfolioManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PortfolioManager *_t = static_cast<PortfolioManager *>(_o);
        switch (_id) {
        case 0: _t->manageProperty(); break;
        case 1: _t->cancelManage(); break;
        case 2: _t->addProperty(); break;
        case 3: _t->updateProperty(); break;
        case 4: _t->manageTenant(); break;
        case 5: _t->addTenant(); break;
        case 6: _t->cancelTenantManage(); break;
        case 7: _t->updateTenant(); break;
        case 8: _t->save(); break;
        case 9: _t->saveAndQuit(); break;
        case 10: _t->quit(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData PortfolioManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PortfolioManager::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PortfolioManager,
      qt_meta_data_PortfolioManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PortfolioManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PortfolioManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PortfolioManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PortfolioManager))
        return static_cast<void*>(const_cast< PortfolioManager*>(this));
    return QWidget::qt_metacast(_clname);
}

int PortfolioManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
