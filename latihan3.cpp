#include "raylib.h"
#include <string>

using namespace std;

class karakter {
protected:
    string nama;
    Vector2 posisi;
    float kecepatan;
    float radiusMC;

public:
    // 1. Perbaikan Constructor (Nilai dimasukkan dengan benar & perbaikan typo float)
    karakter(string name, float x, float y, float speed) {
        nama = name;
        posisi = { x, y };
        kecepatan = speed;
        radiusMC = 30.0f; // Ukuran lingkaran MC
    }

    // 2. Perbaikan fungsi updateInput (Tidak pakai karakter:: dan akses sumbu .x)
    void updateInput() {
        if (IsKeyDown(KEY_D)) {
            posisi.x += kecepatan; // Ditambah sumbu .x
        }
        if (IsKeyDown(KEY_A)) {
            posisi.x -= kecepatan; // Dikurang sumbu .x
        }

        // Pembatasan layar (lebar layar memakai angka fix 800)
        if (posisi.x < radiusMC) posisi.x = radiusMC;
        if (posisi.x > 800 - radiusMC) posisi.x = 800 - radiusMC;
    }

    // 3. Perbaikan fungsi draw (Memakai parameter DrawCircle/DrawText Raylib yang benar)
    void draw() {
        // Gambar tanah/lantai
        DrawLine(0, 300, 800, 300, BLACK);

        // Gambar Karakter berupa lingkaran
        DrawCircleV(posisi, radiusMC, BLUE);

        // Cetak nama MC di atas kepala
        DrawText(nama.c_str(), posisi.x - 20, posisi.y - 50, 16, DARKGRAY);
    }
}; // <--- Jangan lupa titik koma di akhir class, Dit!

int main() {
    // Pustaka Window dibuka di awal int main() agar standard
    const int lebarL = 800;
    const int tinggiL = 450;
    InitWindow(lebarL, tinggiL, "Raylib - Belajar Class Lagi");

    // Membuat objek dari class karakter
    karakter adit("Destroyer", 400.0f, 270.0f, 5.0f);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // LOGIKA
        adit.updateInput();

        // VISUAL
        BeginDrawing();
        ClearBackground(RAYWHITE);

        adit.draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}