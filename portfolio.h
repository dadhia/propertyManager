#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "tenant.h"
#include "property.h"
#include <map>
#include <QListWidget>

class Portfolio
{
public:
	Portfolio();
	~Portfolio();

	void readFile(std::istream & input);
	void savePortfolio(std::ostream & output);

	void addTenant(Tenant & newTenant);
	void addProperty(Property & newProperty);

	void setName(const std::string & filename);
	std::string getName() const;

	void updateListOfProperties(QListWidget* list);
	Property* getSingleProperty (int ID);
	void updateListOfTenants(QListWidget* list);
	Tenant* getSingleTenant(int ID);

private:
	std::map<int, Property> properties;
	std::map<int, Tenant> tenants;
	std::string name;
};
#endif