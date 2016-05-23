#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QTableWidget>
#include <fstream>
#include <QLineEdit>
#include <QLabel>
#include "portfolio.h"

class PortfolioManager : public QWidget 
{
	Q_OBJECT
public:
	PortfolioManager(Portfolio* portfolio);
	~PortfolioManager();

private slots:
	void manageProperty();
	void cancelManage();
	void addProperty();
	void manageTenant();
	void addTenant();

private:
	QPushButton* managePropertyButton;
	QPushButton* addPropertyButton;

	QWidget* managePropertyWidget;
	QVBoxLayout* propertyLines;
	QHBoxLayout* lineOneLayout;
	QHBoxLayout* lineTwoLayout;
	QHBoxLayout* cityLayout;
	QHBoxLayout* stateLayout;
	QHBoxLayout* zipLayout;
	QHBoxLayout* updateButtons;

	QLabel* addressLineOne;
	QLabel* addressLineTwo;
	QLabel* cityLabel;
	QLabel* stateLabel;
	QLabel* zipLabel;

	QLineEdit* lineOne;
	QLineEdit* lineTwo;
	QLineEdit* city;
	QLineEdit* state;
	QLineEdit* zip;
	QPushButton* updatePropertyButton;
	QPushButton* cancelUpdateButton;


	QVBoxLayout* propertyButtons;
	

	QVBoxLayout* tenantButtons;

	QListWidget* tenants;
	QPushButton* manageTenantButton;
	QPushButton* addTenantButton;
	QPushButton* viewPaymentButton;
	QListWidget* properties;
	
	

	QHBoxLayout* propertyManagement;
	QHBoxLayout* tenantManagement;
	QVBoxLayout* overallLayout;
};