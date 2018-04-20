#include <iostream>
#include <fstream>
using namespace std;

class filmler : public tiyatro {
	tiyatro a;
	int girid, secim;
	string oyunadi, seans;
	koltuk otur[8];
public:
	//-----------------------------------------Kurucu Method------------------------------------------------//
	filmler() {
		musyol = "biletler.txt";
		yaz.open(musyol);
		yaz << "  ID\t\t FilmAdi\t Seans\t\tKoltuk No" << endl;
		yaz << "--------\t--------\t--------\t--------" << endl;
		imlec = yaz.tellp();
		yaz.close();
	}

	//-----------------------------------------Tiyatrodaki Oyunlar------------------------------------------------//
	void filmgetir() {
		cout << "###############################		###############################" << endl;
		cout << "#                             #		#                             #" << endl;
		cout << "#        Salon 1              #		#          Salon 2            #" << endl;
		cout << "#                             #		#                             #" << endl;
		cout << "# Oyun:Hamlet                 #		# Oyun:Kral Oidipus           #" << endl;
		cout << "# Yazar:William Shakespeare   #		# Yazar:Sophokles             #" << endl;
		cout << "# Olmak ya da olmamak..       #		# Oidipus Kompleksi kavramýna #" << endl;
		cout << "# iste butun mesele bu..      #		# ilham veren yapittir.       #" << endl;
		cout << "# Seanslar:                   #		# Seanslar:                   #" << endl;
		cout << "#     11-)  13:30             #		#         21-)  13:30         #" << endl;
		cout << "#     12-)  14:30             #		#         22-)  14:30         #" << endl;
		cout << "#                             #		#                             #" << endl;
		cout << "#                             #		#                             #" << endl;
		cout << "#                             #		#                             #" << endl;
		cout << "#                             #		#                             #" << endl;
		cout << "#    Tum Yas Gruplari         #		#       7 Yas ve Uzeri        #" << endl;
		cout << "#                             #		#                             #" << endl;
		cout << "###############################		###############################" << endl;
		cout << endl;
		cout << "###############################		###############################" << endl;
		cout << "#                             #		#                             #" << endl;
		cout << "#         Salon 3             #		#           Salon 4           #" << endl;
		cout << "#                             #		#                             #" << endl;
		cout << "# Oyun:Macbeth                #		# Oyun:Othello                #" << endl;
		cout << "# Yazar:William Shakespeare   #		# Yazar:William Shakespeare   #" << endl;
		cout << "# Olmak ya da olmamak..       #		# Olmak ya da olmamak..       #" << endl;
		cout << "# iste butun mesele bu..      #		# iste butun mesele bu..      #" << endl;
		cout << "# Seanslar:                   #		# Seanslar:                   #" << endl;
		cout << "#     31-)  13:30             #		#     41-)  13:30             #" << endl;
		cout << "#     32-)  14:30             #		#     42-)  14:30             #" << endl;
		cout << "#                             #		#                             #" << endl;
		cout << "#                             #		#                             #" << endl;
		cout << "#                             #		#                             #" << endl;
		cout << "#                             #		#                             #" << endl;
		cout << "#    Tum Yas Gruplari         #		#     Tum Yas Gruplari        #" << endl;
		cout << "#                             #		#                             #" << endl;
		cout << "###############################		###############################" << endl;
		cout << "Sivil:10 TL , Ogrenci 7 TL Uzerinden Fiyatlandirilmaktadir." << endl;
		cout << endl;
		cout << "Oyun ve Seanslari icin yaninda yazan kodlari girin. (Ornegin 4. salon 2. seans icin 42 girin.)" << endl;
	}

	//-----------------------------------------Bilet Satýn Alma------------------------------------------------//	
	void filmsec() {
		cout << "|ID" << endl; cin >> girid;
		if (a.kullanicigetir(girid)) {
			if (a.durum=="ogrenci" && a.intokuu < 7 ) { cout <<a.intokuu <<" TL Bakiyeniz bulunmakta bilet alabilmek icin bakiye yuklemeniz gerekmektedir.(Ogrenci Hesabi)" << endl;
			cout << "Bakiye yukleme ekranina yonlendiriliyorsunuz."<<endl;
			cout << "|ID\t|Yatirilacak Miktar" << endl; cin >> girid >> secim;
			a.parayatir(girid, secim);
			filmsec();
			}
			else if (a.durum == "sivil" && a.intokuu < 10) {
				cout << a.intokuu << " TL Bakiyeniz bulunmakta bilet alabilmek icin bakiye yuklemeniz gerekmektedir.(Sivil Hesabi)" << endl;
				cout << "Bakiye yukleme ekranina yonlendiriliyorsunuz." << endl;
				cout << "|ID\t|Yatirilacak Miktar" << endl; cin >> girid >> secim;
				a.parayatir(girid, secim);
				filmsec();
			}
			else {
				cout << "Oyun ve Seanslari icin yaninda yazan kodlari girin. (Ornegin 4. salon 2. seans icin 42 girin.)" << endl;
				cout << "Seciminiz: ";
				cin >> secim;
				switch (secim) {
				case 11:
					oyunadi = "Hamlet";
					seans = "13:30";
					otur[0].koltukGetir();
					otur[0].yerSec();
					otur[0].koltukGetir();
					yaz.open(musyol, ios::app);
					if (!yaz.is_open()) { cout << "dosya yazmak icin acilamiyor" << endl; }
					yaz << " " << a.intoku << "\t\t " << oyunadi << "\t\t " << seans << "\t\t " << otur[0].degis_harf <<" "<<otur[0].degis_sayi<< endl;
					yaz.close();
					a.paraeksilt(a.intoku);
					cout << "Kayit Basarili.." << endl;
					break;
				case 12:
					oyunadi = "Hamlet";
					seans = "14:30";
					otur[1].koltukGetir();
					otur[1].yerSec();
					otur[1].koltukGetir();
					yaz.open(musyol, ios::app);
					if (!yaz.is_open()) { cout << "dosya yazmak icin acilamiyor" << endl; }
					yaz << " " << a.intoku << "\t\t " << oyunadi << "\t\t " << seans << "\t\t " << otur[1].degis_harf << " " << otur[1].degis_sayi << endl;
					yaz.close();
					a.paraeksilt(a.intoku);
					cout << "Kayit Basarili.." << endl;
					break;
				case 21:
					oyunadi = "KralOidipus";
					seans = "13:30";
					otur[2].koltukGetir();
					otur[2].yerSec();
					otur[2].koltukGetir();
					yaz.open(musyol, ios::app);
					if (!yaz.is_open()) { cout << "dosya yazmak icin acilamiyor" << endl; }
					yaz << " " << a.intoku << "\t\t " << oyunadi << "\t\t " << seans << "\t\t " << otur[2].degis_harf << " " << otur[2].degis_sayi << endl;
					yaz.close();
					a.paraeksilt(a.intoku);
					cout << "Kayit Basarili.." << endl;
					break;
				case 22:
					oyunadi = "KralOidipus";
					seans = "14:30";
					otur[3].koltukGetir();
					otur[3].yerSec();
					otur[3].koltukGetir();
					yaz.open(musyol, ios::app);
					if (!yaz.is_open()) { cout << "dosya yazmak icin acilamiyor" << endl; }
					yaz << " " << a.intoku << "\t\t " << oyunadi << "\t\t " << seans << "\t\t " << otur[3].degis_harf << " " << otur[3].degis_sayi << endl;
					yaz.close();
					a.paraeksilt(a.intoku);
					cout << "Kayit Basarili.." << endl;
					break;
				case 31:
					oyunadi = "Macbeth";
					seans = "13:30";
					otur[4].koltukGetir();
					otur[4].yerSec();
					otur[4].koltukGetir();
					yaz.open(musyol, ios::app);
					if (!yaz.is_open()) { cout << "dosya yazmak icin acilamiyor" << endl; }
					yaz << " " << a.intoku << "\t\t " << oyunadi << "\t\t " << seans << "\t\t " << otur[4].degis_harf << " " << otur[4].degis_sayi << endl;
					yaz.close();
					a.paraeksilt(a.intoku);
					cout << "Kayit Basarili.." << endl;
					break;
				case 32:
					oyunadi = "Macbeth";
					seans = "14:30";
					otur[5].koltukGetir();
					otur[5].yerSec();
					otur[5].koltukGetir();
					yaz.open(musyol, ios::app);
					if (!yaz.is_open()) { cout << "dosya yazmak icin acilamiyor" << endl; }
					yaz << " " << a.intoku << "\t\t " << oyunadi << "\t\t " << seans << "\t\t " << otur[5].degis_harf << " " << otur[5].degis_sayi << endl;
					yaz.close();
					a.paraeksilt(a.intoku);
					cout << "Kayit Basarili.." << endl;
					break;
				case 41:
					oyunadi = "Othello";
					seans = "13:30";
					otur[6].koltukGetir();
					otur[6].yerSec();
					otur[6].koltukGetir();
					yaz.open(musyol, ios::app);
					if (!yaz.is_open()) { cout << "dosya yazmak icin acilamiyor" << endl; }
					yaz << " " << a.intoku << "\t\t " << oyunadi << "\t\t " << seans << "\t\t " << otur[6].degis_harf << " " << otur[6].degis_sayi << endl;
					yaz.close();
					a.paraeksilt(a.intoku);
					cout << "Kayit Basarili.." << endl;
					break;
				case 42:
					oyunadi = "Othello";
					seans = "14:30";
					otur[7].koltukGetir();
					otur[7].yerSec();
					otur[7].koltukGetir();
					yaz.open(musyol, ios::app);
					if (!yaz.is_open()) { cout << "dosya yazmak icin acilamiyor" << endl; }
					yaz << " " << a.intoku << "\t\t " << oyunadi << "\t\t " << seans << "\t\t " << otur[7].degis_harf << " " << otur[7].degis_sayi << endl;
					yaz.close();
					a.paraeksilt(a.intoku);
					cout << "Kayit Basarili.." << endl;
					break;

				}
			}
		}
	}

	//-----------------------------------------Tüm Bileti Olanlari Getir------------------------------------------------//
	void biletgetir() {
		int degis_sayi;
		char degis_harf;
		oku.open(musyol, ios::in);
		if (!oku.is_open()) { cout << "dosya okumak icin acilamiyor" << endl; }
		oku.seekg(imlec);
		while (oku >> intoku >> oyunadi >> seans >> degis_harf >> degis_sayi) {
			a.kullanicigetir(intoku);
			cout <<"\t\t\t"<< oyunadi << " " << seans << " " << degis_harf << degis_sayi << endl;
		}
		oku.close();
	}

	//-----------------------------------------Bilet Ýade Et------------------------------------------------//
	void biletiade(int id) {
		oku.open(musyol);
		yaz.open("biletler1.txt", ios::app);
		if (!oku.is_open())
			cout << "oku dosya acilamiyor" << endl;
		if (!yaz.is_open())
			cout << "yaz dosya acilamiyor" << endl;
		oku.seekg(imlec);
		yaz << "  ID\t\t FilmAdi\t Seans\t\tKoltuk No" << endl;
		yaz << "--------\t--------\t--------\t--------" << endl;
		int degis_sayi;
		char degis_harf;
		while (oku >> intoku >> oyunadi >> seans >> degis_harf >> degis_sayi) {
			if (id == intoku)
			{
				cout << "\t\t\t" << oyunadi << " " << seans << " " << degis_harf << degis_sayi << endl;
					a.paraiadeet(id);
					for (int i = 0; i < 8; i++) { otur[i].iadeet(degis_sayi,degis_harf); }
					yaz << " " << intoku << "\t\t " << "IPTAL" << "\t\t " << "IPTAL" << "\t\t " << 0 << " " << 0 << endl;
			}
			else
				yaz << " " << a.intoku << "\t\t " << oyunadi << "\t\t " << seans << "\t\t " << degis_harf << " " << degis_sayi << endl;

		}
		cout << "Koltuk numaraniz iade alindi ve bakiyenize ucretiniz eklendi." << endl;
		oku.close();
		yaz.close();
		remove("biletler.txt");
		rename("biletler1.txt", "biletler.txt");
	}

	//-----------------------------------------Tüm Koltuklarý Getir------------------------------------------------//
	void koltuklarigetir() {
		for (int i = 0; i < 8; i++) {
			cout << endl;
			cout << "Koltuk: " << i+1 << endl;
			otur[i].koltukGetir();
		}
	}



};



