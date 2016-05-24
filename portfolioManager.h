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
	void updateProperty();
	void manageTenant();
	void addTenant();
	void cancelTenantManage();
	void updateTenant();
	void save();
	void saveAndQuit();
	void quit();

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
	QListWidget* properties;
	QPushButton* manageTenantButton;
	QPushButton* addTenantButton;
	QPushButton* viewPaymentButton;
	
	

	QHBoxLayout* propertyManagement;
	QHBoxLayout* tenantManagement;
	QVBoxLayout* overallLayout;


	bool addingProperty;
	int selectedPropertyID;
	bool addingTenant;
	int selectedTenantID;


	Portfolio* portfolio;
	void sendErrorMessage(const std::string & message);
	int areYouSure();

	QWidget* manageTenantWidget;
	QLabel* firstNameLabel;
	QLineEdit* firstName;
	QLabel* lastNameLabel;
	QLineEdit* lastName;
	QHBoxLayout* firstNameLayout;
	QHBoxLayout* lastNameLayout;
	QVBoxLayout* tenantLines;
	QPushButton* manageLeasesButton;
	QPushButton* updateTenantButton;
	QPushButton* cancelUpdateTenantButton;
	QHBoxLayout* updateTenantButtons;

	QHBoxLayout* phoneNumberLayout;
	QLabel* phoneNumberLabel;
	QLineEdit* phoneNumber;

	QLabel* saveAsLabel;
	QLineEdit* filename;
	QPushButton* saveButton;
	QPushButton* saveAndQuitButton;
	QPushButton* quitButton;
	QHBoxLayout* mainButtonLayout;


	bool allChangesSaved;
};