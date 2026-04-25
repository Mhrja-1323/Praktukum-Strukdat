//127 (GENAP)
#include <iostream>
using namespace std;

#define MAX 5

// ===== STRUCT =====
struct Tiket {
    string nama;
    string rute;
};

// ===== QUEUE =====
struct Queue {
    Tiket data[MAX];
    int front, rear;
};

// ===== STACK =====
struct Stack {
    Tiket data[MAX];
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
void enqueue(Queue *q, Tiket t) {
    if (isFullQueue(q)) {
        cout << "Antrian penuh!\n";
        return;
    }
    if (isEmptyQueue(q)) {
        q->front = 0;
    }
    q->data[++q->rear] = t;
    cout << "Penumpang masuk antrian\n";
}

// ===== DEQUEUE =====
Tiket dequeue(Queue *q) {
    Tiket kosong;
    kosong.nama = "-";

    if (isEmptyQueue(q)) {
        cout << "Antrian kosong!\n";
        return kosong;
    }

    Tiket t = q->data[q->front];
    q->front++;

    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }

    return t;
}

// ===== PUSH =====
void push(Stack *s, Tiket t) {
    if (isFullStack(s)) {
        cout << "Riwayat penuh!\n";
        return;
    }
    s->data[++s->top] = t;
    cout << "Masuk riwayat transaksi\n";
}

// ===== POP =====
void pop(Stack *s) {
    if (isEmptyStack(s)) {
        cout << "Riwayat kosong!\n";
        return;
    }
    cout << "Hapus transaksi: " << s->data[s->top].nama << endl;
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
        cout << "Transaksi terakhir: " << s->data[s->top].nama << endl;
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

    cout << "Daftar antrian:\n";
    for (Tiket *p = q->data + q->front; p <= q->data + q->rear; p++) {
        cout << p->nama << " | " << p->rute << endl;
    }
}

// ===== TAMPIL STACK (POINTER) =====
void tampilStack(Stack *s) {
    if (isEmptyStack(s)) {
        cout << "Riwayat kosong\n";
        return;
    }

    cout << "Riwayat transaksi:\n";
    for (Tiket *p = s->data; p <= s->data + s->top; p++) {
        cout << p->nama << " | " << p->rute << endl;
    }
}

// ===== MAIN =====
int main() {
    Queue q;
    Stack s;

    initQueue(&q);
    initStack(&s);

    int pilih;
    Tiket t;

    do {
        cout << "\n=== SISTEM KERETA API ===\n";
        cout << "1. Tambah Antrian Tiket\n";
        cout << "2. Proses Tiket\n";
        cout << "3. Pop Riwayat\n";
        cout << "4. Peek\n";
        cout << "5. Tampil Antrian\n";
        cout << "6. Tampil Riwayat\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
        case 1:
            cout << "Nama Penumpang: ";
            cin >> t.nama;
            cout << "Rute: ";
            cin >> t.rute;
            enqueue(&q, t);
            break;

        case 2:
            t = dequeue(&q);
            if (t.nama != "-") {
                cout << "Diproses: " << t.nama << " | " << t.rute << endl;
                push(&s, t);
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