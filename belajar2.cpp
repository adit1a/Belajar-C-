#include "raylib.h"

int main() {
    // 1. Inisialisasi Ukuran Jendela Game
    InitWindow(800, 450, "Simulator Blacksmith - Animasi MC");

    // 2. Load Gambar Spritesheet Baru dari Folder Resources
    // Pastikan nama file sesuai dengan yang di-export dari Figma (308x128 px)
    Texture2D spriteMC = LoadTexture("resources/mc_jalan.png");

    // Matematika Pembagian Frame Otomatis
    int jumlahFrame = 4;
    float lebarFrame = 77.0f; // Sesuai hitungan Figma kamu yang sudah presisi
    float tinggiFrame = 128.0f;        // 128 px

    // Jendela Intip: Memotong agar hanya 1 karakter pertama yang muncul di awal
    Rectangle sourceRec = { 0.0f, 0.0f, lebarFrame, tinggiFrame };
    
    // Posisi Spawn MC di tengah layar game
    Vector2 posisiMC = { 350.0f, 150.0f };

    // Variabel Pengatur Waktu Animasi
    int frameAktif = 0;
    int counterWaktu = 0;
    int kecepatanAnimasi = 5; // Semakin besar angkanya, semakin cepat kaki melangkah

    SetTargetFPS(60);

    // -------------------------------------------------------------------------
    // GAME LOOP UATAMA
    // -------------------------------------------------------------------------
    while (!WindowShouldClose()) {
        
        bool sedangJalan = false;

        // DETEKSI INPUT KEYBOARD (A/D atau Panah Kanan-Kiri)
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
            posisiMC.x += 4.0f; // Bergerak ke kanan
            sedangJalan = true;
        }
        else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
            posisiMC.x -= 4.0f; // Bergerak ke kiri
            sedangJalan = true;
        }

        // LOGIKA UPDATE ANIMASI: Frame hanya berputar saat MC berpindah tempat
        if (sedangJalan) {
            counterWaktu++;
            if (counterWaktu >= (120 / kecepatanAnimasi)) {
                counterWaktu = 0;
                frameAktif++;

                // Jika animasi sudah tembus frame ke-4, reset kembali ke frame awal (0)
                if (frameAktif >= jumlahFrame) frameAktif = 0;

                // GESER JENDELA INTIP secara matematis (0*77px, 1*77px, 2*77px, dst.)
                sourceRec.x = (float)frameAktif * lebarFrame;
            }
        } else {
            // Jika tombol dilepas, karakter otomatis kembali ke pose diam (frame pertama)
            frameAktif = 0;
            sourceRec.x = 0.0f;
        }

        // -------------------------------------------------------------------------
        // CANVAS DRAWING (VISUAL)
        // -------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Petunjuk Kontrol di Layar
        DrawText("Tahan tombol A / D atau Panah Kanan-Kiri untuk berjalan", 20, 20, 20, GRAY);

        // Menggambar Karakter Utama yang Sudah Dipotong Presisi
        DrawTextureRec(spriteMC, sourceRec, posisiMC, WHITE);

        EndDrawing();
    }

    // 3. Bersihkan Memory VRAM sebelum menutup program
    UnloadTexture(spriteMC);
    CloseWindow();

    return 0;
}