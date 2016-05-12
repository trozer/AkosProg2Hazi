#pragma once
#include"Person.h"

class Buyer : public Person {

public:
	Buyer() {
		this->Role = "Vevo";
	}
	std::string whatIsMyRole() {
		return Role;
	};

	const char *faljban_nev() const {
		return "Buyer";
	}

	void save(std::ostream& os) const {
		os << faljban_nev() << ' ' << Role << std::endl;
	}

	void load(std::istream& is) {
		is >> Role;
	}

	Buyer* klonoz() const {
		return new Buyer(*this);
	}
};