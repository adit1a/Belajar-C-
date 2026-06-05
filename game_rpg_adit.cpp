#include "raylib.h"
#include <string>

using namespace std;

int main() {
    // Luas layar
    const int lebarLayar = 800;
    const int tinggiLayar = 450;
    
    // 1. PERBAIKAN: Huruf kapital 'I' dan nama variabel 'lebarLayar'
    InitWindow(lebarLayar, tinggiLayar, "Belajar Fundamental RPG - Adit");
    
    // Data Game
    int hpPlayer = 100;
    int hpOrc = 50;
    string statusAksi = "tekan tombol space untuk menyerang!";
    
    // 2. PERBAIKAN: Nama fungsi yang benar adalah SetTargetFPS
    SetTargetFPS(60); 
    
    // 3. PERBAIKAN: Hilangkan tanda kurung luar di while
    while (!WindowShouldClose()) {
        
        // Logika Input & Update
        if (IsKeyPressed(KEY_SPACE)) {
            if (hpOrc > 0) {
                hpOrc -= 15;
                statusAksi = "kamu menebas orc sebesar 15 damage";
                
                if (hpOrc < 0) hpOrc = 0;
            } // Penutup if hpOrc > 0
        } // Penutup if IsKeyPressed

        // 4. PERBAIKAN: Wajib pasang BeginDrawing dan ClearBackground sebelum menggambar
        BeginDrawing();
        ClearBackground(BLACK); // Biar layarnya bersih warna hitam tiap frame
        
        // Menggambar Semua Teks
        DrawText("dungeon battlefield", 250, 30, 24, GOLD);
        
        // 5. PERBAIKAN: Tambah koma sebelum BLUE dan sesuaikan posisi koordinat X agar tidak menumpuk
        DrawText(statusAksi.c_str(), 50, 350, 20, WHITE); 
        
        string teksHPPlayer = "hp kamu: " + to_string(hpPlayer);
        DrawText(teksHPPlayer.c_str(), 50, 150, 20, BLUE); // Pindah ke kiri (X: 50) biar tidak tabrakan
        
        if (hpOrc > 0) {
            string teksHPOrc = "hp orc : " + to_string(hpOrc);
            DrawText(teksHPOrc.c_str(), 600, 150, 20, RED);
        } else {
            DrawText("orc mati!", 600, 150, 20, GRAY);
        }
        
        // 6. PERBAIKAN: Huruf kapital 'E' pada EndDrawing
        EndDrawing();  
    } // Penutup while
    
    CloseWindow();
    return 0;
}