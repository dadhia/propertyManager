#include "tenant.h"
#include <exception>
#include <sstream>
#include <stdexcept>


Tenant::Tenant(const std::string & first, const std::string & last, const std::string & phone) :
firstName(first), lastName(last), phoneNumber(phone)
{
	tenantCount++;
	tenantID = tenantCount;
	propertyID = -1;
	current = false;
	active = false;
	monthlyRent = 0;
	accountBalance = 0;
}

Tenant::Tenant(const std::string & first, const std::string & last, const std::string & phone,
			int ID, int property, bool isCurrent, bool isActive, double rent, double balance):
firstName(first), lastName(last), phoneNumber(phone), tenantID(ID), propertyID(property), current(isCurrent),
active(isActive), monthlyRent(rent), accountBalance(balance) {};

Tenant::~Tenant() {};

void Tenant::setTenantCount(int count)
{
	tenantCount = count;
};

std::string Tenant::getFirstName()
{
	return firstName;
};

std::string Tenant::getLastName()
{
	return lastName;
};

std::string Tenant::getPhoneNumber()
{
	return phoneNumber;
};

void Tenant::setFirstName(const std::string & newFirstName)
{
	firstName = newFirstName;
};

void Tenant::setLastName(const std::string & newLastName)
{
	lastName = newLastName;
};

void Tenant::setPhoneNumber(const std::string & newPhoneNumber)
{
	phoneNumber = newPhoneNumber;
};

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
	ss << firstName << " " << lastName << " " << phoneNumber << " " << tenantID << " " << propertyID << " ";
	ss << current << " " << active << " " << monthlyRent << " " << accountBalance << std::endl;
	std::string information = ss.str();
	output << information;
};

Tenant readTenantInfo(std::istream & input)
{
	std::string first, last, phone;
	int ID, property;
	bool current, active;
	double monthlyRent, accountBalance;
	std::string oneLine;
	std::stringstream ss;
	getline(input, oneLine);
	ss << oneLine;
	ss >> first >> last >> phone >> ID >> property >> current >> active >> monthlyRent >> accountBalance;
	Tenant newTenant(first, last, phone, ID, property, current, active, monthlyRent, accountBalance);
	return newTenant;
};