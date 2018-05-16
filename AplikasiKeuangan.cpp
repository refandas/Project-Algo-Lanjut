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
void biayaBesar();
void waktuTransaksi();
void biayaKecil();
void biayaKeluarbe();
void biayaKeluarke();
void ketDeposito();

int i, j, k, jumlahMasuk, jumlahKeluar, pilihCari, pilihBiaya, pilihTanggal;
char srcTanggal[9];

typedef struct {
	int pemasukan, pengeluaran;
	char keteranganma[100], keteranganke[100], waktuma[9], waktuke[9];
} tipe1;
tipe1 manajUang[100];

typedef struct {
	long double jumlahDeposito, tambahDeposito;
} depo;
depo deposito;

FILE *arsip, *arsip2, *arsip3;

int main() {
	int menuUtama, menuManajKeuangan, balikKeluar, menuLaporKeuangan;
	char ulangMenuUtama;
	bool kembali;

	do {
	cout << "\t\t=== Aplikasi Keuangan ===" << endl;
	cout << "\nMenu : \n1. Manajemen Keuangan \n2. Laporan Keuangan \n3. Pencarian \n4. Cetak Hasil Input";
	cout << "\n5. Deposito \n6. Keluar"<< endl;
	cout << "Pilih menu : "; cin >> menuUtama;
	cout << endl;
	switch(menuUtama) {
		case 1:
			//Menu manaj keuangan
			do {
				cout << "\t\t=== Manajemen Keuangan ===" << endl;
				cout << "1. Pendapatan \n2. Pengeluaran \n3. Kembali" << endl;
				cout << "Pilih (1..3) : "; cin >> menuManajKeuangan;
				manajemenKeuangan(menuManajKeuangan);	//proses

				if(menuManajKeuangan<3) {
					cout << "\n1. Kembali \n2. Keluar \nPilih (1/2) "; cin >> balikKeluar;
					cin.ignore();
					if(balikKeluar==2) exit(0);
				} else if(menuManajKeuangan==3) {
					kembali=true;
					break;
				}
			} while(menuManajKeuangan>3||balikKeluar==1);
			break;
		case 2:
			do {
				cout << "\t\t === Laporan Keuangan ===" << endl;
				cout << "\n Urutkan berdasarkan : " << endl;
				cout << "1. Waktu transaksi \n2. Biaya terbesar \n3. Kembali" << endl;
				cout << "Pilih (1..3) : "; cin >> menuLaporKeuangan;
				laporanKeuangan(menuLaporKeuangan);
				
				if(menuLaporKeuangan<3) {
					cout << "\n1. Kembali \n2. Keluar \nPilih (1/2) "; cin >> balikKeluar;
					cin.ignore();
					if(balikKeluar==2) exit(0);
				} else if(menuLaporKeuangan==3) {
						kembali=true;
						break;
					}
			} while(menuLaporKeuangan>3||balikKeluar==1);
			break;
		case 3:
			pencarianKeuangan();
			
			cout << "\n1. Kembali \n2. Keluar \nPilih (1/2) "; cin >> balikKeluar;
			cin.ignore();
			if(balikKeluar==2) exit(0);
			else  kembali=true;
			break;
		case 4:
			cetakInput();
			cout << "\n1. Kembali \n2. Keluar \nPilih (1/2) "; cin >> balikKeluar;
			
			cin.ignore();
			if(balikKeluar==2) exit(0);
			else  kembali=true;
			break;
		case 5:
			ketDeposito();
			cout << "\n1. Kembali \n2. Keluar \nPilih (1/2) "; cin >> balikKeluar;
			
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
			cout << "\nMaaf, menu yang Anda inputkan tidak ada\n" << endl;
			break;
	}

	if(menuUtama<5&&kembali==false) {
		cout << "Ulang program? (y/n) "; cin >> ulangMenuUtama;
	}
	} while(ulangMenuUtama=='y'||ulangMenuUtama=='Y'||menuUtama>4||kembali==true);
}


void biayaKeluarbe(int left, int right){
	int i=left;
	int j=right;
	tipe1 pivot,temp ;
	pivot = manajUang[(right+left)/2];

	while(i<=j){
		 while(manajUang[i].pengeluaran<manajUang[(right+left)/2].pengeluaran)
			  i++;
		 while(manajUang[j].pengeluaran>manajUang[(right+left)/2].pengeluaran)
			  j--;
	if(i<=j){
		 temp=manajUang[i];
		 manajUang[i]=manajUang[j];
		 manajUang[j]=temp;
		 i++;
		 j--;}}
	if(left<j)
		 biayaKeluarbe(left,j);
	if(i<right)
		biayaKeluarbe(i,right);
	for(i=0;i<jumlahMasuk;i++){
		cout << "\nNominal : Rp. "<<manajUang[i].pengeluaran;
		cout << "\nWaktu (dd/mm/yy) : "<<manajUang[i].waktuke;
		cout << "\nKeterangan : "<<manajUang[i].keteranganke;
	}
}

void biayaKeluarke(int left, int right){
	int i=left;
	int j=right;
	tipe1 pivot,temp ;
	pivot = manajUang[(right+left)/2];

	while(i<=j){
		 while(manajUang[i].pengeluaran>manajUang[(right+left)/2].pengeluaran)
			  i++;
		 while(manajUang[j].pengeluaran<manajUang[(right+left)/2].pengeluaran)
			  j--;
	if(i<=j){
		temp=manajUang[i];
		manajUang[i]=manajUang[j];
		manajUang[j]=temp;
		i++;
		j--;}}
	if(left<j)
		biayaKeluarke(left,j);
	if(i<right)
		biayaKeluarke(i,right);
	for(i=0;i<jumlahMasuk;i++){
		cout << "\nNominal : Rp. "<<manajUang[i].pengeluaran;
		cout << "\nWaktu (dd/mm/yy) : "<<manajUang[i].waktuke;
		cout << "\nKeterangan : "<<manajUang[i].keteranganke;
	}
}

void biayaBesar(int left, int right){
	int i=left;
	int j=right;
	tipe1 pivot,temp ;
	pivot = manajUang[(right+left)/2];

	while(i<=j){
		 while(manajUang[i].pemasukan<manajUang[(right+left)/2].pemasukan)
			  i++;
		 while(manajUang[j].pemasukan>manajUang[(right+left)/2].pemasukan)
			  j--;
	if(i<=j){
		 temp=manajUang[i];
		 manajUang[i]=manajUang[j];
		 manajUang[j]=temp;
		 i++;
		 j--;}}
	if(left<j)
		 biayaBesar(left,j);
	if(i<right)
		biayaBesar(i,right);
	for(i=0;i<jumlahMasuk;i++){
		cout << "\nNominal : Rp. "<<manajUang[i].pemasukan;
		cout << "\nWaktu (dd/mm/yy) : "<<manajUang[i].waktuma;
		cout << "\nKeterangan : "<<manajUang[i].keteranganma;
	}
}

void manajemenKeuangan(int menuManajKeuangan) {
	string ketPendapatan;

	if(menuManajKeuangan==1) {
		cout<<"Masukkan Jumlah Data = ";
      cin>>jumlahMasuk;
		cout << "\t === Pendapatan ===" << endl;
		arsip = fopen("dataKeuanganMasuk.txt","a");
		for(i=0;i<jumlahMasuk;i++){
			cout << "\nData " << i+1 << endl;
			cout << "Nominal : Rp. "; cin >> manajUang[i].pemasukan;
			cout << "Waktu (dd/mm/yy) : "; cin.ignore(); cin.getline(manajUang[i].waktuma,9);
			cout << "Keterangan : "; cin.getline(manajUang[i].keteranganma,100);
			fwrite(&manajUang[i],sizeof(manajUang[i]),1,arsip);
		}
		fclose(arsip);
		cout << "\n----------------" << endl;
		cout << "=Data tersimpan=" << endl;
		cout << "----------------" << endl;
	} else if(menuManajKeuangan==2) {
			cout << "\n\t === Pengeluaran ===" << endl;
			cout << "Masukkan Jumlah Data = ";
			cin >> jumlahKeluar;
			arsip2 = fopen("dataKeuanganKeluar.txt","a");
			for(i=0;i<jumlahKeluar;i++){
            cout << "\nData ke-" << i+1 << endl;
				cout << "Nominal : Rp. "; cin >> manajUang[i].pengeluaran;
				cout << "Waktu (dd/mm/yy) : "; cin.ignore(); cin.getline(manajUang[i].waktuke,9);
				cout << "Keterangan : "; cin.getline(manajUang[i].keteranganke,100);
				fwrite(&manajUang[i],sizeof(manajUang[i]),1,arsip2);
			}
			fclose(arsip2);
		} else
		if(menuManajKeuangan==3) {
				menuManajKeuangan=3;
				cout<<"Belum"<<endl;}
				else
				 if(menuManajKeuangan>3||menuManajKeuangan<1)
					{cout << "Inputan Anda Salah"<<endl;
					cout<<"Kembali ke Sebelumnya"<<endl;}
			}

void biayaKecil(int left, int right){
	int i=left;
	int j=right;
	tipe1 pivot,temp ;
	pivot = manajUang[(right+left)/2];

	while(i<=j){
		 while(manajUang[i].pemasukan>manajUang[(right+left)/2].pemasukan)
			  i++;
		 while(manajUang[j].pemasukan<manajUang[(right+left)/2].pemasukan)
			  j--;
	if(i<=j){
		 temp=manajUang[i];
		 manajUang[i]=manajUang[j];
		 manajUang[j]=temp;
		 i++;
		 j--;}}
	if(left<j)
		 biayaKecil(left,j);
	if(i<right)
		biayaKecil(i,right);
  for(i=0;i<jumlahMasuk;i++){
	  cout << "\nNominal : Rp. "<<manajUang[i].pemasukan;
	  cout << "\nWaktu (dd/mm/yy) : "<<manajUang[i].waktuma;
	  cout << "\nKeterangan : "<<manajUang[i].keteranganma;
	}
}

void ketDeposito() {
	int totalPemasukan=0, totalPengeluaran=0;
	arsip = fopen("dataKeuanganMasuk.txt","r");
	arsip2 = fopen("dataKeuanganKeluar.txt","r");
	arsip3 = fopen("Deposito.txt","w+");
	
	i=0;
	while(fread(&manajUang[i],sizeof(manajUang[i]),1,arsip)) {
		totalPemasukan += manajUang[i].pemasukan;
		i++;
	}
	i=0;
	while(fread(&manajUang[i],sizeof(manajUang[i]),1,arsip2)) {
		totalPengeluaran += manajUang[i].pengeluaran;
		i++;
	}
		
	fread(&deposito,sizeof(deposito),1,arsip3);
	deposito.jumlahDeposito += (totalPemasukan-totalPengeluaran);
	cout << "Uang sekarang : Rp." << deposito.jumlahDeposito;
	cout << endl;
	
	fclose(arsip);
	fclose(arsip2);
	fclose(arsip3);
}

void laporanKeuangan(int menuLaporKeuangan) {
	if(menuLaporKeuangan==1){
		cout<<"Urutan Berdasarkan Waktu Transaksi \n";
    cout<<"Failed"<<endl;
	}
	else if(menuLaporKeuangan==2){
		cout<<"Pengurutan Biaya Pemasukkan Terkecil \n";
       biayaBesar(0,jumlahMasuk-1);
       cout<<"\n\n";
		 cout<<"Pengurutan Biaya Terbesar \n";
		 biayaKecil(0,jumlahMasuk-1);

		 cout<<"\n\n";
		 cout<<"Pengurutan Biaya Pengeluaran Terkecil \n";
		 biayaKeluarbe(0,jumlahKeluar-1);

		 cout<<"\n\n";
		 cout<<"Pengurutan Biaya Pengeluaran Terbesar \n";
		 biayaKeluarke(0,jumlahKeluar-1);
    }
}

void pencarianKeuangan() {
	cout << "\n\t === PENCARIAN ===" << endl;
	cout << "Waktu transaksi : "; cin.ignore(); cin.getline(srcTanggal,9);
	cout << endl;
	arsip = fopen("dataKeuanganMasuk.txt","r");
	arsip2 = fopen("dataKeuanganKeluar.txt","r");
	
	string tanggal = srcTanggal;
	
	i=0;
	while(fread(&manajUang[i],sizeof(manajUang[i]),1,arsip)) {
		if(manajUang[i].waktuma==tanggal) {
			cout << "----------------------------------------" << endl;
			cout << "== Pendapatan" << endl;
			cout << "Nominal : Rp. " << manajUang[i].pemasukan << endl;
			cout << "Waktu (dd/mm/yy) : " << manajUang[i].waktuma << endl;
			cout << "Keterangan : " << manajUang[i].keteranganma << endl;
		}
		i++;
	}
	j=0;
	while(fread(&manajUang[j],sizeof(manajUang[j]),1,arsip2)) {
		if(manajUang[j].waktuke==tanggal) {
			cout << "----------------------------------------" << endl;
			cout << "== Pengeluaran" << endl;
			cout << "Nominal : Rp. " << manajUang[j].pengeluaran << endl;
			cout << "Waktu (dd/mm/yy) : " << manajUang[j].waktuke << endl;
			cout << "Keterangan : " << manajUang[j].keteranganke << endl;
		}
		j++;
	}
	cout << "----------------------------------------" << endl << endl;
	fclose(arsip);
	fclose(arsip2);
}

void cetakInput(){
	arsip = fopen("dataKeuanganMasuk.txt","r");
	
	cout<<"\n\t === Pemasukkan ==="<<endl;
	i=0;
	while(fread(&manajUang[i],sizeof(manajUang[i]),1,arsip)) {
		cout << "----------------------------------------" << endl;
		cout << "Nominal : Rp. " << manajUang[i].pemasukan << endl;
		cout << "Waktu (dd/mm/yy) : " << manajUang[i].waktuma<< endl;
		cout << "Keterangan : " << manajUang[i].keteranganma << endl;
		i++;
	}
	fclose(arsip);
//////////////////////////////////////////////////////////////////////////

	arsip2 = fopen("dataKeuanganKeluar.txt","r");
	
	cout << "----------------------------------------" << endl;
	cout << "\n\t === Pengeluaran ===" << endl;
	j=0;
	while(fread(&manajUang[j],sizeof(manajUang[j]),1,arsip2)) {
		cout << "----------------------------------------" << endl;
		cout << "Nominal : Rp. " << manajUang[j].pengeluaran << endl;
		cout << "Waktu (dd/mm/yy) : " << manajUang[j].waktuke << endl;
		cout << "Keterangan : " << manajUang[j].keteranganke << endl;
		j++;
	}
	fclose(arsip2);
	cout << "----------------------------------------" << endl;
	cout << endl;
}
