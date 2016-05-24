#ifndef PROPERTY_H
#define PROPERTY_H
#include <iostream>
#include <string>
#include <vector>

class Property
{
public:
	Property(const std::string & addressOne, const std::string & addressTwo,
	const std::string & propertyCity, const std::string & propertyState, const int & zipCode);

	Property(const std::string & addressOne, const std::string & addressTwo,
	const std::string & propertyCity, const std::string & propertyState, const int & zipCode,
	const int & propertyIDNumber, const int & tenantIDNumber);

	~Property();

	

	static void setPropertyCount(int count);

	std::string getStreetAddressOne() const;
	std::string getStreetAddressTwo() const;
	std::string getCity() const;
	std::string getState() const;
	int getZip() const;
	int getID() const;
	int getTenantID() const;
	
	
	void setAddressOne(const std::string & lineOne);
	void setAddressTwo(const std::string & lineTwo);
	void setCity(const std::string & newCity);
	void setState(const std::string & newState);
	void setZip(int newZip);
	void assignTenant(int ID);
	
	void writePropertyInfo (std::ostream & output);
private:
	
	static int propertyCount;
	std::string streetAddress;
	std::string addressLineTwo;
	std::string city;
	std::string state;
	int zip;

	int propertyID;
	int tenantID;	
};
#endif