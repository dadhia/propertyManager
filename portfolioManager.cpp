#include "portfolioManager.h"
#include <sstream>
#include <string>
#include <QMessageBox>

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
	//insert slot/signal here
	tenantButtons->addWidget(manageTenantButton);

	addTenantButton = new QPushButton("  Add Tenant  ");
	//insert slot/signal here
	tenantButtons->addWidget(addTenantButton);
	
	viewPaymentButton = new QPushButton("Payment History");
	//insert slot/signal here
	tenantButtons->addWidget(viewPaymentButton);


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
	overallLayout->addLayout(propertyManagement);
	overallLayout->addLayout(tenantManagement);

	setLayout(overallLayout);

	//manage property window
	managePropertyWidget = new QWidget();
	propertyLines = new QVBoxLayout();

	lineOneLayout = new QHBoxLayout();
	addressLineOne = new QLabel("Address Line 1:");
	lineOne = new QLineEdit();
	lineOneLayout->addWidget(addressLineOne);
	lineOneLayout->addWidget(lineOne);
	propertyLines->addLayout(lineOneLayout);

	lineTwoLayout = new QHBoxLayout();
	addressLineTwo = new QLabel("Address Line 2:");
	lineTwo = new QLineEdit();
	lineTwoLayout->addWidget(addressLineTwo);
	lineTwoLayout->addWidget(lineTwo);
	propertyLines->addLayout(lineTwoLayout);

	cityLayout = new QHBoxLayout();
	cityLabel = new QLabel("City:                     ");
	city = new QLineEdit();
	cityLayout->addWidget(cityLabel);
	cityLayout->addWidget(city);
	propertyLines->addLayout(cityLayout);

	stateLayout = new QHBoxLayout();
	stateLabel = new QLabel("State:                  ");
	state = new QLineEdit();
	stateLayout->addWidget(stateLabel);
	stateLayout->addWidget(state);
	propertyLines->addLayout(stateLayout);

	zipLayout = new QHBoxLayout();
	zipLabel = new QLabel("Zip Code:           ");
	zip = new QLineEdit();
	zipLayout->addWidget(zipLabel);
	zipLayout->addWidget(zip);
	propertyLines->addLayout(zipLayout);

	updateButtons = new QHBoxLayout();
	updatePropertyButton = new QPushButton("Update Property");
	connect(updatePropertyButton, SIGNAL(clicked()), this, SLOT(updateProperty()));
	updateButtons->addWidget(updatePropertyButton);
	
	cancelUpdateButton = new QPushButton("Cancel");
	connect(cancelUpdateButton, SIGNAL(clicked()), this, SLOT(cancelManage()));
	updateButtons->addWidget(cancelUpdateButton);
	propertyLines->addLayout(updateButtons);

	managePropertyWidget->setLayout(propertyLines);
	managePropertyWidget->setWindowTitle("Manage Property");
	managePropertyWidget->setStyleSheet("QPushButton:hover {color:red}");
};

PortfolioManager::~PortfolioManager()
{
	//worry about this later
};

void PortfolioManager::manageProperty()
{
	updatePropertyButton->setText("Update Property");
	managePropertyWidget->setWindowTitle("Update Property");
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
	if(addingProperty)
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
		Property newProperty (_lineOne, _lineTwo, _city, _state, _zip);
		this->portfolio->addProperty(newProperty);
		this->portfolio->updateListOfProperties(properties);
		managePropertyWidget->hide();
	}
	else
	{
		//this is for updating a property and not adding a property
		//worry about this later
	}
};

void PortfolioManager::manageTenant()
{

};

void PortfolioManager::addTenant()
{

};

void PortfolioManager::sendErrorMessage(const std::string & message)
{
	QMessageBox errorMessage;
	errorMessage.setWindowTitle("Portfolio Load Error");
	errorMessage.setIcon(QMessageBox::Warning);
	errorMessage.setText(QString::fromStdString(message));
	errorMessage.exec();
	return;
};