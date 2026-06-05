#include "raylib.h"
#include <string>

using namespace std;

int main() {
    // 1. INITIALIZATION
    const int lebarLayar = 800;
    const int tinggiLayar = 450;
    InitWindow(lebarLayar, tinggiLayar, "Pergerakan Kotak - Raylib Fundamental");

    // Variabel Posisi Awal Kotak (Kita taruh di tengah-tengah layar)
    int kotakX = 375; // Posisi Horizontal (Kiri/Kanan)
    int kotakY = 200; // Posisi Vertikal (Atas/Bawah)
    
    // Kecepatan gerak kotak (berapa piksel per frame)
    int kecepatan = 5; 

    SetTargetFPS(60); // Mengunci game di 60 FPS (Loop berputar 60x sedetik)

    // 2. THE GAME LOOP
    while (!WindowShouldClose()) {
        
        // ----------------------------------------------------
        // LOGIKA UPDATE & INPUT (Mendeteksi Tombol Panah)
        // ----------------------------------------------------
        
        // Cek Panah Kanan: Menambah X akan membuat objek bergeser ke KANAN
        if (IsKeyDown(KEY_RIGHT)) {
            kotakX += kecepatan; 
        }
        
        // Cek Panah Kiri: Mengurangi X akan membuat objek bergeser ke KIRI
        if (IsKeyDown(KEY_LEFT)) {
            kotakX -= kecepatan;
        }
        
        // Cek Panah Bawah: Menambah Y akan membuat objek bergeser ke BAWAH
        if (IsKeyDown(KEY_DOWN)) {
            kotakY += kecepatan;
        }
        
        // Cek Panah Atas: Mengurangi Y akan membuat objek bergeser ke ATAS
        if (IsKeyDown(KEY_UP)) {
            kotakY -= kecepatan;
        }

        // ----------------------------------------------------
        // LOGIKA DRAW (Menggambar Objek ke Layar)
        // ----------------------------------------------------
        BeginDrawing();
        ClearBackground(BLACK); // Bersihkan layar dengan warna hitam

        // Gambar petunjuk teks di pojok
        DrawText("Gunakan Tombol Panah di Keyboard untuk Bergerak", 10, 10, 20, GRAY);
        
        // Tampilkan koordinat real-time biar kamu bisa lihat angkanya berubah
        DrawText(("Posisi X: " + std::to_string(kotakX)).c_str(), 10, 40, 18, GREEN);
        DrawText(("Posisi Y: " + std::to_string(kotakY)).c_str(), 10, 65, 18, GREEN);

        // GAMBAR KOTAK BIRU UTAMA
        // Parameter: DrawRectangle(Posisi_X, Posisi_Y, Lebar, Tinggi, Warna)
        DrawRectangle(kotakX, kotakY, 50, 50, BLUE); 

        EndDrawing();
    }

    // 3. DE-INITIALIZATION
    CloseWindow();
    return 0;
}