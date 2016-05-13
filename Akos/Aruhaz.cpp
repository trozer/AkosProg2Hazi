#include"Aruhaz.h"

using namespace std;

bool Aruhaz::addGuard(Guard* newGuard) {
	if (!isFulled()) {
		People.push_back(newGuard);
		guardNum++;
		cout << "Or bement a boltba." << endl;
		return true;
	}
	else {
		cout << "Az aruhaz tele van." << endl;
		return false;
	}
}

bool Aruhaz::addSeller(Seller* newSeller) {
	if (!isFulled()) {
		if (guardNum > 0) {
			People.push_back(newSeller);
			sellerNum++;
			cout << "Elado bement a boltba." << endl;
			return true;
		}
		else {
			cout << "Nincs or a boltan." << endl;
			return false;
		}
	}
	else {
		cout << "Az aruhaz tele van." << endl;
		return false;
	}
}

bool Aruhaz::addBuyer(Buyer* newBuyer) {
	if (!isFulled()) {
		if (sellerNum > 0) {
			People.push_back(newBuyer);
			cout << "Vevo bement a boltba." << endl;
			return true;
		}
		else {
			cout << "Nincs elado a boltan." << endl;
			return false;
		}
	}
	else {
		cout << "Az aruhaz tele van." << endl;
		return false;
	}
}

void Aruhaz::deleteGuard() {
	if(guardNum > 1){
		for (int i = 0; i < People.size(); i++)
			if (People[i]->whatIsMyRole() == "Or") {
				delete People[i];
				People.erase(People.begin() + i);
			}
		cout << "Egy or kilepett a boltbol" << endl;
		guardNum--;
	}
	else 
	if (guardNum == 1) {
		if (People.size() == 1) {
			delete People[0];
			People.erase(People.begin());
			cout << "Az utolso Or elhagyta a boltot." << endl;
			guardNum--;
		}else
			cout << "Van meg bent elado vagy/es vevo, az utolso Or nem hagyhatja el a boltot." << endl;
	}
	else {
		cout << "Nincs Or a boltban." << endl;
	}
}

void Aruhaz::deleteSeller() {
	if (sellerNum > 1) {
		for (int i = 0; i < People.size(); i++)
			if (People[i]->whatIsMyRole() == "Elado") {
				delete People[i];
				People.erase(People.begin() + i);
			}
		cout << "Egy elado kilepett a boltbol" << endl;
		sellerNum--;
	}else
	if (sellerNum == 1) {
		bool isThereBuyer = false;
		for (int i = 0; i < People.size(); i++)
			if (People[i]->whatIsMyRole() == "Vevo")
				isThereBuyer = true;
		if (!isThereBuyer) {
			for (int i = 0; i < People.size(); i++)
				if (People[i]->whatIsMyRole() == "Elado") {
					delete People[i];
					People.erase(People.begin() + i);
				}
			cout << "Az utolso Elado elhagyta a boltot." << endl;
			sellerNum--;
		}
	}
	else {
		cout << "Nincs Elado a boltban." << endl;
	}
}

void Aruhaz::deleteBuyer() {
	bool isThereBuyer = false;
	for (int i = 0; i < People.size(); i++)
		if (People[i]->whatIsMyRole() == "Vevo") {
			delete People[i];
			People.erase(People.begin() + i);
			isThereBuyer = true;
		}
	if(isThereBuyer)
		cout << "Egy Vevo elhagyta a boltot." << endl;
	else
		cout << "Nincs Vevo a boltban." << endl;
}

void Aruhaz::save(std::ostream& os) const{
	for (int i = 0; i < People.size(); i++)
		People[i]->save(os);
}

void Aruhaz::load(std::istream &is) {
	for (int i = 0; i < People.size(); i++)
		delete People[i];
	People.clear();

	Person *uj;
	uj = Person::beolvas(is);
	while (uj) {
		People.push_back(uj);
		uj = Person::beolvas(is);
	}
}

void Aruhaz::kiir() {
	cout << "ARUHAZ NEPESSEGE: " << endl;
	for (int i = 0; i < People.size(); i++)
		cout << People[i]->whatIsMyRole() << endl;
}

Aruhaz::~Aruhaz() {
	for (int i = 0; i < People.size(); i++) {
		delete People[i];
	}
}