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

// ================= SWAP POINTER =================
void swapHewan(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

// ================= TAMBAH DATA =================
void tambahHewan(Hewan *arr) {
    cout << "\n=== Tambah Data Hewan ===\n";
    cout << "ID            : "; cin >> (arr + jumlah)->id;
    cout << "Nama          : "; cin >> (arr + jumlah)->nama;
    cout << "Jenis         : "; cin >> (arr + jumlah)->jenis;
    cout << "Harga Periksa : "; cin >> (arr + jumlah)->harga;
    jumlah++;
}

// ================= TAMPIL DATA =================
void tampilHewan(Hewan *arr) {
    cout << "\n=== Data Hewan Pawcare ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "ID: " << (arr+i)->id
             << " | Nama: " << (arr+i)->nama
             << " | Jenis: " << (arr+i)->jenis
             << " | Harga: " << (arr+i)->harga << endl;
    }
}

// ================= LINEAR SEARCH =================
void linearSearch(Hewan *arr) {
    string cari;
    cout << "\nCari Nama Hewan : ";
    cin >> cari;

    bool ketemu = false;
    for (int i = 0; i < jumlah; i++) {
        if ((arr+i)->nama == cari) {
            cout << "Data ditemukan pada index " << i << endl;
            ketemu = true;
        }
    }

    if (!ketemu)
        cout << "Data tidak ditemukan!\n";
}

// ================= FIBONACCI SEARCH =================
void fibonacciSearch(Hewan *arr) {
    int x;
    cout << "\nCari ID Hewan : ";
    cin >> x;

    int fib2 = 0;
    int fib1 = 1;
    int fib = fib2 + fib1;

    while (fib < jumlah) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    int offset = -1;

    while (fib > 1) {
        int i = min(offset + fib2, jumlah - 1);
        cout << "Cek index: " << i << endl;

        if ((arr+i)->id < x) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if ((arr+i)->id > x) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else {
            cout << "ID ditemukan pada index " << i << endl;
            return;
        }
    }

    if (fib1 && (arr+offset+1)->id == x)
        cout << "ID ditemukan pada index " << offset+1 << endl;
    else
        cout << "Data tidak ditemukan!\n";
}

// ================= BOYER MOORE SEARCH =================
void boyerMooreSearch(Hewan *arr) {
    string pattern;
    cout << "\nCari Jenis Hewan : ";
    cin >> pattern;

    bool ketemu = false;

    for (int x = 0; x < jumlah; x++) {
        string text = (arr+x)->jenis;
        int m = pattern.length();
        int n = text.length();

        int badChar[256];
        for (int i = 0; i < 256; i++) badChar[i] = -1;
        for (int i = 0; i < m; i++) badChar[(int)pattern[i]] = i;

        int s = 0;
        while (s <= (n - m)) {
            int j = m - 1;

            while (j >= 0 && pattern[j] == text[s+j])
                j--;

            if (j < 0) {
                cout << "Jenis ditemukan pada data index " << x << endl;
                ketemu = true;
                break;
            }
            else {
                s += max(1, j - badChar[(int)text[s+j]]);
            }
        }
    }

    if (!ketemu)
        cout << "Jenis hewan tidak ditemukan!\n";
}

// ================= BUBBLE SORT =================
void bubbleSort(Hewan *arr) {
    for (int i = 0; i < jumlah-1; i++) {
        for (int j = 0; j < jumlah-i-1; j++) {
            if ((arr+j)->nama > (arr+j+1)->nama) {
                swapHewan(arr+j, arr+j+1);
            }
        }
    }
    cout << "Bubble Sort berhasil (Nama A-Z)\n";
}

// ================= SELECTION SORT =================
void selectionSort(Hewan *arr) {
    for (int i = 0; i < jumlah-1; i++) {
        int min = i;
        for (int j = i+1; j < jumlah; j++) {
            if ((arr+j)->harga < (arr+min)->harga)
                min = j;
        }
        swapHewan(arr+i, arr+min);
    }
    cout << "Selection Sort berhasil (Harga Termurah)\n";
}

// ================= QUICK SORT =================
int partition(Hewan *arr, int low, int high) {
    int pivot = (arr+high)->id;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if ((arr+j)->id < pivot) {
            i++;
            swapHewan(arr+i, arr+j);
        }
    }
    swapHewan(arr+i+1, arr+high);
    return i+1;
}

void quickSort(Hewan *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

// ================= MAIN =================
int main() {
    Hewan data[MAX];
    int pilih;

    do {
        cout << "\n===== PAWCARE PETSHOP & DOKTER HEWAN =====\n";
        cout << "1. Tambah Data Hewan\n";
        cout << "2. Tampil Data Hewan\n";
        cout << "3. Linear Search Nama\n";
        cout << "4. Fibonacci Search ID\n";
        cout << "5. Boyer Moore Search Jenis\n";
        cout << "6. Bubble Sort Nama\n";
        cout << "7. Selection Sort Harga\n";
        cout << "8. Quick Sort ID\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu : ";
        cin >> pilih;

        switch(pilih) {
            case 1: tambahHewan(data); break;
            case 2: tampilHewan(data); break;
            case 3: linearSearch(data); break;
            case 4: fibonacciSearch(data); break;
            case 5: boyerMooreSearch(data); break;
            case 6: bubbleSort(data); break;
            case 7: selectionSort(data); break;
            case 8: quickSort(data,0,jumlah-1); cout<<"Quick Sort berhasil (ID Ascending)\n"; break;
        }

    } while (pilih != 0);

    return 0;
}