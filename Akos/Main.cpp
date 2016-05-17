#include"Aruhaz.h"
#include"Guard.h"
#include"Seller.h"
#include"Buyer.h"

using namespace std;

int main() {

	Buyer *vevo;
	Seller *elado;
	Guard *or ;

	cout << "Keszitunk egy 6 fos aruhazat..." << endl;
	Aruhaz aruhaz = Aruhaz(6);

	cout << "Teszt 1 : megprobalunk hozzaadni egy vevot" << endl;
	if (!aruhaz.addBuyer(vevo))
		delete vevo;
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