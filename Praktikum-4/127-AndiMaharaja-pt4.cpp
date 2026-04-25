#include <iostream>
using namespace std;

// ===== NODE =====
struct Hewan {
    int id;
    string nama;
    Hewan *next;
};

// ===== QUEUE =====
struct Queue {
    Hewan *front, *rear;
};

// ===== STACK =====
struct Stack {
    Hewan *top;
};

// ===== INIT =====
void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

void initStack(Stack *s) {
    s->top = NULL;
}

// ===== CEK =====
bool isEmptyQueue(Queue *q) {
    return q->front == NULL;
}

bool isEmptyStack(Stack *s) {
    return s->top == NULL;
}

// ===== ENQUEUE =====
void enqueue(Queue *q, int id, string nama) {
    Hewan *baru = new Hewan;
    baru->id = id;
    baru->nama = nama;
    baru->next = NULL;

    if (isEmptyQueue(q)) {
        q->front = q->rear = baru;
    } else {
        q->rear->next = baru;
        q->rear = baru;
    }

    cout << "Hewan masuk antrian\n";
}

// ===== DEQUEUE =====
Hewan dequeue(Queue *q) {
    Hewan kosong;
    kosong.id = -1;

    if (isEmptyQueue(q)) {
        cout << "Antrian kosong!\n";
        return kosong;
    }

    Hewan *hapus = q->front;
    Hewan data = *hapus;

    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;

    delete hapus;
    return data;
}

// ===== PUSH =====
void push(Stack *s, Hewan h) {
    Hewan *baru = new Hewan;
    baru->id = h.id;
    baru->nama = h.nama;

    baru->next = s->top;
    s->top = baru;

    cout << "Masuk riwayat\n";
}

// ===== POP =====
void pop(Stack *s) {
    if (isEmptyStack(s)) {
        cout << "Riwayat kosong!\n";
        return;
    }

    Hewan *hapus = s->top;
    cout << "Hapus riwayat: " << hapus->nama << endl;

    s->top = s->top->next;
    delete hapus;
}

// ===== PEEK =====
void peek(Queue *q, Stack *s) {
    if (!isEmptyQueue(q)) {
        cout << "Antrian depan: " << q->front->nama << endl;
    } else {
        cout << "Antrian kosong\n";
    }

    if (!isEmptyStack(s)) {
        cout << "Riwayat terakhir: " << s->top->nama << endl;
    } else {
        cout << "Riwayat kosong\n";
    }
}

// ===== TAMPIL QUEUE =====
void tampilQueue(Queue *q) {
    if (isEmptyQueue(q)) {
        cout << "Antrian kosong\n";
        return;
    }

    cout << "Isi antrian:\n";
    Hewan *p = q->front;
    while (p != NULL) {
        cout << p->id << " - " << p->nama << endl;
        p = p->next;
    }
}

// ===== TAMPIL STACK =====
void tampilStack(Stack *s) {
    if (isEmptyStack(s)) {
        cout << "Riwayat kosong\n";
        return;
    }

    cout << "Riwayat:\n";
    Hewan *p = s->top;
    while (p != NULL) {
        cout << p->id << " - " << p->nama << endl;
        p = p->next;
    }
}

// ===== MAIN =====
int main() {
    Queue q;
    Stack s;

    initQueue(&q);
    initStack(&s);

    int pilih, id;
    string nama;
    Hewan h;

    do {
        cout << "\n=== PAWCARE PETSHOP ===\n";
        cout << "1. Tambah Antrian\n";
        cout << "2. Panggil Pasien\n";
        cout << "3. Pop Riwayat\n";
        cout << "4. Peek\n";
        cout << "5. Tampil Antrian\n";
        cout << "6. Tampil Riwayat\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
        case 1:
            cout << "ID: "; cin >> id;
            cout << "Nama: "; cin >> nama;
            enqueue(&q, id, nama);
            break;

        case 2:
            h = dequeue(&q);
            if (h.id != -1) {
                cout << "Dipanggil: " << h.nama << endl;
                push(&s, h);
            }
            break;

        case 3:
            pop(&s);
            break;

        case 4:
            peek(&q, &s);
            break;

        case 5:
            tampilQueue(&q);
            break;

        case 6:
            tampilStack(&s);
            break;
        }
    } while (pilih != 0);

    return 0;
}