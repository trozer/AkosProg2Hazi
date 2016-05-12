#include"Person.h"

std::map<std::string, Person *> Person::prototipusok;

Person* Person::beolvas(std::istream& is) {
	std::string tipus;
	if (!(is >> tipus))
		return NULL;
	std::map<std::string, Person *>::iterator it;
	it = prototipusok.find(tipus);
	if (it == prototipusok.end())
		throw std::runtime_error("ervenytelen ember tipus");
	
	Person *proto = it->second;

	Person *uj = proto->klonoz();
	uj->load(is);
	return uj;
}