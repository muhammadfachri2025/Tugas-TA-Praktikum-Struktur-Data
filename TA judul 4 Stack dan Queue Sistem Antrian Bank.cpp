#include <iostream>
#include <string>
using namespace std;

const int MAX = 5;
int frontIdx = -1, rearIdx = -1;
string nama[MAX], layanan[MAX];

bool isEmpty() { return frontIdx == -1; }
bool isFull()  { return (rearIdx + 1) % MAX == frontIdx; }

void enqueue() {
    if (isFull()) cout << "Antrian penuh!\n";
    else {
        string n, l;
        cin.ignore();
        cout << "Masukkan nama nasabah: "; getline(cin, n);
        cout << "Masukkan jenis layanan: "; getline(cin, l);
        if (isEmpty()) frontIdx = rearIdx = 0;
        else rearIdx = (rearIdx + 1) % MAX;
        nama[rearIdx] = n;
        layanan[rearIdx] = l;
        cout << n << " masuk ke antrian.\n";
    }
}

void dequeue() {
    if (isEmpty()) cout << "Antrian kosong!\n";
    else {
        cout << "Nasabah " << nama[frontIdx] << " (" << layanan[frontIdx] << ") telah dilayani.\n";
        if (frontIdx == rearIdx) frontIdx = rearIdx = -1;
        else frontIdx = (frontIdx + 1) % MAX;
    }
}

void peek() {
    if (isEmpty()) cout << "Tidak ada nasabah di antrian.\n";
    else cout << "Nasabah terdepan: " << nama[frontIdx] << " (" << layanan[frontIdx] << ")\n";
}

void display() {
    if (isEmpty()) cout << "Antrian kosong.\n";
    else {
        cout << "\nDaftar Nasabah dalam Antrian:\n";
        int i = frontIdx;
        while (true) {
            cout << "- " << nama[i] << " (" << layanan[i] << ")\n";
            if (i == rearIdx) break;
            i = (i + 1) % MAX;
        }
    }
}

int main() {
    int pilih;
    do {
        cout << "\n=== SISTEM ANTRIAN BANK ===\n";
        cout << "1. Tambah Nasabah (Enqueue)\n";
        cout << "2. Layani Nasabah (Dequeue)\n";
        cout << "3. Lihat Nasabah Terdepan (Peek)\n";
        cout << "4. Cek Kosong/Penuh\n";
        cout << "5. Tampilkan Semua Nasabah\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4:
                cout << (isEmpty() ? "Queue kosong.\n" : "Queue tidak kosong.\n");
                cout << (isFull() ? "Queue penuh.\n" : "Queue belum penuh.\n");
                break;
            case 5: display(); break;
            case 6: cout << "Terima kasih!\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }
    } while (pilih != 6);
}
