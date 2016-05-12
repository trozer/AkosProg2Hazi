#pragma once
#include<iostream>
#include<map>
#include<string>

class Person {
protected:
	std::string Role;
public:
	virtual std::string whatIsMyRole() = 0;

	virtual const char *faljban_nev() const = 0;
	virtual void save(std::ostream &os) const = 0;
	virtual void load(std::istream &is) = 0;
	virtual Person* klonoz() const = 0;

	static std::map<std::string, Person *> prototipusok;
	static void prototipus_hozzaad(Person *a) {
		prototipusok[a->faljban_nev()] = a;
	}
	static Person* beolvas(std::istream &is);

	~Person() {}
};