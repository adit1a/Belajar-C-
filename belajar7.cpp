#include "raylib.h"
#include <string>

using namespace std;

class karakter {
protected:
    string nama;
    Vector2 posisi;
    float kecepatan;
    Texture2D spriteGw;
    Rectangle sourceRec;
    int jumlahFrame;
    int frameAktif;
    int counterWaktu;
    int kecepatanAnimasi; // <- Harus diisi nilainya
    float lebarFrame;
    float tinggiFrame;
    float arahHadap;

public:
    karakter(string namaKu, float x, float y, float speed, const char* pathGambar) {
        nama = namaKu;
        posisi = { x, y };
        kecepatan = speed;
        spriteGw = LoadTexture(pathGambar);
        
        jumlahFrame = 5;
        lebarFrame = (float)spriteGw.width / jumlahFrame;
        tinggiFrame = (float)spriteGw.height;
        
        frameAktif = 0;
        counterWaktu = 0;
        kecepatanAnimasi = 12; // <-- KITA BERI NILAI DI SINI (Misal 12)
        arahHadap = 1.0f;
        
        // KITA SET UKURAN AWAL JENDELA INTIPNYA DI SINI
        sourceRec = { 0.0f, 0.0f, lebarFrame, tinggiFrame };
    }

    ~karakter() {
        UnloadTexture(spriteGw);
    }

    void updateInput() {
        bool sdgJalan = false;

        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
            posisi.x += kecepatan;
            sdgJalan = true;
            arahHadap = 1.0f; 
        }
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
            posisi.x -= kecepatan;
            sdgJalan = true;
            arahHadap = -1.0f; 
        }

        // PEMBATAS LAYAR (Screen Bounding agar tidak hilang keluar jendela)
        if (posisi.x < 0) posisi.x = 0;
        if (posisi.x > 800 - lebarFrame) posisi.x = 800 - lebarFrame;

        if (sdgJalan) {
            counterWaktu++;
            if (counterWaktu >= (60 / kecepatanAnimasi)) {
                counterWaktu = 0;
                frameAktif++;
                if (frameAktif >= jumlahFrame) frameAktif = 0;
            }
        } else {
            frameAktif = 0;
        }

        // Terapkan hasil potongan frame ke sourceRec
        sourceRec.x = (float)frameAktif * lebarFrame;
        sourceRec.width = lebarFrame * arahHadap;
    }

    void draw() {
        // 1. PASTIKAN FILTERNYA 'WHITE' agar gambar PNG asli terlihat cerah
        // 2. Jika arah hadap kiri (-1), kita geser sedikit posisi gambarnya agar tidak bergeser saat berbalik
        Vector2 posisiGambar = posisi;
        if (arahHadap < 0) {
            // Ditambah selebar frame agar posisi anchor pivotnya seimbang saat di-mirror
            posisiGambar.x += lebarFrame; 
        }

        DrawTextureRec(spriteGw, sourceRec, posisiGambar, WHITE);
        
        // Cetak teks nama di atas kepala karakter
        DrawText(nama.c_str(), posisi.x, posisi.y - 20, 16, BLACK);
    }
};

int main() {
    InitWindow(800, 450, "Game Gw - Fix Animasi");
    
    // Pastikan folder resources dan nama file kamu sudah sesuai di laptop ya!
    karakter L("adit", 350.0f, 150.0f, 5.0f, "resources/mc4_jalan.png");
    
    SetTargetFPS(60);
    
    while (!WindowShouldClose()) {
        L.updateInput();
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        L.draw();
        
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}