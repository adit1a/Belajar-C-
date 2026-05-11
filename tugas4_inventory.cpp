#include <iostream>
#include <string>

using namespace std;

// Struct untuk menyimpan data item
struct Item {
    string nama;
    int jumlah;
    int maxStack;
};

// Fungsi untuk menambah jumlah item (Mining/Looting)
void ambilItem(Item &i) {
    if (i.jumlah < i.maxStack) {
        i.jumlah++;
        cout << ">>> Kamu mendapatkan 1 " << i.nama << "!" << endl;
    } else {
        cout << ">>> Gagal! Slot " << i.nama << " sudah penuh (Max: " << i.maxStack << ")" << endl;
    }
}

int main() {
    // 1. Inisialisasi Item (Data awal)
    Item slot1 = {"Cobblestone", 10, 64}; // Hampir penuh
    Item slot2 = {"Iron Sword", 0, 1};    // Item yang tidak bisa ditumpuk

    int pilihan;

    do {
        cout << "\n=== INVENTORY SEDERHANA ===" << endl;
        cout << "1. [Slot 1] " << slot1.nama << " (" << slot1.jumlah << "/" << slot1.maxStack << ")" << endl;
        cout << "2. [Slot 2] " << slot2.nama << " (" << slot2.jumlah << "/" << slot2.maxStack << ")" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih aksi (1-3): ";
        cin >> pilihan;

        // 2. Menggunakan Switch Case untuk memproses pilihan
        switch (pilihan) {
            case 1:
                ambilItem(slot1);
                break;
            case 2:
                ambilItem(slot2);
                break;
            case 3:
                cout << "Keluar dari game..." << endl;
                break;
            default:
                cout << "Pilihan tidak tersedia!" << endl;
        }

    } while (pilihan != 3);

    return 0;
}