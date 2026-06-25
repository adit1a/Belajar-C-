#include "raylib.h"
#include <string>

using namespace std;

struct rintangan {
    Rectangle kotak;
    Color warna;
};

class karakter {
protected:
    string nama;
    Vector2 posisi;
    float kecepatan;
    float radiusMC;
    float kecepatanY;
    bool sedangMelompat;

public:
    karakter(string name, float x, float y, float speed) {
        nama = name;
        posisi = { x, y };
        kecepatan = speed;
        radiusMC = 30.0f; 
        kecepatanY = 0.0f;
        sedangMelompat = false;
    }

    void updateInput(float posisiYtanah, rintangan daftarRintangan[], int jumlahRintangan) {
    // 1. Simpan posisi lama sebelum bergerak (untuk pengaman dinding samping)
    float posisiX_lama = posisi.x;

    // --- GAYA GRAVITASI ---
    float gravitasi = 0.5f;
    kecepatanY += gravitasi;
    posisi.y += kecepatanY;

    // Batas bawah tanah utama
    if (posisi.y + radiusMC >= posisiYtanah) {
        posisi.y = posisiYtanah - radiusMC;
        kecepatanY = 0.0f;
        sedangMelompat = false; // Reset status melompat di tanah utama
    }

    // --- INPUT TOMBOL JALAN ---
    if (IsKeyDown(KEY_D)) posisi.x += kecepatan;
    if (IsKeyDown(KEY_A)) posisi.x -= kecepatan;

    // --- LOGIKA CEK TABRAKAN DENGAN BALOK RINTANGAN ---
    for (int i = 0; i < jumlahRintangan; i++) {
        if (CheckCollisionCircleRec(posisi, radiusMC, daftarRintangan[i].kotak)) {
            
            // JIKA MENABRAK DARI ATAS BALOK (MC mendarat di atas permukaan)
            // Toleransi 15 piksel dihitung dari kecepatan jatuh
            if (kecepatanY > 0 && (posisi.y + radiusMC - kecepatanY <= daftarRintangan[i].kotak.y + 10.0f)) {
                posisi.y = daftarRintangan[i].kotak.y - radiusMC;
                kecepatanY = 0.0f;
                sedangMelompat = false; // KUNCI RE-ENABLE: Di atas balok dianggap menapak tanah!
            } 
            // JIKA MENABRAK DARI SAMPING BALOK (Mentok dinding)
            else {
                posisi.x = posisiX_lama;
            }
        }
    }

    // --- INPUT TOMBOL LOMPAT (Dipindah ke paling bawah agar akurat) ---
    // Sekarang, tombol SPACE akan mengecek status akhir 'sedangMelompat' setelah kalkulasi tabrakan selesai
    if (IsKeyPressed(KEY_SPACE) && !sedangMelompat) {
        kecepatanY = -12.0f; // Dorong ke atas langit
        sedangMelompat = true;
    }

    // Pembatasan layar window (lebar 800)
    if (posisi.x < radiusMC) posisi.x = radiusMC;
    if (posisi.x > 800 - radiusMC) posisi.x = 800 - radiusMC;
}

    void draw() {
        
        DrawCircleV(posisi, radiusMC, BLUE);
        
        DrawText(nama.c_str(), posisi.x - 20, posisi.y - 50, 16, DARKGRAY);
    }
}; 

int main() {
    const int lebarL = 800;
    const int tinggiL = 450;
    InitWindow(lebarL, tinggiL, "Raylib - Logika Tabrakan Rintangan");

    float posisiYtanah = 350.0f;

    
    karakter adit("Destroyer", 100.0f, posisiYtanah - 30.0f, 5.0f);

    const int jumlah_rintangan = 3;
    rintangan daftarRintangan[jumlah_rintangan];

    daftarRintangan[0].kotak = {300.0f, posisiYtanah - 50.0f, 60.0f, 50.0f};
    daftarRintangan[0].warna = DARKGRAY;
    
    daftarRintangan[1].kotak = {450.0f, posisiYtanah - 90.0f, 60.0f, 90.0f};
    daftarRintangan[1].warna = GRAY;
    
    daftarRintangan[2].kotak = {650.0f, posisiYtanah - 160.0f, 60.0f, 160.0f};
    daftarRintangan[2].warna = LIGHTGRAY;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        
        adit.updateInput(posisiYtanah, daftarRintangan, jumlah_rintangan);

        
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Garis Tanah GOLD
        DrawLine(0, posisiYtanah, lebarL, posisiYtanah, GOLD);
        
        // Menggambar semua rintangan
        for (int i = 0; i < jumlah_rintangan; i++) {
            DrawRectangleRec(daftarRintangan[i].kotak, daftarRintangan[i].warna);
            DrawRectangleLinesEx(daftarRintangan[i].kotak, 2, BLACK);
        }

        adit.draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}