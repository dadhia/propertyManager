#ifndef TENANT_H
#define TENANT_H
#include <string>
#include <iostream>
#include <ctime>

class Tenant
{
public:

	Tenant(const std::string & first, const std::string & last, const std::string & phone);
	Tenant(const std::string & first, const std::string & last, const std::string & phone,
			int ID, int property, bool isCurrent, bool isActive, double rent, double balance);
	~Tenant();

	static void setTenantCount(int count);


	std::string getFirstName();
	std::string getLastName();
	std::string getPhoneNumber();

	void setFirstName(const std::string & newFirstName);
	void setLastName(const std::string & newLastName);
	void setPhoneNumber(const std::string & newPhoneNumber);

	void assignToProperty(int propertyID);

	void makePayment (double amount);

	void addMonthlyRent();

	int getID();

	int getProperty();

	double getMonthlyRent();

	double getAccountBalance();

	void setMonthlyRent(double amount);

	void writeTenantInfo(std::ostream & output);

private:
	static int tenantCount;
	std::string firstName;
	std::string lastName;
	std::string phoneNumber;
	int tenantID;
	int propertyID;
	bool current;
	bool active;
	double monthlyRent;
	double accountBalance;

	//worry about this later
	//tm* moveIn;
	//tm* moveOut;
};
#endif