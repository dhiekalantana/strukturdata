#include <iostream>
using namespace std;

int maksimal = 5;
int top = 0;
string arrayBuku[5];

bool isFull() { //jadiin kuis
    if(top == maksimal) {
        return true;
    }
    else
        return false;
}

bool isEmpty() { //jadiin kuis
    if(top == 0) {
        return true;
    }
    else
        return false;
}



//membuat fungsi push
void pushArray(string data) {
    //cek apakah masih bisa diisi arraynya
    if (isFull()==true) {
        cout << "Data Penuh" << endl;
    }
    else{
        arrayBuku[top]=data;
        top++;
    }
}

//membuat fungsi push
void popArray() {
    if(isEmpty()) {
        cout << "Data kosong" << endl;
    }
    else {
        arrayBuku[top-1] ="";
        top--;
    }
}


//Melihat atau mengintip data diposisi tertentu
void peekArray(int posisi) {
    if(isEmpty()) {
        cout << "Data kosong" << endl;
    }
    else {
        int indeks=top;
        for (int i=0; i<posisi; i++) {
            indeks--;
        }

        cout << "Data posisi ke-" << posisi << ": " << arrayBuku[indeks] << endl;
    }
}

//Menghitung banyak data pada stack
int countArray()
{
    if(isEmpty()) {
        return 0;
    }
    else {
        return top;
    }
}

//mengubah data di posisi tertentu
void changeArray(string data, int posisi)
{
    if(isEmpty()) {
        cout << "Data kosong" << endl;
    }
    else {
        int indeks=top;
        for (int i=0; i<posisi; i++) {
            indeks--;
        }
        arrayBuku[indeks]=data;
    }
}


//Menghapus atau membersihkan semua data pada stack
void destroyArray() { //kuis
    for (int i=0;i<top;i++) {
        arrayBuku[i]="";
    }
    top = 0;
}

//Mencetak semua data pada stack
void displayArray() {
    cout << "Data stack array : " << endl;
    for (int i = maksimal - 1; i >= 0; i--) {
        if(arrayBuku[i]!= "") {
        cout << "Data : " << arrayBuku[i] << endl;
        }
    }
    cout << endl;
}

int main() {
    //masukkan data 1
    pushArray("Matematika");
    displayArray();

    //masukkan data 2
    pushArray("English");
    displayArray();
    //cek apakah stack full
    cout << "apakah data full? : " << isFull() << endl;
    //cek apakah stack kosong
    cout << "apakah data kosong? : " << isEmpty() << endl;
    cout << endl;

    //masukkan data 3,4,5
    pushArray("Pemrograman");
    pushArray("Python");
    pushArray("Web Programming");
    displayArray();

    cout << "apakah data full? : " << isFull() << endl;
    cout << "apakah data kosong? : " << isEmpty() << endl;
    cout << endl;

    //Menghapus satu data ditumpukan teratas
    popArray();
    displayArray();
    cout << "apakah data full? : " << isFull() << endl;
    cout << "apakah data kosong? : " << isEmpty() << endl;
    cout << endl;

    //menghitung banyaknya array pada stack
    cout << "Banyaknya data pada stack : " << countArray() << endl;
    cout << endl;

    //mengintip array di posisi tertentu
    peekArray(1);
    cout << endl ;

    //mengganti elemen di posisi tertentu
    changeArray("Java",2);
    displayArray();

    //menghapus semua elemen pada stack
    destroyArray();
    cout << "apakah data full? : " << isFull() << endl;
    cout << "apakah data kosong? : " << isEmpty() << endl;
    cout << endl;

}

// original source code from:https://github.com/yunusfebriansyah/struktur-data/blob/main/Stack/src/Main.cpp
