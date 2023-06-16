#include <iostream>
#include <string>
#include <conio.h>
using namespace std;


//membuat kategory harga event
struct Category {
	string jenisHargaEvent;
	float hargaEvent;
	int kuantitas;
};


//membuat booking event
struct Booking {
	string nama;
	string email;
	string tanggalLahir;
	string nomorTelepon;
	string nomorIdentitas;
	char jenisKelamin;
	string jenisKategori;
};


//membuat struct event
struct Event {
	string nama;
	string tempat;
	string tanggal;
	int id;
	int kapasitas;
	int jumlahKategori;
	int jumlahPemesan;
	Category kategori[20];
	Booking pemesanan[1000];
};



//membuat struct transaksi
struct transactions {
	int nota;
	string tanggal;
	float total;
};

//deklarasi array event
Event event[100];

//deklarasi counter event
int countEvent = 0;


//Membuat Event
void createEvent(int jumlahEvent) {
	countEvent += jumlahEvent;
	for (int i = 0; i < jumlahEvent; i++) {
		event[i].id = i;
		event[i].kapasitas = 0;
		cout << "Masukan Nama Event : "; getline(cin, event[i].nama);
		cout << "Masukan Lokasi Event : "; cin >> event[i].tempat;
		cin.ignore();
		cout << "Masukan Waktu Event : "; getline(cin, event[i].tanggal);
		cout << "Berapa Jenis Harga Kategori Tiket Yang Diinginkan : "; cin >> event[i].jumlahKategori;
		for (int j = 0; j < event[i].jumlahKategori; j++) {
			cout << "Masukan Nama Kategori Harga ke-" << j + 1 << ":";
			cin >> event[i].kategori[j].jenisHargaEvent;
			cout << endl;
			cout << "Masukan Harga Kategori " <<event[i].kategori[j].jenisHargaEvent << " :";
			cin >> event[i].kategori[j].hargaEvent;
			cout << "Masukan Kuantitas Kategori " << event[i].kategori[j].jenisHargaEvent << " :";
			cin >> event[i].kategori[j].kuantitas;
			event[i].kapasitas += event[i].kategori[j].kuantitas;
			cin.ignore();
			cout << endl;
		}
	}
}


//Cetak Seluruh Event
void printEvent() {
	for (int i = 0; i < countEvent; i++) {
		cout << "----------------------------------------" << endl;
		cout << "NO:\t" << i + 1 << endl;
		cout << "Nama Event: " << event[i].nama << endl;
		cout << "Lokasi: " << event[i].tempat << endl;
		cout << "Waktu: " << event[i].tanggal << endl;
		cout << "Kapasitas: " << event[i].kapasitas << endl;
		cout << "Harga >>>>>>>" << endl;
		for (int j = 0; j < event[i].jumlahKategori; j++)
			cout << "No." << j + 1 << " Ticket " << event[i].kategori[j].jenisHargaEvent << " Harga : Rp." << event[i].kategori[j].hargaEvent <<" sisa ticket: " << event[i].kategori[j].kuantitas << endl;
	}
}

//Cetak Semua Data Pemesan
void printBooking(int no) {
	no --;
	cout << "--------------DATA PEMESAN TIKET UNTUK EVENT " << event[no].nama << "--------------" << endl;
	for (int i = 0; i < event[no].jumlahPemesan; i++) {
		cout << "No. " << i + 1 <<". Nama Pemesan Tiket" << event[no].pemesanan[i].nama <<endl;
		cout <<"Email : " << event[no].pemesanan[i].email << endl;
		cout <<"Tanggal Lahir : " << event[no].pemesanan[i].tanggalLahir << endl;
		cout <<"Nomor Telepon : " << event[no].pemesanan[i].nomorTelepon << endl;
		cout <<"Nomor Identitas : " << event[no].pemesanan[i].nomorIdentitas << endl;
		cout <<"Jenis Kelamin : " << event[no].pemesanan[i].jenisKelamin << endl;
		cout <<"Kategori Tiket Yang Dipesan : " << event[no].pemesanan[i].jenisKategori << endl;
	}
}


int main() {
	int pilihan,jawab;
	float totalHarga = 0, uangPembayaran;
	createEvent(2);
	printEvent();
	int countTicketEvent = 0, jumlahPesanTiket = 0;
	char tambahTicket ='y', konfirmasi, gender;

	//Menu Awal
	MenuAwal:

	//menu Pesan Ticket
MenuPesanTiket:
	cout << "Masukan Ticket Mana Yang Ingin Di Pesan:"; cin >> pilihan;
	if (pilihan > countEvent || pilihan == 0) {
		cout << "Masukan Menu Event ticket yang Benar!" <<endl;
		goto MenuPesanTiket;
	}
	else {
		cout << "Anda ingin memesan ticket event" << endl;
		cout << "----------------------------------------" << endl;
		cout << "NO:\t" << pilihan << endl;
		cout << "Nama Event: " << event[pilihan - 1].nama << endl;
		cout << "Lokasi: " << event[pilihan - 1].tempat << endl;
		cout << "Waktu: " << event[pilihan - 1].tanggal << endl;
		cout << "Kapasitas: " << event[pilihan - 1].kapasitas << endl;
		cout << "Konfirmasi(y/n): "; cin >> konfirmasi;
		if (konfirmasi == 'y' || konfirmasi == 'Y') {
			cout << "Pilih Kategori Ticket yang ingin di pesan" << endl;
			for (int j = 0; j < event[pilihan-1].jumlahKategori; j++) {
				cout << "No." << j + 1 << " Ticket " << event[pilihan-1].kategori[j].jenisHargaEvent << " Harga : Rp." << event[pilihan-1].kategori[j].hargaEvent << " sisa ticket: " << event[pilihan-1].kategori[j].kuantitas << endl;
			}
			cout << "Jawab: "; cin >> jawab;
			cin.ignore();
			cout << "Anda Akan Memesan Tiket Event " << event[pilihan - 1].nama << " Dengan Kategori " << event[pilihan-1].kategori[jawab-1].jenisHargaEvent << " Seharga : Rp. " << event[pilihan-1].kategori[jawab-1].hargaEvent <<endl;
			while (tambahTicket != 'n') {
				if (tambahTicket == 'y') {
					InputData:
					cout << "-------INPUT IDENTITAS------" << endl;
					cout << "Masukan Nama : "; getline(cin, event[pilihan - 1].pemesanan[countTicketEvent].nama);
					cout << "Masukan Email : "; getline(cin, event[pilihan - 1].pemesanan[countTicketEvent].email);
					cout << "Masukan Tanggal lahir : "; getline(cin, event[pilihan - 1].pemesanan[countTicketEvent].tanggalLahir);
					cout << "Masukan Nomor Telepon : "; getline(cin, event[pilihan - 1].pemesanan[countTicketEvent].nomorTelepon);
					cout << "Masukan Nomor Identitas : "; getline(cin, event[pilihan - 1].pemesanan[countTicketEvent].nomorIdentitas);
					cout << "Masukan Jenis Kelamin(L/P) : "; cin >> event[pilihan - 1].pemesanan[countTicketEvent].jenisKelamin;
					cin.ignore();
					cout << "Data dibawah ini sudah benar? " << endl;
					cout << "----------------------------------------" << endl;
					cout << "Nama : " << event[pilihan - 1].pemesanan[countTicketEvent].nama << endl;
					cout << "Email : " << event[pilihan - 1].pemesanan[countTicketEvent].email << endl;
					cout << "Tanggal Lahir : " << event[pilihan - 1].pemesanan[countTicketEvent].tanggalLahir << endl;
					cout << "Nomor Telepon : " << event[pilihan - 1].pemesanan[countTicketEvent].nomorTelepon << endl;
					cout << "Nomor Identitas : " << event[pilihan - 1].pemesanan[countTicketEvent].nomorIdentitas << endl;
					cout << "Jenis Kelamin : " << event[pilihan - 1].pemesanan[countTicketEvent].jenisKelamin << endl;
					cout << "Konfirmasi (y/n) :"; cin >> konfirmasi;
					cin.ignore();
					if (konfirmasi == 'n') {
						goto InputData;
					}
					else if (konfirmasi == 'y') {
						countTicketEvent++;
						jumlahPesanTiket++;
						event[pilihan - 1].kategori[jawab - 1].kuantitas--;
						totalHarga += event[pilihan - 1].kategori[jawab - 1].hargaEvent;
						event[pilihan - 1].pemesanan[countTicketEvent].jenisKategori = event[pilihan - 1].kategori[jawab - 1].jenisHargaEvent;
						cout << "Apakah ingin menambah ticket lagi?" << endl;
						cout << "Jawab(y/n): "; cin >> tambahTicket;
						cin.ignore();
					}
				}
				else {
					cout << "Jawab jawaban yang benar!" << endl;
					cout << "Apakah ingin menambah ticket lagi ? " << endl;
					cout << "Jawab(y/n): "; cin >> tambahTicket; 
				}
			}
		}
		else {
			goto MenuPesanTiket;
		}
	}

//Checkout event
Checkout:
	cout << "Anda Memesan " << jumlahPesanTiket  <<" Tiket Event " << event[pilihan - 1].nama << "  Dengan Jumlah Total Pembayaran Adalah Rp. " << totalHarga <<endl;
	cout << "Apakah ingin lanjut?" << endl;
	cout << " Jawab (y/n):"; cin >> konfirmasi;
	if (konfirmasi == 'y' || pilihan == 'Y') {
		do {
			cout << " Masukan jumlah uang anda:"; cin >> uangPembayaran;
			if (uangPembayaran < totalHarga) {
				cout << "Uang anda kurang" << endl;
				cout << "Masukan jumlah uang pembayaran yang benar!" << endl;
				cin.get();
			}
		} while (uangPembayaran < totalHarga);
		cout << "Pemesanan tiket event " << event[pilihan - 1].nama  << " Sudah berhasil." << endl;
		event[pilihan - 1].jumlahPemesan += jumlahPesanTiket;
	}
	else if (pilihan == 'n' || pilihan == 'N') {
		cout << "Anda Telah Membatalkan Transaksi Pesan Tiket";
		countTicketEvent -= jumlahPesanTiket;
		jumlahPesanTiket -= jumlahPesanTiket;
		goto MenuAwal;
	}
	printEvent();
	cout << "Mencetak Booking Event Nomor 1" << endl;
	printBooking(1);

}