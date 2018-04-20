#include <iostream>
#include "tiyatro.h"
#include "koltuk.h"
#include "filmler.h"
using namespace std;

int main() {
	tiyatro bir;
	filmler oyun;
	int secim,girid,para;
	
anamenu:

	system("cls");
	do {
		cout << endl;
		cout << "###################################################" << endl;
		cout << "\tislem No \t\tislem" << endl;
		cout << "###################################################" << endl;
		cout << "\t1 \t\t Yeni Kayit Ekle" << endl;
		cout << "\t2 \t\t Bir Kayit Listele(id)" << endl;
		cout << "\t3 \t\t Tum Kayitlari Listele" << endl;
		cout << "\t4 \t\t Satis islemleri" << endl;
		cout << "\t5 \t\t Bakiye Ekle" << endl;
		cout << "\t9 \t\t Ekrani Temizle" << endl;
		cout << "\t0 \t\t Cikis" << endl;
		cout << "###################################################" << endl;
		cout << "istenilen islemi girin: ";
		cin >> secim;
		if (secim == 1) { bir.kullaniciekle();  }
		else if (secim == 2) {
			cout << "|ID" << endl; cin >> girid; bir.kullanicigetir(girid);		}
		else if (secim == 3) { bir.kullanicigetir(); }
		else if (secim == 4) {  goto altmenu; }
		else if (secim == 5) {
			cout << "|ID\t|Yatirilacak Miktar" << endl; cin >> girid>>para;
			bir.parayatir(girid,para);
		
		}
		else if (secim == 9) { goto anamenu; }
		else if (secim == 0) { goto son; }
	} while (true);

altmenu:

	system("cls");
	do {
		cout << endl;
		cout << "###################################################" << endl;
		cout << "\tislem No \t\tislem" << endl;
		cout << "###################################################" << endl;
		cout << "\t1 \t\t Filmleri Gor" << endl;
		cout << "\t2 \t\t Salon'a Gore Bos Yerler" << endl;
		cout << "\t3 \t\t Bilet Satin Al(Once Kayit Olunuz)" << endl;
		cout << "\t4 \t\t Ana Menu(Kayit Olabilirsiniz.)" << endl;
		cout << "\t5 \t\t Tum Bilet Alanlari Getir" << endl;
		cout << "\t6 \t\t Bilet Iptal Et" << endl;
		cout << "\t9 \t\t Ekrani Temizle" << endl;
		cout << "\t0 \t\t Cikis" << endl;
		cout << "###################################################" << endl;
		cout << "istenilen islemi girin: ";
		cin >> secim;
		if (secim == 1) { oyun.filmgetir(); }
		
		else if (secim == 2) { oyun.koltuklarigetir(); }
		else if (secim == 3) { oyun.filmsec(); }
		else if (secim == 4) { goto anamenu; }
		else if (secim == 5) { oyun.biletgetir(); }
		else if (secim == 6) { cout << "|ID" << endl; cin >> girid; oyun.biletiade(girid); }
		else if (secim == 9) { goto altmenu; }
		else if (secim == 0) { goto son; }
	} while (true);

	
son:
	cout << endl;
	cout << "Yine Bekleriz :)"<<endl;
	cout << endl;

	system("pause");
}