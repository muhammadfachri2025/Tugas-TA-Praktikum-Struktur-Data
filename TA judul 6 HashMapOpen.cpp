#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;
string barang[SIZE];
int stok[SIZE];
bool deleted[SIZE]; 
int hashFunc(string nama) {
    int sum = 0;
    for (char c : nama) sum += c;
    return sum % SIZE;
}
void tambahBarang(string nama, int jumlah) {
    int index = hashFunc(nama);
    int start = index;
    bool full = true;

    do {
        if (barang[index].empty() || deleted[index]) {
            barang[index] = nama;
            stok[index] = jumlah;
            deleted[index] = false;
            cout << "Barang '" << nama << "' berhasil ditambahkan di indeks " << index << endl;
            full = false;
            break;
        }
        index = (index + 1) % SIZE;
    } while (index != start);

    if (full)
        cout << "Tabel penuh! Tidak dapat menambah barang.\n";
}
void cariBarang(string nama) {
    int index = hashFunc(nama);
    int start = index;
    do {
        if (barang[index] == nama && !deleted[index]) {
            cout << "Barang ditemukan di indeks " << index
                 << " → Nama: " << barang[index]
                 << ", Stok: " << stok[index] << endl;
            return;
        }
        if (barang[index].empty() && !deleted[index])
            break;
        index = (index + 1) % SIZE;
    } while (index != start);

    cout << "Barang '" << nama << "' tidak ditemukan.\n";
}
void hapusBarang(string nama) {
    int index = hashFunc(nama);
    int start = index;

    do {
        if (barang[index] == nama && !deleted[index]) {
            deleted[index] = true;
            barang[index] = "";
            stok[index] = 0;
            cout << "Barang '" << nama << "' dihapus dari indeks " << index << endl;
            return;
        }
        if (barang[index].empty() && !deleted[index])
            break;
        index = (index + 1) % SIZE;
    } while (index != start);

    cout << "Barang '" << nama << "' tidak ditemukan.\n";
}

int main() {
    int pilihan, jumlah;
    string nama;
    for (int i = 0; i < SIZE; i++) {
        barang[i] = "";
        stok[i] = 0;
        deleted[i] = false;
    }
    do {
        cout << "\n=== SISTEM STOK BARANG MINI MARKET ===\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Cari Barang\n";
        cout << "3. Hapus Barang\n";
        cout << "4. Keluar\nPilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Nama barang: "; cin >> nama;
                cout << "Jumlah stok: "; cin >> jumlah;
                tambahBarang(nama, jumlah);
                break;
            case 2:
                cout << "Cari nama barang: "; cin >> nama;
                cariBarang(nama);
                break;
            case 3:
                cout << "Nama barang yang ingin dihapus: "; cin >> nama;
                hapusBarang(nama);
                break;
        }
    } while (pilihan != 4);
    cout << "\nTerima kasih telah menggunakan sistem ini!\n";
    return 0;
}
