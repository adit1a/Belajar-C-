#include "raylib.h"
#include <iostream>
#include <string>

using namespace std;

struct Paket {
    string kotaTujuan;
    int berat;
    string nama;
};

// FUNGSI KAMU (Logika tetap sama persis)
void hitungBiaya(Paket p, int kota, int &total){
    int beratNormal = 3;
    int biayaPerKg = 10000;
    
    switch (kota) {
        case 1:
            if(p.berat <= beratNormal) total = p.berat * biayaPerKg;
            else total = (beratNormal * biayaPerKg) + ((p.berat - beratNormal) * 5000);
            break;
        case 2:
            if(p.berat <= beratNormal) total = p.berat * biayaPerKg;
            else total = (beratNormal * biayaPerKg) + ((p.berat - beratNormal) * 7500);
            break;
        case 3:
            if(p.berat <= beratNormal) total = p.berat * biayaPerKg;
            else total = (beratNormal * biayaPerKg) + ((p.berat - beratNormal) * 6000);
            break;
        default:
            total = 0;
            break;
    }
}

int main() {
    // 1. Inisialisasi Ukuran Layar Aplikasi
    const int layarLebar = 500;
    const int layarTinggi = 450;
    InitWindow(layarLebar, layarTinggi, "Sistem Ekspedisi UI/UX - Adit");

    // Data Simulasi (Input manual via kode untuk contoh UI)
    Paket p1;
    p1.nama = "Adit1a";
    p1.berat = 5; // Contoh berat 5kg
    
    int kotaDipilih = 0;
    int totalBiaya = 0;

    // Mendefinisikan Koordinat Kotak Tombol (X, Y, Lebar, Tinggi)
    Rectangle tombolMks = { 50, 150, 110, 40 };
    Rectangle tombolKdr = { 195, 150, 110, 40 };
    Rectangle tombolDpk = { 340, 150, 110, 40 };

    SetTargetFPS(60); // Mengunci aplikasi di 60 FPS (Ringan untuk Athlon)

    // 2. GAME LOOP (Aplikasi berjalan terus selama belum ditutup)
    while (!WindowShouldClose()) {
        
        // Ambil posisi mouse saat ini
        Vector2 posisiMouse = GetMousePosition();

        // LOGIKA DETEKSI KLIK TOMBOL
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (CheckCollisionPointRec(posisiMouse, tombolMks)) {
                kotaDipilih = 1;
                hitungBiaya(p1, kotaDipilih, totalBiaya);
            }
            if (CheckCollisionPointRec(posisiMouse, tombolKdr)) {
                kotaDipilih = 2;
                hitungBiaya(p1, kotaDipilih, totalBiaya);
            }
            if (CheckCollisionPointRec(posisiMouse, tombolDpk)) {
                kotaDipilih = 3;
                hitungBiaya(p1, kotaDipilih, totalBiaya);
            }
        }

        // 3. PROSES MENGGAMBAR UI/UX DI LAYAR
        BeginDrawing();
        ClearBackground(RAYWHITE); // Warna background aplikasi

        // Gambar Judul
        DrawText("SISTEM EKSPEDISI PAKET", 80, 20, 24, DARKGRAY);
        DrawLine(20, 60, 480, 60, LIGHTGRAY);

        // Tampilkan Data Pengirim
        DrawText(("Pengirim: " + p1.nama).c_str(), 50, 80, 18, BLACK);
        DrawText(("Berat Paket: " + to_string(p1.berat) + " Kg").c_str(), 50, 110, 18, BLACK);

        // GAMBAR TOMBOL KOTA 1 (Makassar)
        // Jika mouse di atas tombol, warnanya berubah jadi abu-abu (Hover effect)
        Color warnaMks = CheckCollisionPointRec(posisiMouse, tombolMks) ? LIGHTGRAY : GRAY;
        DrawRectangleRec(tombolMks, warnaMks);
        DrawText("Makassar", tombolMks.x + 12, tombolMks.y + 12, 16, WHITE);

        // GAMBAR TOMBOL KOTA 2 (Kendari)
        Color warnaKdr = CheckCollisionPointRec(posisiMouse, tombolKdr) ? LIGHTGRAY : GRAY;
        DrawRectangleRec(tombolKdr, warnaKdr);
        DrawText("Kendari", tombolKdr.x + 18, tombolKdr.y + 12, 16, WHITE);

        // GAMBAR TOMBOL KOTA 3 (Depok)
        Color warnaDpk = CheckCollisionPointRec(posisiMouse, tombolDpk) ? LIGHTGRAY : GRAY;
        DrawRectangleRec(tombolDpk, warnaDpk);
        DrawText("Depok", tombolDpk.x + 25, tombolDpk.y + 12, 16, WHITE);

        // TAMPILKAN STRUK HASIL DI BAWAH
        DrawLine(20, 230, 480, 230, LIGHTGRAY);
        
        if (kotaDipilih != 0) {
            string teksKota = (kotaDipilih == 1) ? "Makassar" : (kotaDipilih == 2) ? "Kendari" : "Depok";
            DrawText(("Kota Tujuan: " + teksKota).c_str(), 50, 260, 18, DARKBLUE);
            
            // Tampilkan Total Biaya dengan Box Hijau khas Aplikasi Kasir
            DrawRectangle(50, 310, 400, 60, GREEN);
            DrawText(("TOTAL: Rp " + to_string(totalBiaya)).c_str(), 70, 325, 26, WHITE);
        } else {
            DrawText("Silahkan klik tombol kota tujuan di atas...", 50, 260, 16, GRAY);
        }

        EndDrawing();
    }

    // Tutup Jendela Aplikasi
    CloseWindow();
    return 0;
}