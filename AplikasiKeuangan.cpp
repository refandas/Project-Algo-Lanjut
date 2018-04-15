//============================================================================
// Name        : AplikasiKeuangan.cpp
// Author      : refanda, nico
//============================================================================

#include <iostream>
#include <stdlib.h>
using namespace std;

void manajemenKeuangan(short menuManajKeuangan);
void laporanKeuangan(short menuLaporKeuangan);
void pencarianKeuangan();
void rencanaKeuangan();

typedef struct {
	int pemasukan,pengeluaran;
	string keterangan;
} tipe1;
tipe1 manajUang;

int main() {
	short menuUtama, menuManajKeuangan, balikKeluar, menuLaporKeuangan;
	char ulangMenuUtama;
	bool kembali;

	do {
	cout << "\t\t=== Aplikasi Keuangan ===" << endl;
	cout << "\nMenu : \n1. Manajemen Keuangan \n2. Laporan Keuangan \n3. Pencarian \n4. Rencana Keuangan" << endl;
	cout << "Pilih menu : "; cin >> menuUtama;

		switch(menuUtama) {
			case 1:
				//Menu manaj keuangan
				do {
					cout << "\t\t=== Manajemen Keuangan ===" << endl;
					cout << "1. Pendapatan \n2. Pengeluaran \n3. Kembali" << endl;
					cout << "Pilih (1..3) : "; cin >> menuManajKeuangan;				
					manajemenKeuangan(menuManajKeuangan);	//proses
	
					if(menuManajKeuangan<3) {
						cout << "\n1. Kembali \n2. Keluar \n(1/2) "; cin >> balikKeluar;
						cin.ignore();
						if(balikKeluar==2)
							exit(0);
					} else if(menuManajKeuangan==3) {
						kembali=true;
						break;
					}
				} while(menuManajKeuangan>3||balikKeluar==1);
				break;
			case 2:
				cout << "\t\t === Laporan Keuangan ===" << endl;
				cout << "\n Urutkan berdasarkan : " << endl;
				cout << "1. Waktu transaksi \n2. Biaya terbesar \n3. Kembali" << endl;
				cout << "Pilih (1..3) : "; cin >> menuLaporKeuangan;
				laporanKeuangan(menuLaporKeuangan);
				
				break;
			case 3:
				pencarianKeuangan();
				break;
			case 4:
				rencanaKeuangan();
				break;
			default:
				cout << "Maaf, menu yang Anda inputkan tidak ada\n" << endl;
				break;
		}

		if(menuUtama<5&&kembali==false) {
			cout << "Ulang program? (y/n) "; cin >> ulangMenuUtama;
		}
	} while(ulangMenuUtama=='y'||ulangMenuUtama=='Y'||menuUtama>4||kembali==true);
}

void manajemenKeuangan(short menuManajKeuangan) {
	string ketPendapatan;

	if(menuManajKeuangan==1) {
		cout << "\t\t    === Pendapatan ===" << endl;
		cout << "Nominal : Rp. "; cin >> manajUang.pemasukan;
		cin.ignore();
		cout << "Keterangan : \n    ";
		getline(cin, manajUang.keterangan);
		cout << "Data tersimpan" << endl;
	} else if(menuManajKeuangan==2) {
			cout << "\t\t === Pengeluaran ===" << endl;
			cout << "Nominal : Rp. "; cin >> manajUang.pengeluaran;
		} else if(menuManajKeuangan==3) {
				menuManajKeuangan=3;
			}
}

void laporanKeuangan(short menuLaporKeuangan) {
	if(menuLaporKeuangan==1)
	/*
		else if(menuLaporKeuangan==2)
			else if(menuLaporKeuangan==3)
			* */
	cout << "Fitur segera datang" << endl;
}

void pencarianKeuangan() {
	cout << "\t\t    === Pencarian ===" << endl;
	cout << "Fitur belum ada" << endl;
}

void rencanaKeuangan() {
	cout << "\t\t === Rencana Keuangan ===" << endl;
	cout << "Fitur belum ada" << endl;
}

