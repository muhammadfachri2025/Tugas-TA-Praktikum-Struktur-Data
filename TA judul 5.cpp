#include <iostream>
#include <string>
using namespace std;

struct Menu {
    string nama;
    int harga;
    Menu *left, *right;
};

Menu* buatNode(string nama, int harga) {
    return new Menu{nama, harga, nullptr, nullptr};
}

Menu* insert(Menu* root, string nama, int harga) {
    if (!root) return buatNode(nama, harga);
    if (harga < root->harga) root->left = insert(root->left, nama, harga);
    else root->right = insert(root->right, nama, harga);
    return root;
}

void tampil(Menu* root) {
    if (!root) return;
    tampil(root->left);
    cout << root->nama << " - Rp" << root->harga << endl;
    tampil(root->right);
}

Menu* findMin(Menu* root) {
    while (root && root->left) root = root->left;
    return root;
}

Menu* findMax(Menu* root) {
    while (root && root->right) root = root->right;
    return root;
}

int main() {
    Menu* root = nullptr;
    int n, harga;
    string nama;

    cout << "Masukkan jumlah menu: ";
    cin >> n; cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "\nNama makanan: ";
        getline(cin, nama);
        cout << "Harga: Rp";
        cin >> harga; cin.ignore();
        root = insert(root, nama, harga);
    }

    cout << "\n=== DAFTAR MENU (TERMURAH → TERMAHAL) ===\n";
    tampil(root);

    Menu* murah = findMin(root);
    Menu* mahal = findMax(root);

    if (murah && mahal) {
        cout << "\nMenu Termurah  : " << murah->nama << " - Rp" << murah->harga;
        cout << "\nMenu Termahal  : " << mahal->nama << " - Rp" << mahal->harga << endl;
    }
}
