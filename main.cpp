#include "loadWindow.h"
#include <iostream>
#include <QApplication>

int Property::propertyCount = 0;
int Tenant::tenantCount = 0;

int main (int argc, char* argv[])
{
	QApplication app(argc, argv);

	LoadWindow loadWindow;

	loadWindow.show();

	return app.exec();
};