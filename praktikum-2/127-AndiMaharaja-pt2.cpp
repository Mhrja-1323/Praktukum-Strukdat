#include <iostream>
using namespace std;

struct Hewan {  
    int id;
    string nama;
    string jenis;
    float harga;
};

const int MAX = 100;
int jumlah = 0;

// ================== SWAP POINTER ==================
void swapHewan(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

// ================== TAMBAH DATA ==================
void tambahHewan(Hewan *arr) {
    cout << "\n=== Tambah Data Hewan ===\n";
    cout << "ID: ";
    cin >> (arr + jumlah)->id;
    cout << "Nama: ";
    cin >> (arr + jumlah)->nama;
    cout << "Jenis: ";
    cin >> (arr + jumlah)->jenis;
    cout << "Harga: ";
    cin >> (arr + jumlah)->harga;
    jumlah++;
}

// ================== TAMPIL DATA (POINTER) ==================
void tampilHewan(Hewan *arr) {
    cout << "\n=== Data Hewan ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "ID: " << (arr + i)->id
             << " | Nama: " << (arr + i)->nama
             << " | Jenis: " << (arr + i)->jenis
             << " | Harga: " << (arr + i)->harga << endl;
    }
}

// ================== LINEAR SEARCH ==================
void linearSearch(Hewan *arr) {
    string cari;
    cout << "\nCari nama hewan: ";
    cin >> cari;

    bool ketemu = false;
    for (int i = 0; i < jumlah; i++) {
        if ((arr + i)->nama == cari) {
            cout << "Ditemukan: ID " << (arr + i)->id << endl;
            ketemu = true;
        }
    }

    if (!ketemu) cout << "Tidak ditemukan!\n";
}

// ================== FIBONACCI SEARCH ==================
void fibonacciSearch(Hewan *arr) {
    int x;
    cout << "\nCari ID hewan: ";
    cin >> x;

    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < jumlah) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibMMm2, jumlah - 1);

        // tampil proses iterasi
        cout << "Cek index: " << i << endl;

        if ((arr + i)->id < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if ((arr + i)->id > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else {
            cout << "Ditemukan di index " << i << endl;
            return;
        }
    }

    if (fibMMm1 && (arr + offset + 1)->id == x)
        cout << "Ditemukan di index " << offset + 1 << endl;
    else
        cout << "Tidak ditemukan\n";
}

// ================== BUBBLE SORT (NAMA) ==================
void bubbleSort(Hewan *arr) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if ((arr + j)->nama > (arr + j + 1)->nama) {
                swapHewan(arr + j, arr + j + 1);
            }
        }
    }
    cout << "Berhasil diurutkan (Nama A-Z)\n";
}

// ================== SELECTION SORT (HARGA) ==================
void selectionSort(Hewan *arr) {
    for (int i = 0; i < jumlah - 1; i++) {
        int min = i;
        for (int j = i + 1; j < jumlah; j++) {
            if ((arr + j)->harga < (arr + min)->harga) {
                min = j;
            }
        }
        swapHewan(arr + i, arr + min);
    }
    cout << "Berhasil diurutkan (Harga termurah)\n";
}

// ================== MAIN ==================
int main() {
    Hewan data[MAX];
    int pilih;

    do {
        cout << "\n=== PAWCARE PETSHOP ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampil Data\n";
        cout << "3. Cari Nama (Linear)\n";
        cout << "4. Cari ID (Fibonacci)\n";
        cout << "5. Sort Nama (Bubble)\n";
        cout << "6. Sort Harga (Selection)\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1: tambahHewan(data); break;
            case 2: tampilHewan(data); break;
            case 3: linearSearch(data); break;
            case 4: fibonacciSearch(data); break;
            case 5: bubbleSort(data); break;
            case 6: selectionSort(data); break;
        }

    } while (pilih != 0);

    return 0;
}