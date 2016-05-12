#pragma once
#include<iostream>
#include<vector>
#include"Person.h"
#include"Guard.h"
#include"Buyer.h"
#include"Seller.h"

class Aruhaz {
private:
	int guardNum;
	int sellerNum;
	int cap;
	std::vector<Person*> People;

public:
	Aruhaz(int cap) :guardNum(0), sellerNum(0), cap(cap) {
		
	}

	int getGuardNum() {
		return guardNum;
	}

	int getSellerNum() {
		return sellerNum;
	}

	bool isFulled() {
		if (People.size() == cap)
			return true;
		return false;
	}

	bool addGuard(Guard*);
	bool addSeller(Seller*);
	bool addBuyer(Buyer*);

	void deleteGuard();
	void deleteSeller();
	void deleteBuyer();

	void save(std::ostream &os) const;
	void load(std::istream &is);

	void kiir();

};