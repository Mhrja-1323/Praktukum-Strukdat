//127 (ganjil)

#include <iostream>
using namespace std;

#define MAX 5

// Struct data hewan
struct Hewan {
    int id;
    string nama;
};

// ===== QUEUE =====
struct Queue {
    Hewan data[MAX];
    int front, rear;
};

// ===== STACK =====
struct Stack {
    Hewan data[MAX];
    int top;
};

// ===== INIT =====
void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

void initStack(Stack *s) {
    s->top = -1;
}

// ===== CEK =====
bool isFullQueue(Queue *q) {
    return q->rear == MAX - 1;
}

bool isEmptyQueue(Queue *q) {
    return q->front == -1;
}

bool isFullStack(Stack *s) {
    return s->top == MAX - 1;
}

bool isEmptyStack(Stack *s) {
    return s->top == -1;
}

// ===== ENQUEUE =====
void enqueue(Queue *q, Hewan h) {
    if (isFullQueue(q)) {
        cout << "Antrian penuh!\n";
        return;
    }
    if (isEmptyQueue(q)) {
        q->front = 0;
    }
    q->data[++q->rear] = h;
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

    Hewan h = q->data[q->front];
    q->front++;

    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }

    return h;
}

// ===== PUSH =====
void push(Stack *s, Hewan h) {
    if (isFullStack(s)) {
        cout << "Riwayat penuh!\n";
        return;
    }
    s->data[++s->top] = h;
    cout << "Masuk riwayat\n";
}

// ===== POP =====
void pop(Stack *s) {
    if (isEmptyStack(s)) {
        cout << "Riwayat kosong!\n";
        return;
    }
    cout << "Hapus riwayat: " << s->data[s->top].nama << endl;
    s->top--;
}

// ===== PEEK =====
void peek(Queue *q, Stack *s) {
    if (!isEmptyQueue(q)) {
        cout << "Antrian depan: " << q->data[q->front].nama << endl;
    } else {
        cout << "Antrian kosong\n";
    }

    if (!isEmptyStack(s)) {
        cout << "Riwayat terakhir: " << s->data[s->top].nama << endl;
    } else {
        cout << "Riwayat kosong\n";
    }
}

// ===== TAMPIL QUEUE (POINTER) =====
void tampilQueue(Queue *q) {
    if (isEmptyQueue(q)) {
        cout << "Antrian kosong\n";
        return;
    }

    cout << "Isi antrian:\n";
    for (Hewan *p = q->data + q->front; p <= q->data + q->rear; p++) {
        cout << p->id << " - " << p->nama << endl;
    }
}

// ===== TAMPIL STACK (POINTER) =====
void tampilStack(Stack *s) {
    if (isEmptyStack(s)) {
        cout << "Riwayat kosong\n";
        return;
    }

    cout << "Riwayat:\n";
    for (Hewan *p = s->data; p <= s->data + s->top; p++) {
        cout << p->id << " - " << p->nama << endl;
    }
}

// ===== MAIN =====
int main() {
    Queue q;
    Stack s;

    initQueue(&q);
    initStack(&s);

    int pilih;
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
            cout << "ID: "; cin >> h.id;
            cout << "Nama: "; cin >> h.nama;
            enqueue(&q, h);
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