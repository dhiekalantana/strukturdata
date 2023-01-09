#include <iostream>
using namespace std;
	
int sequentialsearch(string barang[], int jumlah_elemen, string key){
	bool status=false;
	for (int i=0; i<jumlah_elemen; i++){
		if(key==barang[i]){
			status=true;
			return i;
			break;
		}
	}
	if (status==false)
		return -1;
}

int main (){
     //semua deklarasi di pindah keatas aja. jangan di dalem case
     // soalnya kalau di dlm case dia cuma bisa di pake pas di case itu aja
     // sedangkan kita mau pake variabelnya di semua case
	int pilihmenu;
	char menulain;
	char ulang;
	string barangygdicari;
    string daftar_barang[] = {"Baju", "Celana", "Rok", "Jaket", "Sweater"}; // sy pindahin diatas aja
    // jadi 1 variabel buat semua
	int daftar_harga[] = {50000, 100000, 100000, 150000, 200000};
    // ini juga sama sy pindahin ke atas jadi 1 variabel buat semua
    int  i, jenis, total=0;
    int kodebarang[100]; //disini bukan i tp langsung kita batasin aja max jenis barang yang diinput misal 100
	int jumlahbarang[100]; //ini juga bukan i
    int harga[100];    //ini juga bukan i
    int kembali, bayar;
	
	do{
	cout << "## Toko Baju Sederhana ## " << endl;
	cout << "========================= " << endl;
	cout << endl;
	cout << "Pilihan Menu :" << endl;
	cout << "1. Lihat Pricelist" << endl;
	cout << "2. Cari Harga Barang" << endl;
	cout << "3. Mulai Order" << endl;
	cout << "4. Bayar" << endl;
	cout << "5. Cetak Receipt" << endl;
	
	cout << "Inputkan menu : " ;
	cin >> pilihmenu;
	
	switch(pilihmenu){
		case 1:
			cout << "===== Pricelist Toko Baju Sederhana =====" << endl;
			cout << "1. Baju : Rp. 50.000" << endl;
			cout << "2. Celana : Rp. 100.000" << endl;
			cout << "3. Rok : Rp. 100.000" << endl;
			cout << "4. Jaket : Rp. 150.000" << endl;
			cout << "5. Sweater : Rp. 200.000" << endl;
			cout << endl;		
			break ;
			
		case 2:
			{

		
			int jumlah_elemen = sizeof(daftar_barang)/sizeof(daftar_barang[0]);
	
			string key;
	
			cout << "Masukan barang yang dicari (gunkan huruf kapital pada awal huruf) : ";
			cin >> key;
	
			int indeksbarang = sequentialsearch(daftar_barang, jumlah_elemen, key);
			if (indeksbarang==-1){
			cout << "Harga barang tidak tersedia" << endl;
			}
			else{
			cout << "Harga barang yang dicari adalah : " << daftar_harga[indeksbarang] << endl;
			}
			break;}
			
		case 3:	
		{
  
		//	int daftarharga[] = {0, 50000, 100000, 100000, 150000, 200000};  ini ga ush kan udh di deklarasiin diatas
			
			
				cout << "===== Pricelist Toko Baju Sederhana =====" << endl;
				cout << "1. Baju : Rp. 50.000" << endl;
				cout << "2. Celana : Rp. 100.000" << endl;
				cout << "3. Rok : Rp. 100.000" << endl;
				cout << "4. Jaket : Rp. 150.000" << endl;
				cout << "5. Sweater : Rp. 200.000" << endl;
			
				cout << "Berapa jenis barang yang ingin kamu beli : " ; 
				cin >> jenis;
				cout << endl;
	
			if (jenis<1){
				cout << endl;
				cout << "Jumlah barang tidak boleh 0 " << endl;
			}
			else {
				cout << "> Input " << jenis << " Jenis Barang : " << endl;


			for (i=0; i<jenis; i++){ // -> i nya harus mulai dari 0 karena kan array mulainya dari 0. jadi ga boleh mulai dari 1
				cout << "- Input kode barang ke-"<< i+1 << " : ";  //di kasih i+1 aja biar tetep mulai dari posisi 1
				cin >> kodebarang[i];
				cout << "Masukkan jumlah barang ke-"<< i+1 << " : "; //ini juga i+1 -> jadi nyetaknya ga input kode barang ke 0 tapi tetep input barang ke 1 
				cin >> jumlahbarang[i];
				cout << endl;
				
				harga[i]=jumlahbarang[i]*daftar_harga[kodebarang[i]-1]; //di dalam kode barang dikurang 1 soalnya kan kode barang di mulai dari 1 tp indeksnya di mulai dari 0
				cout << "total harga barang ke-" << i+1 << " : " << harga[i] << endl;
				cout << endl;
				
				total=total+harga[i];
			}
			
			cout << "Total harga yang harus dibayar : " << total << endl; //ini kenapa +1 soalnya int totalnya ga kamu sama denganin 0 pas awal2. jd mesti kita deklarasiinnya int total =0;
		}
			break;
	}
		
		case 4:
			//int bayar; -> ini sy pindahin keatas
			//int total; -> ini ga ush di definiskan lg. makanya dia berubah jadi 0 terus
			//int kembali; -> ini sy pindahin keatas
			
			cout << "Total yang harus dibayar : Rp " << total << endl;
    cout << "Masukan jumlah pembayaran : Rp ";
	cin >> bayar;
	kembali = bayar - total;
	
	if(bayar>total){
		cout << "Kembalian anda = Rp " << kembali << endl;
	}	
	else{
		cout << "Ga cukup wangnya" << endl;
	}
			break;
			
		case 5:
			cout << "=============== INVOICE ===============" << endl;
			break;
		
		default:
				cout << "Masukkan anda salah" << endl;
			}
			
		cout << "Ingin memilih menu lain (y/t) ? ";
		cin >> ulang; }
		while (ulang!='t');

	return 0;
}
