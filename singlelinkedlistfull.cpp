//source:  yunusfebriansyah
#include <iostream>

using namespace std;

 //deklarasi single linked list
struct Buku {

    string judul, pengarang;
    int tahunTerbit;
    Buku *next;
};

Buku *head, *tail, *current, *newNode, *del, *before;

//menghitung jumlah node pada single linked list
int countSingleLinkedList(){
    current=head;
    int jumlah=0;
    while(current != NULL) {
        jumlah++;
        current = current-> next;
    }
    return jumlah;
}

//print single linked list
void printSingleLinkedList () {
    current = head;
      while(current != NULL) {
        cout << "Judul Buku: " << current->judul << endl;
        cout << "Pengarang: " << current->pengarang << endl;
        cout << "Tahun terbit: " << current->tahunTerbit << endl;
        cout << endl;
        current = current->next;
    }

}

//buat single linked list
void createSingleLinkedList (string judul, string pengarang, int tahunTerbit) {
    head = new Buku();
    head->judul = judul;
    head->pengarang=pengarang;
    head->tahunTerbit = tahunTerbit;
    head->next = NULL;
    tail=head;
}


//tambahkan node di akhir
void addLast(string judul, string pengarang, int tahunTerbit) {
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit= tahunTerbit;
    newNode->next = NULL;
    tail->next=newNode;
    tail=newNode;
}

//tambahkan node di awal
void addFirst(string judul, string pengarang, int tahunTerbit) {
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit= tahunTerbit;
    newNode->next=head;
    head=newNode;
}

//menghapus node pertama
void deleteFirst(){
    del = head;
    head = head->next;
    delete del;
}

//menghapus node pertama
void deleteLast(){
    del = tail;
    current = head;
    while(current->next!=tail) {
        current = current->next;
    }
    tail = current;
    tail->next = NULL;
    delete del;
}

//modifikasi node pertama
void changeFirst(string judul, string pengarang, int tahunTerbit) {
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit= tahunTerbit;
}

//modifikasi node terakhir
void changeLast(string judul, string pengarang, int tahunTerbit) {
    tail->judul = judul;
    tail->pengarang = pengarang;
    tail->tahunTerbit= tahunTerbit;
}

//tambahkan node di posisi tertentu
void addAfter(string judul, string pengarang, int tahunTerbit, int posisi) {
    //dibutuhkan kondisi untuk mengecek posisi
    // add after tidak bisa digunakan untuk posisi 1 (karena sudah ada fungsi add first)
    // add after tidak bisa digunakan untuk posisi terakhir (karena sudah ada fungsi add last)
    // add after tidak bisa digunakan menambah node di luar jumlah node yang ada
    if(posisi < 1 || posisi > countSingleLinkedList() ) {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if(posisi == 1 || posisi == countSingleLinkedList() ) {
        cout << "Data Tidak Berada di tengah" << endl;
    }
    else{
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit= tahunTerbit;
    current=head;
    int nomor=1;
    while(nomor<posisi-1) {
        current=current->next;
        nomor++;
    }
    newNode->next=current->next;
    current->next=newNode;
    }
}

//menghapus node di posisi tertentu
void deleteAfter(int posisi){
    //dibutuhkan kondisi untuk mengecek apakah delete after digunakan untuk remove node pertama 
    // atau lebih dari jumlah node
    if(posisi < 1 || posisi > countSingleLinkedList() ) {
        cout << "Posisi di luar jangkauan" << endl;
        cout << "Data tidak bisa di hapus" << endl << endl;
    }
    else if(posisi == 1 || posisi == countSingleLinkedList() ) {
        cout << "Data Tidak Berada di tengah" << endl;
        cout << "Data tidak bisa di hapus" << endl << endl;
    }
    else{
    current = head;
    int nomor=1;

    while(nomor<=posisi) {
        if(nomor == posisi-1) {
            before=current;
        }
        if(nomor == posisi) {
            del=current;
        }
        current=current->next;
        nomor++;
    }
    before->next=current;
    delete del;
    }
}



int main () {

    createSingleLinkedList("Ayat-ayat Cinta", "Habiburrahman El Shirazy", 2018);
    printSingleLinkedList();
    cout << "\n\n" << endl;
    addLast("Dilan", "Pidi Baiq", 2018);
    printSingleLinkedList(); 
    cout << "\n\n" << endl;
    addFirst("Bumi Manusia", "Pramoedya Ananta Toer", 2022);
    printSingleLinkedList(); 
    cout << "\n\n" << endl;

    deleteFirst();
    printSingleLinkedList(); 
    cout << "\n\n" << endl;

    deleteLast();
    printSingleLinkedList(); 
    cout << "\n\n" << endl;

    changeFirst("Rindu", "Tere Liye", 2022);
    printSingleLinkedList(); 
    cout << "\n\n" << endl;

    addLast("Bumi", "Tere Liye", 2018);
    printSingleLinkedList(); 
    cout << "\n\n" << endl;

    addFirst("5 Cm", "Donny Dhirgantoro", 2022);
    printSingleLinkedList(); 
    cout << "\n\n" << endl;

    addAfter("Laskar Pelangi", "Andrea Hirata", 2021, 3);
    printSingleLinkedList(); 
    cout << "\n\n" << endl;

    deleteAfter(2);
    printSingleLinkedList(); 
    cout << "\n\n" << endl;

    deleteAfter(1); //kondisi dimana menggunakan delete after di posisi 1 tidak akan di proses
    printSingleLinkedList(); 
    cout << "\n\n" << endl;

    deleteAfter(4); //kondisi dimana menggunakan delete after di posisi lebih dari jumlah node tidak akan di proses
    printSingleLinkedList(); 
    cout << "\n\n" << endl;

    //kondisi dimana menggunakan delete after di posisi lebih dari jumlah node tidak akan di proses
    addAfter("Laskar Pelangi", "Andrea Hirata", 2021, 5);
    printSingleLinkedList(); 
    cout << "\n\n" << endl;


    return 0;
}
