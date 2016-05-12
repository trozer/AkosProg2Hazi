#pragma once
#include"Person.h"

class Guard : public Person{

public:
	Guard() {
		this->Role = "Or";
	}
	std::string whatIsMyRole() {
		return Role;
	};

	const char *faljban_nev() const {
		return "Guard";
	}

	void save(std::ostream& os) const {
		os << faljban_nev() << ' ' << Role << std::endl;
	}

	void load(std::istream& is) {
		is >> Role;
	}

	Guard* klonoz() const {
		return new Guard(*this);
	}
};
