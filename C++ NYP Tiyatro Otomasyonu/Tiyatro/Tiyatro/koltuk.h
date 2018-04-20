#include <iostream>
#include <fstream>
using namespace std;
class koltuk : public tiyatro {
protected:
	char a[8][10];
	char harf[8] = { 'A', 'B' ,'C','D','E','F','G','H' };
public:
	char degis_harf;
	int degis_sayi;
	//-----------------------------------------Kurucu Method------------------------------------------------//
	koltuk() {  
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 10; j++) {
				a[i][j] = '\xDB';
			}
		}
	} 

	//-----------------------------------------Koltuk Yeri Seçme------------------------------------------------//
	void yerSec() {

		cout << "Koltuk no giriniz: ";
		cin >> degis_harf >> degis_sayi;
		bool b = false;

		for (int i = 0; i < 8; i++) {

			if (degis_harf == harf[i] && a[i][degis_sayi - 1] != '\xB0') {
				a[i][degis_sayi - 1] = '\xB0';
				b = true;

			}
		}
		if (!b) { cout << "Koltuk Dolu Baska Koltuk Secin." << endl; yerSec(); }
	}

	//-----------------------------------------Koltuk Ýade Etme------------------------------------------------//
	void iadeet(int degissayi, char degisharf) {
		for (int i = 0; i < 8; i++) {
			if (degis_harf == harf[i] && a[i][degis_sayi - 1] != '\xDB') {
				a[i][degis_sayi - 1] = '\xDB';
			}
		}
	}

	//-----------------------------------------Güncel Koltuk Durumunu Getir------------------------------------------------//
	void koltukGetir() {
		cout << endl;
		for (int i = 1; i <= 10; i++) {
			cout << i << "   ";
		}
		cout << endl;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 10; j++) {
				cout << a[i][j] << "   ";
			}
			cout << harf[i];
			cout << endl;
			cout << endl;
		}
		cout << '\xDB' << "=> Bos koltuk.";
		cout << endl << '\xB0' << "=> Dolu koltuk." << endl;
	} 

	//-----------------------------------------Koltuk Durumunu Txt Kaydet------------------------------------------------//
	void koltukKaydet() { 
		yaz.open("koltuk.txt");
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 10; j++) {
				yaz << a[i][j] << "   ";
			}
			yaz << harf[i];
			yaz << endl;
			yaz << endl;
		}
	} 
};
