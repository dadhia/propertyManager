#include "property.h"
#include <string>
#include <exception>
#include <stdexcept>
#include <sstream>

Property::Property(const std::string & addressOne, const std::string & addressTwo,
	const std::string & propertyCity, const std::string & propertyState, const int & zipCode) :
streetAddress(addressOne), addressLineTwo(addressTwo), city(propertyCity), state(propertyState), zip(zipCode)
{
	tenantID = -1;
	//this->propertyCount++;
	//propertyID = this->propertyCount;
};

Property::Property(const std::string & addressOne, const std::string & addressTwo,
	const std::string & propertyCity, const std::string & propertyState, const int & zipCode,
	const int & propertyIDNumber, const int & tenantIDNumber) :
streetAddress(addressOne), addressLineTwo(addressTwo), city(propertyCity), state(propertyState), zip(zipCode)
{
	tenantID = tenantIDNumber;
	//if(propertyIDNumber > propertyCount)
	//{
	//	throw std::logic_error("Error: File corrupted. Error Code: 12");
	//}
	propertyID = propertyIDNumber;
};

Property::~Property() {};

//void Property::setPropertyCount (int count)
//{
//	propertyCount = count;
//};


//Getter Methods Below
int Property::getID() const
{
	return propertyID;
};

int Property::getTenantID() const
{
	return tenantID;
};

std::string Property::getStreetAddressOne() const
{
	return streetAddress;
};

std::string Property::getStreetAddressTwo() const
{
	return addressLineTwo;
};

std::string Property::getCity() const
{
	return city;
};

std::string Property::getState() const
{
	return state;
};

int Property::getZip() const
{
	return zip;
};

//setter methods
//note that there is no way to change the property ID once it has been created
//ID's are assigned by the property class

void Property::setAddressOne(const std::string & lineOne)
{
	streetAddress = lineOne;
};

void Property::setAddressTwo(const std::string & lineTwo)
{
	addressLineTwo = lineTwo;
};

void Property::setCity(const std::string & newCity)
{
	city = newCity;
};

void Property::setState(const std::string & newState)
{
	state = newState;
};

void Property::setZip(int newZip)
{
	zip = newZip;
};

void Property::assignTenant(int ID)
{
	tenantID = ID;
};

void Property::writePropertyInfo (std::ostream & output) const
{
	output << streetAddress << std::endl;
	output << addressLineTwo << std::endl;
	output << city << std::endl;
	output << state << std::endl;
	std::stringstream ss;
	ss << zip << " " << tenantID << " " << propertyID;
	std::string lastLine = ss.str();
	output << ss << std::endl;
};