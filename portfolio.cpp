#include "portfolio.h"
#include "tenant.h"
#include "property.h"
#include <sstream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <exception>

//prototype; definition can be found in property.cpp
Property readPropertyInfo(std::istream & input);

//prototype; defintion can be found in tenant.cpp
Tenant readTenantInfo(std::istream & input);

Portfolio::Portfolio () {};

Portfolio::~Portfolio () {};

void Portfolio::addTenant(Tenant & newTenant)
{
	tenants.insert(std::pair<int, Tenant> (newTenant.getID(), newTenant));
};

void Portfolio::addProperty(Property & newProperty)
{
	properties.insert(std::pair<int, Property>(newProperty.getID(), newProperty));
};

void Portfolio::setName(const std::string & filename)
{
	name = filename;
};

std::string Portfolio::getName() const
{
	return name;
};

//read tenant information from  a file and build the portfolio with it
void Portfolio::readFile(std::istream & input)
{
	std::string oneLine;
	std::stringstream  ss;
	getline(input, oneLine);
	ss << oneLine;
	int numberOfProperties, numberOfTenants;
	ss >> numberOfProperties >> numberOfTenants;
	Property::setPropertyCount(numberOfProperties);
	Tenant::setTenantCount(numberOfTenants);
	for (int i = 0; i < numberOfProperties; i++)
	{
		try
		{
			Property newProperty = readPropertyInfo(input);
			properties.insert(std::pair<int, Property>(newProperty.getID(), newProperty));
		}
		catch(std::exception & e)
		{
			throw std::logic_error("File Corrupted! Error Code: 0001");
		}

	}
	for (int i = 0; i < numberOfTenants; i++)
	{
		try
		{
			Tenant newTenant = readTenantInfo(input);
			tenants.insert(std::pair<int, Tenant>(newTenant.getID(), newTenant));			
		}
		catch(std::exception & e)
		{
			throw std::logic_error("File Corrupted! Error Code: 0002");
		}
	}
};

void Portfolio::savePortfolio(std::ostream & output)
{
	std::stringstream ss;
	ss << properties.size() << " " << tenants.size();
	output << ss.str() << std::endl;
	for (std::map <int, Property>::iterator it = this->properties.begin(); it!= this->properties.end(); it++)
		it->second.writePropertyInfo(output);
	for (std::map <int, Tenant> ::iterator it = this->tenants.begin(); it!= this->tenants.end(); ++it)
		it->second.writeTenantInfo(output);
};

void Portfolio::updateListOfProperties(QListWidget* list)
{
	list->clear();
	std::map <int, Property>::iterator it;
	for (it = this->properties.begin(); it!= this->properties.end(); ++it)
	{
		std::string itemDescription = it->second.getStreetAddressOne() + " " + it->second.getCity() + 
		" " + it->second.getState();
		list->addItem(QString::fromStdString(itemDescription));
	}
};

Property* Portfolio::getSingleProperty (int ID)
{
	return &(properties.find(ID)->second);
};

void Portfolio::updateListOfTenants(QListWidget* list)
{
	list->clear();
	std::map <int, Tenant>::iterator it;
	for (it = this->tenants.begin(); it!= this->tenants.end(); it++)
	{
		std::string itemDescription = it->second.getFirstName() + " " + it->second.getLastName() + "   Phone: " + 
		it->second.getPhoneNumber();
		list->addItem(QString::fromStdString(itemDescription));
	}
};

Tenant* Portfolio::getSingleTenant (int ID)
{
	return &(tenants.find(ID)->second);
};