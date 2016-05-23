#include "portfolio.h"
#include "tenant.h"
#include "property.h"
#include <sstream>
#include <fstream>
#include <string>

//this fuunction is not a part of the property class but can be used to read property information
Property readPropertyInfo(std::istream & input)
{
	std::string addressOne, addressTwo, city, state, otherInfo;
	int zip, tenantNumber, propertyNumber;
	std::stringstream ss;
	getline(input, addressOne);
	getline(input, addressTwo);
	getline(input, city);
	getline(input, state);
	getline(input, otherInfo);
	ss << otherInfo;
	ss >> zip >> tenantNumber >> propertyNumber;
	Property newProperty(addressOne, addressTwo, city, state, zip, tenantNumber, propertyNumber);
	return newProperty;
};

//this function is not a part of the tenant class but can be used to read tenant information
Tenant readTenantInfo(std::istream & input)
{
	std::string first, last;
	int ID, property;
	bool current, active;
	double monthlyRent, accountBalance;
	std::string oneLine;
	std::stringstream ss;
	getline(input, oneLine);
	ss << oneLine;
	ss >> first >> last >> ID >> property >> current >> active >> monthlyRent >> accountBalance;

	Tenant newTenant(first, last, ID, property, current, active, monthlyRent, accountBalance);
	return newTenant;
};

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


//read tenant information from  a file and build the portfolio with it
void Portfolio::readFile(std::istream input)
{
	std::string oneLine;
	std::stringstream  ss;
	getline(input, oneLine);
	ss << oneLine;
	int numberOfProperties, numberOfTenants;
	ss >> numberOfProperties >> numberOfTenants;
	//Property::setPropertyCount(numberOfProperties);
	//Tenant::setTenantCount(numberOfTenants);
	for (int i = 0; i < numberOfProperties; i++)
	{
		Property newProperty = readPropertyInfo(input);
		properties.insert(std::pair<int, Property>(newProperty.getID(), newProperty));
	}
	for (int i = 0; i < numberOfTenants; i++)
	{
		Tenant newTenant = readTenantInfo(input);
		tenants.insert(std::pair<int, Tenant>(newTenant.getID(), newTenant));
	}
};
