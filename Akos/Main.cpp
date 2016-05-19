#include"Aruhaz.h"
#include"Guard.h"
#include"Seller.h"
#include"Buyer.h"
#include<fstream>

using namespace std;

int main() {

	Buyer *vevo;
	Seller *elado;
	Guard *or ;

	cout << "Keszitunk egy 6 fos aruhazat..." << endl;
	Aruhaz aruhaz = Aruhaz(6);
	cout << "-------------" << endl;

	cout << "Teszt 1 : megprobalunk beleptetni egy vevot" << endl;
	vevo = new Buyer();
	if (!aruhaz.addBuyer(vevo))
		delete vevo;
	cout << "-------------" << endl;

	cout << "Teszt 2 : megprobalunk beleptetni egy ort" << endl;
	or = new Guard();
	if (!aruhaz.addGuard(or))
		delete or;
	cout << "-------------" << endl;

	cout << "Teszt 3 : megprobalunk beleptetni egy vevot ismet" << endl;
	vevo = new Buyer();
	if (!aruhaz.addBuyer(vevo))
		delete vevo;
	cout << "-------------" << endl;

	cout << "Teszt 4 : megprobalunk beleptetni egy eladot " << endl;
	elado = new Seller();
	if (!aruhaz.addSeller(elado))
		delete elado;
	cout << "-------------" << endl;

	cout << "Teszt 5 : megprobalunk beleptetni egy vevot ismet " << endl;
	vevo = new Buyer();
	if (!aruhaz.addBuyer(vevo))
		delete vevo;
	cout << "-------------" << endl;

	cout << "Teszt 6 : megprobalunk kileptetni egy ort " << endl;
	aruhaz.deleteGuard();
	cout << "-------------" << endl;

	cout << "Teszt 7 : megprobalunk kileptetni egy eladot " << endl;
	aruhaz.deleteSeller();
	cout << "-------------" << endl;

	cout << "Teszt 8 : megprobalunk beleptetni 4 eladot" << endl;
	elado = new Seller();
	if (!aruhaz.addSeller(elado))
		delete elado;
	elado = new Seller();
	if (!aruhaz.addSeller(elado))
		delete elado;
	elado = new Seller();
	if (!aruhaz.addSeller(elado))
		delete elado;
	elado = new Seller();
	if (!aruhaz.addSeller(elado))
		delete elado;
	cout << endl;
	aruhaz.list();
	cout << "-------------" << endl;

	cout << "Teszt 9 : megprobalunk kileptetni ket eladot " << endl;
	aruhaz.deleteSeller();
	aruhaz.deleteSeller();
	cout << endl;
	aruhaz.list();
	cout << "-------------" << endl;

	cout << "Teszt 10 : megprobalunk beleptetni ket ort " << endl;
	or = new Guard();
	if (!aruhaz.addGuard(or ))
		delete or ;
	or = new Guard();
	if (!aruhaz.addGuard(or ))
		delete or ;
	cout << endl;
	aruhaz.list();
	cout << "-------------" << endl;

	cout << "Teszt 11 : megprobalunk kileptetni egy ort " << endl;
	aruhaz.deleteGuard();
	cout << endl;
	aruhaz.list();
	cout << "-------------" << endl;

	cout << "Teszt 12 : megprobalunk kileptetni ket ort es ket eladot" << endl;
	aruhaz.deleteGuard();
	aruhaz.deleteGuard();
	aruhaz.deleteSeller();
	aruhaz.deleteSeller();
	cout << endl;
	aruhaz.list();
	cout << "-------------" << endl;

	cout << "Teszt 13 : megprobalunk kileptetni egy vevot egy eladot es egy ort ebben a sorrendben" << endl;
	aruhaz.deleteBuyer();
	aruhaz.deleteSeller();
	aruhaz.deleteGuard();
	cout << endl;
	aruhaz.list();
	cout << "-------------" << endl;

	cout << "Teszt 14 : megprobalunk kileptetni egy ort, egy eladot es egy vevot" << endl;
	aruhaz.deleteGuard();
	aruhaz.deleteSeller();
	aruhaz.deleteBuyer();
	cout << "-------------" << endl;

	cout << "Teszt 15 : megprobalunk beleptetni egy eladot" << endl;
	elado = new Seller();
	if (!aruhaz.addSeller(elado))
		delete elado;
	cout << "-------------" << endl;

	cout << "Feltoltes : perzisztenciahoz hozzaadunk egy ort, ket eladot es harom vevot" << endl;
	or = new Guard();
	if (!aruhaz.addGuard(or ))
		delete or ;
	elado = new Seller();
	if (!aruhaz.addSeller(elado))
		delete elado;
	elado = new Seller();
	if (!aruhaz.addSeller(elado))
		delete elado;
	vevo = new Buyer();
	if (!aruhaz.addBuyer(vevo))
		delete vevo;
	vevo = new Buyer();
	if (!aruhaz.addBuyer(vevo))
		delete vevo;
	vevo = new Buyer();
	if (!aruhaz.addBuyer(vevo))
		delete vevo;
	cout << endl;
	aruhaz.list();
	cout << endl;
	cout << "-------------" << endl;
	cout << "perzisztencia tesztelese" << endl;
	cout << "adatok mentese..." << endl;
	//prototipusok regisztracioja
	Person::prototipus_hozzaad(new Buyer());
	Person::prototipus_hozzaad(new Seller());
	Person::prototipus_hozzaad(new Guard());

	try {
		ofstream os("objects");
		aruhaz.save(os);
	}
	catch(ofstream::failure e){
		cerr << "Valamiert nem tudtuk kimenteni az aruhazat.";
	}
	cout << "aruhazat sikeresen kimentettuk az objects faljba" << endl << endl;

	cout << "kimentett objektum visszaolvasasa..." << endl;
	try {
		ifstream is("objects");
		aruhaz = Aruhaz(0);
		aruhaz.load(is);
		cout << "sikeresen visszaolvastuk az aruhazat, nezzuk meg a tartalmat:" << endl;
		cout << endl;
		aruhaz.list();
	}
	catch (ifstream::failure e) {
		cerr << "Valamiert nem tudtuk visszaolvasni az aruhazat es a benne levo embereket";
	}
	cout << "-------------" << endl;

	cout << "Egy vevot kileptetunk" << endl;
	aruhaz.deleteBuyer();
	cout << endl;
	aruhaz.list();
	cout << "-------------" << endl;

	cout << "4 vevot kileptetunk" << endl;
	aruhaz.deleteBuyer();
	aruhaz.deleteBuyer();
	aruhaz.deleteBuyer();
	aruhaz.deleteBuyer();
	cout << endl;
	aruhaz.list();
	cout << "-------------" << endl;

	return 0;
}