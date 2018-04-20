#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class tiyatro{
	
public:
	int id = 5000,imlec,intoku,bakiye,intokuu;
	string ad, soyad, durum,musyol;
	ifstream oku;
	ofstream yaz;
public:
	//-----------------------------------------Kurucu Method------------------------------------------------//
	tiyatro() {
		musyol = "musteriler.txt";
		yaz.open(musyol);
		yaz << "  ID\t\t   AD\t\t SOYAD\t\tDurum\t\t Bakiye" << endl;
		yaz << "--------\t--------\t--------\t--------\t--------" << endl;
		imlec = yaz.tellp();
		yaz.close();
		bakiye = 0;
	}

	//-----------------------------------------Kullanýcý Txt Yazdýrma------------------------------------------------//
	int kullaniciekle() {
		yaz.open(musyol,ios::app);
		if (!yaz.is_open()) { cout << "dosya yazmak icin acilamiyor" << endl; return 0; }
		cout << endl;
		cout << "|Ad\t|Soyad\t|Durum(sivil/ogrenci)" << endl;
		cin >> ad >> soyad >> durum;
		yaz << " " << id << "\t\t " << ad << "\t\t " << soyad << "\t\t " << durum << "\t\t " << bakiye << endl;
		cout << "Kayit Basarili ID numaraniz: "; cout << id<<endl;
		yaz.close();
		id++;
		return 1;
	}

	//-----------------------------------------Tüm Kullanýcýlarý Ekrana Getirme------------------------------------------------//
	int kullanicigetir() {
		oku.open(musyol,ios::in);
		if (!oku.is_open()) { cout << "dosya okumak icin acilamiyor" << endl; return 0; }
		oku.seekg(imlec);
		while (oku >> intoku >> ad >> soyad >> durum>> intokuu) {
			cout << intoku << " " << ad << " " << soyad << " " << durum <<" "<< intokuu <<endl;
		}
		oku.close();
		return 1;
	}

	//-----------------------------------------Belirli Bir Kullanýcýyý Ekrana Getirme------------------------------------------------//
	int kullanicigetir(int gelenid) {
		oku.open(musyol, ios::in);
		if (!oku.is_open()) { cout << "dosya okumak icin acilamiyor" << endl; return 0; }
		oku.seekg(imlec);
		bool a = false;
		while (oku >> intoku >> ad >> soyad >> durum >> intokuu) {
			if (intoku == gelenid) { cout << intoku << " " << ad << " " << soyad << " " << durum << " " << intokuu << endl; a = true; oku.close(); return 1; }
		}
		oku.close();
		if (!a){cout << "Kayit bulunamadi."<<endl; return 0;} else return 1;
	}

	//-----------------------------------------Para Yatirma------------------------------------------------//
	void parayatir(int id, float gelenbakiye)
	{
		oku.open(musyol);
		yaz.open("musteriler1.txt",ios::app);
		if (!oku.is_open())
			cout << "oku dosya acilamiyor" << endl;

		if (!yaz.is_open())
			cout << "yaz dosya acilamiyor" << endl;
		bool a = false;
		oku.seekg(imlec);
		yaz << "  ID\t\t   AD\t\t SOYAD\t\tDurum\t\t Bakiye" << endl;
		yaz << "--------\t--------\t--------\t--------\t--------" << endl;
		while (oku >> intoku >> ad >> soyad >> durum >> intokuu)
		{
			if (id == intoku)
			{
				intokuu = intokuu + gelenbakiye;
				yaz << " " << intoku << "\t\t " << ad << "\t\t " << soyad << "\t\t " << durum << "\t\t " << intokuu << endl; a = true;
				cout << "Paraniz basariyla bakiyenize eklendi."<<endl;
			}
			else
				yaz << " " << intoku << "\t\t " << ad << "\t\t " << soyad << "\t\t " << durum << "\t\t " << intokuu << endl;
		}
		if (!a) { cout << "Kayit Bulunamadi."; }
		oku.close();
		yaz.close();
		remove("musteriler.txt");
		rename("musteriler1.txt", "musteriler.txt");
	}

	//-----------------------------------------Para Ýade Etme------------------------------------------------//
	void paraiadeet(int id)
	{
		oku.open(musyol);
		yaz.open("musteriler1.txt", ios::app);
		if (!oku.is_open())
			cout << "oku dosya acilamiyor" << endl;

		if (!yaz.is_open())
			cout << "yaz dosya acilamiyor" << endl;
		oku.seekg(imlec);
		yaz << "  ID\t\t   AD\t\t SOYAD\t\tDurum\t\t Bakiye" << endl;
		yaz << "--------\t--------\t--------\t--------\t--------" << endl;
		while (oku >> intoku >> ad >> soyad >> durum >> intokuu)
		{
			if (id == intoku)
			{
				if (durum == "ogrenci") intokuu = intokuu + 7;
				else if (durum == "sivil") intokuu = intokuu + 10;
				yaz << " " << intoku << "\t\t " << ad << "\t\t " << soyad << "\t\t " << durum << "\t\t " << intokuu << endl; 
			}
			else
				yaz << " " << intoku << "\t\t " << ad << "\t\t " << soyad << "\t\t " << durum << "\t\t " << intokuu << endl;
		}
		oku.close();
		yaz.close();
		remove("musteriler.txt");
		rename("musteriler1.txt", "musteriler.txt");
	}

	//-----------------------------------------Para Eksilt------------------------------------------------//
	void paraeksilt(int id)
	{
		oku.open(musyol);
		yaz.open("musteriler1.txt", ios::app);
		if (!oku.is_open())
			cout << "oku dosya acilamiyor" << endl;

		if (!yaz.is_open())
			cout << "yaz dosya acilamiyor" << endl;
		bool a = false;
		oku.seekg(imlec);
		yaz << "  ID\t\t   AD\t\t SOYAD\t\tDurum\t\t Bakiye" << endl;
		yaz << "--------\t--------\t--------\t--------\t--------" << endl;
		while (oku >> intoku >> ad >> soyad >> durum >> intokuu)
		{
			if (id == intoku && durum=="ogrenci")
			{
				intokuu = intokuu - 7;
				yaz << " " << intoku << "\t\t " << ad << "\t\t " << soyad << "\t\t " << durum << "\t\t " << intokuu << endl; a = true;
				cout << "Ogrenci hesabi: bakiyenizden 7 TL eksiltildi." << endl;
			}
			else if (id == intoku && durum == "sivil")
			{
				intokuu = intokuu - 10;
				yaz << " " << intoku << "\t\t " << ad << "\t\t " << soyad << "\t\t " << durum << "\t\t " << intokuu << endl; a = true;
				cout << "Sivil hesabi: bakiyenizden 10 TL eksiltildi." << endl;
			}
			else
				yaz << " " << intoku << "\t\t " << ad << "\t\t " << soyad << "\t\t " << durum << "\t\t " << intokuu << endl;
		}
		if (!a) { cout << "Kayit Bulunamadi."; }
		oku.close();
		yaz.close();
		remove("musteriler.txt");
		rename("musteriler1.txt", "musteriler.txt");
	}
};