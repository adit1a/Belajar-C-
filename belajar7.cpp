#include "raylib.h"
#include <string>

using namespace std;

class karakter {
protected:
    string nama;
    Vector2 posisi;
    float kecepatan;
    
    // --- TAMBAHAN VARIABEL UNTUK ANIMASI GAMBAR ---
    Texture2D spriteMC;       // Tempat menyimpan file gambar (.png)
    Rectangle sourceRec;      // Jendela intip untuk memotong per frame
    int jumlahFrame;
    int frameAktif;
    int counterWaktu;
    int kecepatanAnimasi;
    float lebarFrame;
    float tinggiFrame;
    float arahHadap;
public:
    // CONSTRUCTOR: Load gambar langsung saat objek dibuat
    karakter(string namAwal, float x, float y, float speed, const char* pathGambar) {
        nama = namAwal;
        posisi = { x, y };
        kecepatan = speed;

        // 1. Load File Gambar dari folder resources
        spriteMC = LoadTexture(pathGambar); 

        // 2. Setup Matematika Potong Frame (Misal gambar hasil Figma kamu 308x128 px)
        jumlahFrame = 5;
        lebarFrame = (float)spriteMC.width / jumlahFrame; // 308 / 4 = 77 px
        tinggiFrame = (float)spriteMC.height;            // 128 px

        // 3. Set Jendela Intip di awal (membaca frame ke-0)
        sourceRec = { 0.0f, 0.0f, lebarFrame, tinggiFrame };

        // Variabel waktu animasi
        frameAktif = 0;
        counterWaktu = 0;
        kecepatanAnimasi = 11;
        arahHadap =1.0f;
    }

    // DESTRUCTOR: Otomatis hapus gambar dari VRAM saat game ditutup biar tidak bocor (leak)
    ~karakter() {
        UnloadTexture(spriteMC);
    }

    void updateInput() {
        bool sedangJalan = false;

        // INPUT KONTROL jalan kanan-kiri
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
            posisi.x += kecepatan;
            sedangJalan = true;
            arahHadap = 1.0f;
        }
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
            posisi.x -= kecepatan;
            sedangJalan = true;
            arahHadap = -1.0f;
        }

        // --- LOGIKA UPDATE ANIMASI SPRITESHEET ---
        if (sedangJalan) {
            counterWaktu++;
            if (counterWaktu >= (60 / kecepatanAnimasi)) {
                counterWaktu = 0;
                frameAktif++;

                if (frameAktif >= jumlahFrame) frameAktif = 0;

                // Geser koordinat X jendela intip (0*77px, 1*77px, dst)
                sourceRec.x = (float)frameAktif * lebarFrame;
            }
        } else {
            // Jika diam, kembalikan ke frame pertama
            frameAktif = 0;
            
        }
        sourceRec.x = (float)frameAktif * lebarFrame;
        sourceRec.width = lebarFrame * arahHadap;
    }

    void draw() {
        // Menggambar Karakter memakai Gambar Texture, bukan lingkaran lagi!
        // Fungsi: DrawTextureRec(nama_texture, rectangle_potongan, posisi_vector2, warna_filter)
        DrawTextureRec(spriteMC, sourceRec, posisi, WHITE);
        
        // Tetap cetak nama di atas kepala karakter biar keren
        DrawText(nama.c_str(), posisi.x + 10, posisi.y - 20, 16, GRAY);
    }
};

int main() {
    InitWindow(800, 450, "Raylib - Mengingat Animasi Class");

    // Pemanggilan di int main jadi rapi banget, Dit!
    // Cukup tambahkan alamat path filemu di parameter terakhir
    karakter mc("Adit", 350.0f, 150.0f, 4.0f, "resources/mc4_jalan.png");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Update & Draw murni dikendalikan lewat class mc
        mc.updateInput();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        mc.draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}