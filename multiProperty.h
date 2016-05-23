#include "property.h"

class Collection : public Property
{
public:
	Collection();
	~Collection();
	void addProperty(Property newProperty);

private:
	std::list<Property> properties;
};