#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk Circular Linked List Perpustakaan
struct BukuNode {
    string judulBuku;
    BukuNode* next;

    // Constructor untuk isi data node
    BukuNode(string judul) {
        judulBuku = judul;
        next = nullptr;
    }
};

// Fungsi menambah buku di akhir circular linked list
BukuNode* tambahBuku(BukuNode* head, string judul) {
    BukuNode* newNode = new BukuNode(judul);

    // Jika list masih kosong
    if (head == nullptr) {
        newNode->next = newNode;
        return newNode;
    }

    // Cari node terakhir
    BukuNode* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    // Sambungkan node terakhir ke node baru
    temp->next = newNode;
    newNode->next = head;

    return head;
}

// Fungsi mencari buku berdasarkan judul
bool cariBuku(BukuNode* head, string judulDicari) {
    // Cek apakah list kosong
    if (head == nullptr) {
        return false;
    }

    BukuNode* temp = head;

    do {
        // Bandingkan judul buku
        if (temp->judulBuku == judulDicari) {
            return true;
        }

        temp = temp->next;

    } while (temp != head); // berhenti kalau sudah muter lagi ke awal

    return false;
}

int main() {
    BukuNode* head = nullptr;

    // Menambahkan data buku ke circular linked list
    head = tambahBuku(head, "Struktur Data dengan C++");
    head = tambahBuku(head, "Pengantar Algoritma");
    head = tambahBuku(head, "Pemrograman Berorientasi Objek");
    head = tambahBuku(head, "Sistem Basis Data");

    string buku1 = "Pengantar Algoritma";
    string buku2 = "Kalkulus Lanjut";

    cout << "Mencari buku '" << buku1 << "': "
         << (cariBuku(head, buku1) ? "Ditemukan" : "Tidak Ditemukan") << endl;

    cout << "Mencari buku '" << buku2 << "': "
         << (cariBuku(head, buku2) ? "Ditemukan" : "Tidak Ditemukan") << endl;

    return 0;
}