#include <iostream>
using namespace std;

int main() {
    const int JUMLAH = 5;   
    int nilai[JUMLAH];      
    int total = 0;

    cout << "Masukkan nilai untuk " << JUMLAH << " siswa:" << endl;
    for (int i = 0; i < JUMLAH; i++) {
        cout << "Nilai siswa ke-" << i + 1 << " : ";
        cin >> nilai[i];
        total += nilai[i];
    }

    cout << "\nDaftar nilai siswa:" << endl;
    for (int i = 0; i < JUMLAH; i++) {
        cout << "Siswa ke-" << i + 1 << " : " << nilai[i] << endl;
    }

    float rata = (float) total / JUMLAH;
    cout << "\nRata-rata nilai = " << rata << endl;

    return 0;
}
