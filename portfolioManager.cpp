#include "portfolioManager.h"
#include <sstream>
#include <string>
#include <QMessageBox>
#include <QApplication>
#include <fstream>

PortfolioManager::PortfolioManager (Portfolio* portfolio)
{
	this->portfolio = portfolio;
	setWindowTitle("Longboat Developement: Portfolio Manager");
	setStyleSheet("QPushButton:hover {color:red}");
	
	//section 1 of 2: tenant management
	tenantManagement = new QHBoxLayout();

	tenants = new QListWidget();
	tenantManagement->addWidget(tenants);
	
	tenantButtons = new QVBoxLayout();
	manageTenantButton = new QPushButton("  Manage Tenant  ");
	connect(manageTenantButton, SIGNAL(clicked()), this, SLOT(manageTenant()));
	tenantButtons->addWidget(manageTenantButton);

	

	addTenantButton = new QPushButton("  Add Tenant  ");
	connect(addTenantButton, SIGNAL(clicked()), this, SLOT(addTenant()));
	tenantButtons->addWidget(addTenantButton);
	
	viewPaymentButton = new QPushButton("Payment History");
	//insert slot/signal here
	tenantButtons->addWidget(viewPaymentButton);

	manageLeasesButton = new QPushButton("Manage Leases");
	//insert slot/signal here
	tenantButtons->addWidget(manageLeasesButton);


	tenantManagement->addLayout(tenantButtons);
	
	
	
	
	//section 2 of 2: property management 
	propertyManagement = new QHBoxLayout();
	
	//scrollable list for all the properties
	properties = new QListWidget();
	propertyManagement->addWidget(properties);

	//manage property and add property buttons
	propertyButtons = new QVBoxLayout();
	
	managePropertyButton = new QPushButton("Manage Property");
	connect(managePropertyButton, SIGNAL(clicked()), this, SLOT(manageProperty()));
	propertyButtons->addWidget(managePropertyButton);
	
	addPropertyButton = new QPushButton("Add Property");
	connect(addPropertyButton, SIGNAL(clicked()), this, SLOT(addProperty()));
	propertyButtons->addWidget(addPropertyButton);

	propertyManagement->addLayout(propertyButtons);

	overallLayout = new QVBoxLayout();

	mainButtonLayout = new QHBoxLayout();
	saveAsLabel = new QLabel("Save As: ");
	mainButtonLayout->addWidget(saveAsLabel);

	filename = new QLineEdit();
	connect(filename, SIGNAL(returnPressed()), this, SLOT(save()));
	mainButtonLayout->addWidget(filename);
	filename->setText(QString::fromStdString(this->portfolio->getName()));

	saveButton = new QPushButton("Save");
	connect(saveButton, SIGNAL(clicked()), this, SLOT(save()));
	mainButtonLayout->addWidget(saveButton);

	saveAndQuitButton = new QPushButton("Save and Quit");
	connect(saveAndQuitButton, SIGNAL(clicked()), this, SLOT(saveAndQuit()));
	mainButtonLayout->addWidget(saveAndQuitButton);

	quitButton = new QPushButton("Quit");
	connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));
	mainButtonLayout->addWidget(quitButton);

	overallLayout->addLayout(propertyManagement);
	overallLayout->addLayout(tenantManagement);
	overallLayout->addLayout(mainButtonLayout);

	setLayout(overallLayout);

	//manage property window
	managePropertyWidget = new QWidget();
	propertyLines = new QVBoxLayout();
	

	lineOneLayout = new QHBoxLayout();
	addressLineOne = new QLabel("Address Line 1:");
	lineOneLayout->addWidget(addressLineOne);
	lineOne = new QLineEdit();
	connect(lineOne, SIGNAL(returnPressed()), this, SLOT(updateProperty()));
	lineOneLayout->addWidget(lineOne);
	propertyLines->addLayout(lineOneLayout);

	//address line two for property
	lineTwoLayout = new QHBoxLayout();
	addressLineTwo = new QLabel("Address Line 2:");
	lineTwoLayout->addWidget(addressLineTwo);
	lineTwo = new QLineEdit();
	connect(lineTwo, SIGNAL(returnPressed()), this, SLOT(updateProperty()));
	lineTwoLayout->addWidget(lineTwo);
	propertyLines->addLayout(lineTwoLayout);

	//city for property
	cityLayout = new QHBoxLayout();
	cityLabel = new QLabel("City:                     ");
	cityLayout->addWidget(cityLabel);
	city = new QLineEdit();
	connect(city, SIGNAL(returnPressed()), this, SLOT(updateProperty()));
	cityLayout->addWidget(city);
	propertyLines->addLayout(cityLayout);

	//state for property
	stateLayout = new QHBoxLayout();
	stateLabel = new QLabel("State:                  ");
	stateLayout->addWidget(stateLabel);
	state = new QLineEdit();
	connect(state, SIGNAL(returnPressed()), this, SLOT(updateProperty()));
	stateLayout->addWidget(state);
	propertyLines->addLayout(stateLayout);

	//zip code for property
	zipLayout = new QHBoxLayout();
	zipLabel = new QLabel("Zip Code:           ");
	zipLayout->addWidget(zipLabel);
	zip = new QLineEdit();
	connect(zip, SIGNAL(returnPressed()), this, SLOT(updateProperty()));
	zipLayout->addWidget(zip);
	propertyLines->addLayout(zipLayout);

	selectedPropertyID = properties->currentRow();
	updateButtons = new QHBoxLayout();
	updatePropertyButton = new QPushButton("Update Property");
	connect(updatePropertyButton, SIGNAL(clicked()), this, SLOT(updateProperty()));
	updateButtons->addWidget(updatePropertyButton);
	
	cancelUpdateButton = new QPushButton("Cancel");
	connect(cancelUpdateButton, SIGNAL(clicked()), this, SLOT(cancelManage()));
	updateButtons->addWidget(cancelUpdateButton);
	propertyLines->addLayout(updateButtons);

	managePropertyWidget->setLayout(propertyLines);
	managePropertyWidget->setStyleSheet("QPushButton:hover {color:red}");

	manageTenantWidget = new QWidget();
	tenantLines = new QVBoxLayout();

	firstNameLayout = new QHBoxLayout();
	firstNameLabel = new QLabel("First Name: ");
	firstNameLayout->addWidget(firstNameLabel);
	firstName = new QLineEdit();
	connect(firstName, SIGNAL(returnPressed()), this, SLOT(updateTenant()));
	firstNameLayout->addWidget(firstName);
	tenantLines->addLayout(firstNameLayout);

	lastNameLayout = new QHBoxLayout();
	lastNameLabel = new QLabel("Last Name:  ");
	lastNameLayout->addWidget(lastNameLabel);
	lastName = new QLineEdit();
	connect(lastName, SIGNAL(returnPressed()), this, SLOT(updateTenant()));
	lastNameLayout->addWidget(lastName);
	tenantLines->addLayout(lastNameLayout);

	phoneNumberLayout = new QHBoxLayout();
	phoneNumberLabel = new QLabel("Phone Number: ");
	phoneNumberLayout->addWidget(phoneNumberLabel);
	phoneNumber = new QLineEdit();
	connect(phoneNumber, SIGNAL(returnPressed()), this, SLOT(updateTenant()));
	phoneNumberLayout->addWidget(phoneNumber);
	tenantLines->addLayout(phoneNumberLayout);

	updateTenantButton = new QPushButton("Update Tenant");
	connect(updateTenantButton, SIGNAL(clicked()), this, SLOT(updateTenant()));
	cancelUpdateTenantButton = new QPushButton("Cancel");
	connect(cancelUpdateTenantButton, SIGNAL(clicked()), this, SLOT(cancelTenantManage()));
	updateTenantButtons = new QHBoxLayout();
	updateTenantButtons->addWidget(updateTenantButton);
	updateTenantButtons->addWidget(cancelUpdateTenantButton);
	tenantLines->addLayout(updateTenantButtons);
	manageTenantWidget->setLayout(tenantLines);

	allChangesSaved = true;
	this->portfolio->updateListOfProperties(properties);
	this->portfolio->updateListOfTenants(tenants);
};

PortfolioManager::~PortfolioManager()
{
	//worry about this later
};

void PortfolioManager::manageProperty()
{
	selectedPropertyID = properties->currentRow()+1;
	if(selectedPropertyID==0)
	{
		sendErrorMessage("No Property Selected!");
		return;
	}
	addingProperty = false;

	Property* selectedProperty = this->portfolio->getSingleProperty(selectedPropertyID);
	lineOne->setText(QString::fromStdString(selectedProperty->getStreetAddressOne()));
	lineTwo->setText(QString::fromStdString(selectedProperty->getStreetAddressTwo()));
	city->setText(QString::fromStdString(selectedProperty->getCity()));
	state->setText(QString::fromStdString(selectedProperty->getState()));
	std::stringstream ss;
	ss << selectedProperty->getZip();
	zip->setText(QString::fromStdString(ss.str()));
	updatePropertyButton->setText("Update Property");
	managePropertyWidget->setWindowTitle("Manage Property");
	managePropertyWidget->show();
};

/**
* Hides the managePropertyWidget from the user's view.
*/
void PortfolioManager::cancelManage()
{
	managePropertyWidget->hide();
};

/**
* Clears the text in the managePropertyWidget and also changes the text of the window and button
* to 'Add Property'.
*/
void PortfolioManager::addProperty()
{
	addingProperty = true;
	lineOne->clear();
	lineTwo->clear();
	city->clear();
	state->clear();
	zip->clear();
	updatePropertyButton->setText("Add Property");
	managePropertyWidget->setWindowTitle("Add Property");
	managePropertyWidget->show();
};

void PortfolioManager::updateProperty()
{
	if(lineOne->text().isEmpty() || city->text().isEmpty() || state->text().isEmpty() ||
		zip->text().isEmpty())
	{
		sendErrorMessage("Address Line One, City, State, and Zip Code are all required fields!");
		return;
	}
	std::string _lineOne = lineOne->text().toStdString();
	std::string _lineTwo = lineTwo->text().toStdString();
	std::string _city = city->text().toStdString();
	std::string _state = state->text().toStdString();
	int _zip = zip->text().toInt();
	if (addingProperty)
	{
		Property newProperty (_lineOne, _lineTwo, _city, _state, _zip);
		this->portfolio->addProperty(newProperty);
	}
	else
	{
		Property* selectedProperty = this->portfolio->getSingleProperty(selectedPropertyID);
		selectedProperty->setAddressOne(_lineOne);
		selectedProperty->setAddressTwo(_lineTwo);
		selectedProperty->setCity(_city);
		selectedProperty->setState(_state);
		selectedProperty->setZip(_zip);
	}
	this->portfolio->updateListOfProperties(properties);
	allChangesSaved = false;
	managePropertyWidget->hide();
};

void PortfolioManager::manageTenant()
{
	addingTenant = false;
	selectedTenantID = tenants->currentRow()+1;
	if (selectedTenantID == 0)
	{
		sendErrorMessage("No Tenant Selected!");
		return;
	}
	Tenant* selectedTenant = this->portfolio->getSingleTenant(selectedTenantID);
	firstName->setText(QString::fromStdString(selectedTenant->getFirstName()));
	lastName->setText(QString::fromStdString(selectedTenant->getLastName()));
	phoneNumber->setText(QString::fromStdString(selectedTenant->getPhoneNumber()));

	manageTenantWidget->setWindowTitle("Manage Tenant");
	updateTenantButton->setText("Update Tenant");
	manageTenantWidget->show();
};

void PortfolioManager::addTenant()
{
	addingTenant = true;
	firstName->clear();
	lastName->clear();
	phoneNumber->clear();
	manageTenantWidget->setWindowTitle("Add Tenant");
	updateTenantButton->setText("Add Tenant");
	manageTenantWidget->show();
};

/**
* Hides the manageTenantWidget from the user's view.
*/
void PortfolioManager::cancelTenantManage()
{
	manageTenantWidget->hide();
};

void PortfolioManager::updateTenant()
{
	if (firstName->text().isEmpty() || lastName->text().isEmpty() || phoneNumber->text().isEmpty() )
	{
		sendErrorMessage("First Name, Last Name, and Phone Number are all required fields!");
		return;
	}
	std::string first = firstName->text().toStdString();
	std::string last = lastName->text().toStdString();
	std::string phone = phoneNumber->text().toStdString();

	if(addingTenant)
	{
		Tenant newTenant(first, last, phone);
		this->portfolio->addTenant(newTenant);
	}
	else
	{
		Tenant* selectedTenant = this->portfolio->getSingleTenant(selectedTenantID);
		selectedTenant->setFirstName(first);
		selectedTenant->setLastName(last);
		selectedTenant->setPhoneNumber(phone);
	}
	this->portfolio->updateListOfTenants(tenants);
	allChangesSaved = false;
	manageTenantWidget->hide();
}

void PortfolioManager::saveAndQuit()
{
	this->save();
	this->quit();
};

void PortfolioManager::save()
{
	std::ofstream output(filename->text().toStdString().c_str());
	this->portfolio->savePortfolio(output);
	output.close();
	allChangesSaved = true;
};

void PortfolioManager::quit () 
{
	if (!allChangesSaved)
	{
		int choice = areYouSure();
		if(choice == QMessageBox::AcceptRole)
		{
			this->save();
		}
		else if (choice == QMessageBox::RejectRole)
		{
			return;
		}
		else
		{
			QApplication::exit();
		}
	}
	else
	{
		QApplication::exit();
	}
};

void PortfolioManager::sendErrorMessage(const std::string & message)
{
	QMessageBox errorMessage;
	errorMessage.setWindowTitle("Error");
	errorMessage.setIcon(QMessageBox::Warning);
	errorMessage.setText(QString::fromStdString(message));
	errorMessage.exec();
	return;
};

int PortfolioManager::areYouSure()
{
	QMessageBox errorMessage;
	errorMessage.setText("Not all changes to your portfolio have been saved.  Do you want to quit without saving?");
	errorMessage.setStandardButtons(QMessageBox::Cancel | QMessageBox::Save | QMessageBox::Discard);
	errorMessage.setDefaultButton(QMessageBox::Save);
	return errorMessage.exec();
};