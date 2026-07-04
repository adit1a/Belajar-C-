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
        float posisiX_lama = posisi.x;

        // GRAVITASI
        float gravitasi = 0.5f;
        kecepatanY += gravitasi;
        posisi.y += kecepatanY;

        if (posisi.y + radiusMC >= posisiYtanah) {
            posisi.y = posisiYtanah - radiusMC;
            kecepatanY = 0.0f;
            sedangMelompat = false;
        }

        // INPUT JALAN (Batas kanan kita perlebar ke 2000 piksel biar dunianya luas!)
        if (IsKeyDown(KEY_D)) posisi.x += kecepatan;
        if (IsKeyDown(KEY_A)) posisi.x -= kecepatan;

        // INPUT LOMPAT
        if (IsKeyPressed(KEY_SPACE) && !sedangMelompat) {
            kecepatanY = -12.0f; 
            sedangMelompat = true;
        }

        // CEK TABRAKAN
        for (int i = 0; i < jumlahRintangan; i++) {
            if (CheckCollisionCircleRec(posisi, radiusMC, daftarRintangan[i].kotak)) {
                if (kecepatanY > 0 && (posisi.y + radiusMC - kecepatanY <= daftarRintangan[i].kotak.y + 10.0f)) {
                    posisi.y = daftarRintangan[i].kotak.y - radiusMC;
                    kecepatanY = 0.0f;
                    sedangMelompat = false; 
                } else {
                    posisi.x = posisiX_lama;
                }
            }
        }

        // Batas dunia baru: sekarang MC bisa jalan dari koordinat 0 sampai 2000!
        if (posisi.x < radiusMC) posisi.x = radiusMC;
        if (posisi.x > 2000 - radiusMC) posisi.x = 2000 - radiusMC;
    }

    void draw() {
        DrawCircleV(posisi, radiusMC, BLUE);
        DrawText(nama.c_str(), posisi.x - 20, posisi.y - 50, 16, DARKGRAY);
    }
    
    // Fungsi wajib agar int main() bisa membisikkan posisi MC ke kamera
    Vector2 getPosisi() { return posisi; }
}; 

int main() {
    const int lebarL = 800;
    const int tinggiL = 450;
    InitWindow(lebarL, tinggiL, "Raylib - Logika Kamera 2D");

    float posisiYtanah = 350.0f;
    karakter adit("Mc", 100.0f, posisiYtanah - 30.0f, 5.0f);

    // Kita sebar 3 rintangan di koordinat yang lebih jauh (dunia luar)
    const int jumlah_rintangan = 3;
    rintangan daftarRintangan[jumlah_rintangan];
    daftarRintangan[0].kotak = {400.0f, posisiYtanah - 50.0f, 60.0f, 50.0f};
    daftarRintangan[0].warna = DARKGRAY;
    
    daftarRintangan[1].kotak = {800.0f, posisiYtanah - 90.0f, 60.0f, 90.0f};
    daftarRintangan[1].warna = GRAY;
    
    daftarRintangan[2].kotak = {1300.0f, posisiYtanah - 160.0f, 60.0f, 160.0f};
    daftarRintangan[2].warna = LIGHTGRAY;

    // --- SETUP KAMERA 2D ---
    Camera2D kamera = { 0 };
    kamera.target = adit.getPosisi();              // Mengunci objek yang diincar
    kamera.offset = { lebarL / 2.0f, tinggiL / 2.0f }; // Membuat posisi target pas di tengah layar
    kamera.rotation = 0.0f;
    kamera.zoom = 1.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // 1. UPDATE LOGIKA GAME
        adit.updateInput(posisiYtanah, daftarRintangan, jumlah_rintangan);

        // 2. UPDATE POSISI KAMERA (Kamera selalu memperbarui koordinat target mengikuti X si MC)
        kamera.target.x = adit.getPosisi().x;

        // 3. DRAW VISUAL
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // --- MULAI MODE KAMERA ---
        // Semua objek di dalam sini akan bergeser otomatis secara matematika grafis
        BeginMode2D(kamera);

            // Gambar Garis Tanah sepanjang 2000 piksel kedepan
            DrawLine(0, posisiYtanah, 2000, posisiYtanah, GOLD);
            
            // Gambar Rintangan
            for (int i = 0; i < jumlah_rintangan; i++) {
                DrawRectangleRec(daftarRintangan[i].kotak, daftarRintangan[i].warna);
                DrawRectangleLinesEx(daftarRintangan[i].kotak, 2, BLACK);
            }

            // Gambar Karakter
            adit.draw();

        EndMode2D();
        // --- AKHIR MODE KAMERA ---

        // CONTOH UI: Teks ini ditaruh di luar Mode2D agar tetap diam di layar (tidak ikut bergeser)
        DrawText("LOG GAMEPLAY: KAMERA AKTIF", 20, 20, 20, RED);
        DrawText(TextFormat("Posisi X Player: %.0f", adit.getPosisi().x), 20, 50, 16, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}