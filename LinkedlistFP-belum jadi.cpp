
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;


struct administrator {
    string username, password;
};

administrator admin;


struct event {
    string namaEvent;
    int kapasitas;
    string waktu;
    string tempat;
    int id;
    event* jenisHarga;
    event* next;
};
event* headEvent, * tail, * cur, * newNode, * del, * before;

struct category : event {b        
    string kategori;
    int harga;
    category* next;
};
category* newNodeCategory, * curTicket, * headCategory, *tailCategory;




struct ticket {
    string namaLengkap;
    string nomorPonsel;
    char jenisKelamin;
    int tanggalLahir;
    string namaEvent;
    ticket* next;
};
ticket* headTicket,* tailTicket;

//deklarasi ID event
int idEvent = 1;

//deklarasi kategori event;
int jumlahKategori;

void createEvent(string namaEvent, int kapasitas, string waktu, string tempat,int jumlahKategori) {
    if(headEvent==NULL){
        string kategory;
        int harga;
        headEvent = new event();
        headEvent->namaEvent = namaEvent;
        headEvent->kapasitas = kapasitas;
        headEvent->tempat = tempat;
        headEvent->waktu = waktu;
        for (int i = 0; i < jumlahKategori; i++) {
            if (i == 0) {
                newNodeCategory = new category;
                cout << "Masukan Nama kategory ke-" <<i << ":"; cin >> kategory; cout << endl;
                cout << "Masukan Harga Kategory ke-" << i << ":"; cin >> harga; cout << endl;
                newNodeCategory->kategori = kategory;
                newNodeCategory->harga = harga;
                newNodeCategory->next = NULL;
                tailCategory = newNodeCategory;
                headEvent->jenisHarga = newNodeCategory;
            }
            else {
                newNodeCategory = new category;
                cout << "Masukan Nama kategory ke-" << i << ":"; cin >> kategory; cout << endl;
                cout << "Masukan Harga Kategory ke-" << i << ":"; cin >> harga; cout << endl;
                newNodeCategory->kategori = kategory;
                newNodeCategory->harga = harga;
                newNodeCategory->next = NULL;
                tailCategory->next = newNodeCategory;
                tailCategory = newNodeCategory;
            }
            
        }
        
        headEvent->next = NULL;
        tail = headEvent;
    }
    else {
        newNode = new event();
        newNode->namaEvent = namaEvent;
        newNode->kapasitas = kapasitas;
        newNode->tempat = tempat;
        newNode->waktu = waktu;
        newNode->id = idEvent;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
    idEvent++;
}

void createTicket(string namaLengkap, string nomorPonsel, char jenisKelamin, int tanggalLahir, string namaEvent) {
    headTicket = new ticket();
    headTicket->namaLengkap = namaLengkap;
    headTicket->nomorPonsel = nomorPonsel;
    headTicket->jenisKelamin = jenisKelamin;
    headTicket->tanggalLahir = tanggalLahir;
    headTicket->namaEvent = namaEvent;
    headTicket->next = NULL;
    tailTicket = headTicket;
}


void cetakEvent() {
    cur = headEvent;
    int count = 1;
    cout << "== LIST NAMA EVENT ==" << endl << endl;
    while (cur != NULL) {
        cout << count;
        cout << "Nama Event :" << cur->namaEvent << endl;
        cout << "Kapasitas:" << cur->kapasitas << endl;
        cout << "Lokasi : " << cur->tempat << endl;
        cout << "Waktu: " << cur->waktu << endl;
        cout << "Harga : " << endl;
        cout << "------------------------------------" << endl;
        curTicket = cur;
        while(curTicket->jenisHarga)
        count++;
        cur = cur->next;
    }
}

void menuEvent() {
    cout << "1. Pesan tiket" << endl;
    cout << "2. Pencarian Event" << endl;
    cout << "3. List event yang sedang dilaksanakan hari ini  " << endl;
    cout << "4. List Harga event" << endl;
    cout << "5. List Seluruh Event " << endl;
    cout << "6. Informasi lanjutan" << endl;
    cout << "7. Exit Aplikasi" << endl;
};




int main()
{
    headEvent = NULL;
    headTicket = NULL;
    char Namaevent[20];
    int kapasitas;
    string tempat;
    string waktu;
    
    cout << "Masukan Nama Event:"; cin.getline(Namaevent,20);
    cout << "Masukan Kapasitas:"; cin >> kapasitas;
    cout << "Masukan Lokasi Event:"; cin >> tempat;
    cin.ignore();
    cout << "Masukan Waktu Event:"; getline(cin, waktu);
    cout << "Berapa Kategori tiket yang diinginkan?"; cin >> jumlahKategori;
    createEvent(Namaevent, kapasitas, waktu, tempat, jumlahKategori);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


/*    int login;

    cout << "APLIKASI TIKETING EVENT" << endl << endl;
    cout << "-Untuk Membuat Event login menggunakan admin" << endl;
    cout << "-Untuk Membeli Tiket, Login Menggunakan User" << endl;
    cout << "1. Anda Login Sebagai Admin" <<endl;
    cout << "2. Anda Login Sebagai User" << endl;
    cout << "Masukan piliham:"; cin >> login;
    
    if (login == 1) {
        cout << "Masukan username:"; cin >> admin.username; cout << endl;;
        cout << "Masukan password:"; cin >> admin.password; cout << endl;
        cout << "Selamat datang " << admin.username << endl << endl;
        cout << "Silahkan tuliskan event yang mau dibuat" << endl;
    }
*/