//============================================================================
// Name        : AplikasiKeuangan.cpp
// Author      : refanda, nico
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void manajemenKeuangan(int menuManajKeuangan);
void laporanKeuangan(int menuLaporKeuangan);
void pencarianKeuangan();
void rencanaKeuangan();
void cetakInput();

int i, j, k, jumlahMasuk, jumlahKeluar, pilihCari, pilihBiaya, pilihTanggal;
char srcTanggal[9];

typedef struct {
	int pemasukan, pengeluaran;
	char keterangan[100], waktu[9];
} tipe1;
tipe1 manajUang[100];

FILE *arsip;

int main() {
	int menuUtama, menuManajKeuangan, balikKeluar, menuLaporKeuangan;
	char ulangMenuUtama;
	bool kembali;

	do {
	cout << "\t\t=== Aplikasi Keuangan ===" << endl;
	cout << "\nMenu : \n1. Manajemen Keuangan \n2. Laporan Keuangan \n3. Pencarian \n4. Rencana Keuangan";
	cout << "\n5. Cetak Hasil Input \n6. Keluar "<< endl;
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
		case 5:
			cetakInput();
			cout << "\n1. Kembali \n2. Keluar \n(1/2) "; cin >> balikKeluar;
			cin.ignore();
			if(balikKeluar==2) exit(0);
			else  kembali=true;
			break;
		case 6:
			cout << "\nTerima Kasih telah Menggunakan Program Ini" << endl;
			cout << "Keluar Program . . ." << endl;
			exit(0);
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

void manajemenKeuangan(int menuManajKeuangan) {
	string ketPendapatan;

	if(menuManajKeuangan==1) {
		cout<<"Masukkan Jumlah Data = ";
      cin>>jumlahMasuk;
		cout << "\t === Pendapatan ===" << endl;
		arsip = fopen("dataKeuanganMasuk.txt","a");
		for(i=0;i<jumlahMasuk;i++){
			cout<<"Data "<<i+1<<endl;
			cout << "Nominal : Rp. "; cin >> manajUang[i].pemasukan;
			cout << "Waktu (dd/mm/yy) : "; cin.ignore(); cin.getline(manajUang[i].waktu,9);
			cout << "Keterangan : "; cin.getline(manajUang[i].keterangan,100);
			fwrite(&manajUang[i],sizeof(manajUang[i]),1,arsip);
		}
		fclose(arsip);
		cout << "Data tersimpan" << endl;
	} else if(menuManajKeuangan==2) {
			cout << "\t === Pengeluaran ===" << endl;
			cout<<"Masukkan Jumlah Data = ";
			cin>>jumlahKeluar;
			arsip = fopen("dataKeuanganKeluar.txt","a");
			for(i=0;i<jumlahKeluar;i++){
            cout<<"Data ke-"<<i+1<<endl;
				cout << "Nominal : Rp. "; cin >> manajUang[i].pengeluaran;
				cout << "Waktu (dd/mm/yy) : "; cin.ignore(); cin.getline(manajUang[i].waktu,9);
				cout << "Keterangan : "; cin.getline(manajUang[i].keterangan,100);
				fwrite(&manajUang[i],sizeof(manajUang[i]),1,arsip);
			}
			fclose(arsip);
		} else 
		if(menuManajKeuangan==3) {
				menuManajKeuangan=3;
				cout<<"Belum"<<endl;}
				else
				 if(menuManajKeuangan>3||menuManajKeuangan<1) 
					{cout << "Inputan Anda Salah"<<endl;
					cout<<"Kembali ke Sebelumnya"<<endl;}
			}

void laporanKeuangan(int menuLaporKeuangan) {
	if(menuLaporKeuangan==1){
		cout<<"Urutan Berdasarkan Waktu Transaksi \n";
		cout<<"COMING SOON\n";
	}
	else if(menuLaporKeuangan==2){
		cout<<"Biaya Terbesar \n";
		cout<<"Hasil Biaya Terbesar Adalah \n";
		cout<<"Belum Saatnya\n";
    }
	/*
		else if(menuLaporKeuangan==2)
			else if(menuLaporKeuangan==3)
			* */
	cout << "Fitur segera datang" << endl;
}

void pencarianKeuangan() {
	cout << "\n\t === PENCARIAN ===" << endl;
	cout << "Waktu transaksi : "; cin.ignore(); cin.getline(srcTanggal,9);
	cout << endl;
	i=0;
	arsip = fopen("dataKeuanganKeluar.txt","r");
	while(feof(arsip)==NULL) {
		fread(&manajUang[i],sizeof(manajUang[i]),1,arsip);
		i++;
	}
	string tanggal = srcTanggal;
	
	for(j=0; j<i-1; j++) {
		if(manajUang[j].waktu==tanggal) {
			cout << "----------------------------------------" << endl;
			cout << "Nominal : Rp. " << manajUang[j].pengeluaran << endl;
			cout << "Waktu (dd/mm/yy) : " << manajUang[j].waktu << endl;
			cout << "Keterangan : " << manajUang[j].keterangan << endl;
		}
	}
	cout << "----------------------------------------" << endl << endl;
	fclose(arsip);
	
}

void rencanaKeuangan() {
	cout << "\t\t === Rencana Keuangan ===" << endl;
	cout << "Fitur belum ada" << endl;
}

void cetakInput(){
	cout << "\n\t === Pendapatan ===" << endl;
	arsip = fopen("dataKeuanganMasuk.txt","r");
	
	i=0;
	while(feof(arsip)==NULL) {
		fread(&manajUang[i],sizeof(manajUang[i]),1,arsip);
		i++;
	}
	for(j=0; j<i-1; j++){
		cout << "----------------------------------------" << endl;
		cout << "Nominal : Rp. " << manajUang[j].pemasukan << endl;
		cout << "Waktu (dd/mm/yy) : " << manajUang[j].waktu << endl;
		cout << "Keterangan : " << manajUang[j].keterangan << endl;
	}
	
	fclose(arsip);
	
	cout << "----------------------------------------" << endl;
	cout << "\n\t === Pengeluaran ===" << endl;
	arsip = fopen("dataKeuanganKeluar.txt","r");
	
	i=0;
	while(feof(arsip)==NULL) {
		fread(&manajUang[i],sizeof(manajUang[i]),1,arsip);
		i++;
	}
	for(j=0; j<i-1; j++){
		cout << "----------------------------------------" << endl;
		cout << "Nominal : Rp. " << manajUang[j].pengeluaran << endl;
		cout << "Waktu (dd/mm/yy) : " << manajUang[j].waktu << endl;
		cout << "Keterangan : " << manajUang[j].keterangan << endl;
	}
	fclose(arsip);
	cout << "----------------------------------------" << endl;
	cout << endl;
}
