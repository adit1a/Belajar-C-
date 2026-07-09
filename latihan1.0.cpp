#include <string>
#include "raylib.h"
#include <ctime>
#include <vector> // Ditambahkan untuk menampung daftar platform

using namespace std;

const int lebarL = 1600;
const int tinggiL = 800;
const float lantai = 600.0f;

class player {
private:
    Vector2 posisi;
    Vector2 ukuran;
    float kecepatanX;
    float kecepatanY;
    bool sdgMelompat;
    Color warna;
    float gravitasi = 0.5f;

public:
    player(float xAwal, float yAwal, Color warnaA) {
        posisi = {xAwal, yAwal};
        ukuran = {40, 40};
        kecepatanX = 5.0f;
        kecepatanY = 0.0f;
        sdgMelompat = false;
        warna = warnaA;
    }

    // Fungsi Aksesor untuk mengambil data kotak player
    Rectangle GetRect() {
        return { posisi.x, posisi.y, ukuran.x, ukuran.y };
    }

    void gerak() {
        // --- GERAK HORIZONTAL ---
        if (IsKeyDown(KEY_D)) posisi.x += kecepatanX;
        if (IsKeyDown(KEY_A)) posisi.x -= kecepatanX;
        
        // Batas Layar Kiri & Kanan
        if (posisi.x < 0) posisi.x = 0;
        if (posisi.x + ukuran.x > lebarL) posisi.x = lebarL - ukuran.x;

        // --- GERAK VERTIKAL (LOMPAT) ---
        if (IsKeyDown(KEY_SPACE) && !sdgMelompat) {
            kecepatanY = -12.0f;
            sdgMelompat = true;
        }

        // Menerapkan Gravitasi
        kecepatanY += gravitasi;
        posisi.y += kecepatanY;

        // Batas Lantai Bawah
        if (posisi.y + ukuran.y >= lantai) {
            posisi.y = lantai - ukuran.y;
            kecepatanY = 0.0f;
            sdgMelompat = false;
        }
    }

    // Fungsi khusus jika mendarat di atas platform
    void MendaratDiPlatform(float koordinatYPlatform) {
        posisi.y = koordinatYPlatform - ukuran.y;
        kecepatanY = 0.0f;
        sdgMelompat = false;
    }

    // Aksesor untuk memeriksa kecepatan Y
    float GetKecY() { return kecepatanY; }

    void draw() {
        DrawRectangleV(posisi, ukuran, warna);
    }
};

void lantai1() {
    DrawRectangle(0, 600, 1600, 200, GRAY);
}

int main() {
    InitWindow(lebarL, tinggiL, "Raylib - Belajar Platform");
    player K1(100, 100, RED);
    SetTargetFPS(60);
    srand(time(0));

    // ========================================================
    // MEMBUAT 3 PLATFORM DI ATAS YANG BISA DIINJAK
    // ========================================================
    vector<Rectangle> platforms;
    platforms.push_back({ 400, 480, 200, 20 });  // Platform 1 (Kiri)
    platforms.push_back({ 700, 380, 200, 20 });  // Platform 2 (Tengah Atas)
    platforms.push_back({ 1000, 450, 250, 20 }); // Platform 3 (Kanan)

    while (!WindowShouldClose()) {
        // 1. Update Posisi Player
        K1.gerak();

        // 2. Logika Deteksi Tabrakan untuk Semua Platform
        for (size_t i = 0; i < platforms.size(); i++) {
            if (CheckCollisionRecs(K1.GetRect(), platforms[i])) {
                // KUNCI UTAMA: Hanya mendarat jika karakter sedang jatuh ke bawah (kecepatanY positif)
                if (K1.GetKecY() > 0.0f) {
                    K1.MendaratDiPlatform(platforms[i].y);
                }
            }
        }

        // 3. Menggambar Semua Objek
        BeginDrawing();
            ClearBackground(RAYWHITE);
            
            lantai1(); // Gambar tanah biasa

            // Gambar ke-3 platform biru menggunakan perulangan
            for (size_t i = 0; i < platforms.size(); i++) {
                DrawRectangleRec(platforms[i], BLUE);
            }

            K1.draw(); // Gambar player merah
            
        EndDrawing();
    }

    CloseWindow();
    return 0;
}