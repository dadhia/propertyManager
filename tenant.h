#ifndef TENANT_H
#define TENANT_H
#include <string>
#include <iostream>
#include <ctime>

class Tenant
{
public:
	Tenant(const std::string & firstName, const std::string & lastName, double rent = 0, double balance =0 );
	Tenant(const std::string & first, const std::string & last, int tenantIDNumber, int propertyIDNumber,
	bool isCurrent, bool isActive, double rent=0, double balance=0);

	~Tenant();

	//static void setTenantCount(int count);

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
	//static int tenantCount;
	std::string firstName;
	std::string lastName;
	int tenantID;
	int propertyID;
	bool current;
	bool active;


	double monthlyRent;
	double accountBalance;
	tm* moveIn;
	tm* moveOut;
};

Tenant readTenantInfo(std::ifstream & input);
#endif