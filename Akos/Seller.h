#pragma once
#include"Person.h"

class Seller : public Person{

public:
	Seller() {
		this->Role = "Elado";
	}
	std::string whatIsMyRole() {
		return Role;
	};

	const char *faljban_nev() const {
		return "Seller";
	}

	void save(std::ostream& os) const {
		os << faljban_nev() << ' ' << Role << std::endl;
	}

	void load(std::istream& is) {
		is >> Role;
	}

	Seller* klonoz() const {
		return new Seller(*this);
	}
};
