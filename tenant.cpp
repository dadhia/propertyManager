#include "tenant.h"
#include <exception>
#include <sstream>
#include <stdexcept>
/*
void Tenant::setTenantCount(int count)
{
	tenantCount = count;
};*/


Tenant::Tenant(const std::string & first, const std::string & last, double rent, double balance):
	firstName(first), lastName(last), monthlyRent(rent), accountBalance(balance)
{
	propertyID = -1;
	//tenantCount++;
	//tenantID = tenantCount;
};

Tenant::Tenant(const std::string & first, const std::string & last, int tenantIDNumber, int propertyIDNumber,
	bool isCurrent, bool isActive, double rent, double balance):
	firstName(first), lastName(last), current(isCurrent), active(isActive), monthlyRent(rent), accountBalance(balance)
{
	propertyID = propertyIDNumber;
	//if(tenantIDNumber > tenantCount)
	//	throw std::logic_error("Error: file corrupted.  Error Code: 29");
	tenantID = tenantIDNumber;
};

Tenant::~Tenant() {};



void Tenant::assignToProperty(int ID)
{
	propertyID = ID;
};

void Tenant::makePayment (double amount)
{
	accountBalance -= amount;
};

void Tenant::addMonthlyRent ()
{
	accountBalance += monthlyRent;
};

int Tenant::getID()
{
	return tenantID;
};

int Tenant::getProperty()
{
	return propertyID;
};

double Tenant::getMonthlyRent()
{
	return monthlyRent;
};

double Tenant::getAccountBalance()
{
	return accountBalance;
};

void Tenant::setMonthlyRent(double amount)
{
	monthlyRent = amount;
};

void Tenant::writeTenantInfo(std::ostream & output)
{
	std::stringstream ss;
	ss << firstName << " " << lastName << " " << tenantID << " " << propertyID << " ";
	ss << current << " " << active << " " << monthlyRent << " " << accountBalance << std::endl;
	std::string information = ss.str();
	output << information;
};