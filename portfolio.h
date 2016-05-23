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

	void readFile(std::istream input);
	void savePortfolio(std::ofstream & output) const;

	void addTenant(Tenant & newTenant);
	void addProperty(Property & newProperty);

	void setName(const std::string & filename);

	const std::map<int, Property> & getProperties() const;
	const std::map<int, Tenant> & getTenants () const;

	void updateListOfProperties(QListWidget* list);

private:
	std::map<int, Property> properties;
	std::map<int, Tenant> tenants;
	std::string name;
};
#endif