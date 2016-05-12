#include"Aruhaz.h"
#include"Guard.h"
#include"Seller.h"
#include"Buyer.h"

int main() {
	Aruhaz aruhaz = Aruhaz(6);

	aruhaz.addGuard(new Guard());
	Buyer *vevo = new Buyer();
	if (!aruhaz.addBuyer(vevo))
		delete vevo;
	aruhaz.addSeller(new Seller());
	aruhaz.addSeller(new Seller());
	aruhaz.addSeller(new Seller());

	aruhaz.addBuyer(new Buyer());
	aruhaz.addBuyer(new Buyer());
	aruhaz.addBuyer(new Buyer());
	aruhaz.addBuyer(new Buyer());
	
	aruhaz.kiir();

	aruhaz.deleteSeller();	

	aruhaz.kiir();

	aruhaz.deleteGuard();

	aruhaz.kiir();

//	aruhaz.save()

	return 0;
}