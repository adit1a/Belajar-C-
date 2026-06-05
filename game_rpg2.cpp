#include "raylib.h"
#include <string>

using namespace std;

int main() {
    const int lebarLayar = 800;
    const int tinggiLayar = 450;
    InitWindow(lebarLayar, tinggiLayar, "Belajar Fundamental RPG - Adit");
    
    int hpPlayer = 100;
    int hpOrc = 50;
    string statusAksi = "tekan tombol space untuk menyerang!";
    
    SetTargetFPS(60); 
    
    while (!WindowShouldClose()) {
        // ─── LOGIKA INPUT & UPDATE ───
        if (IsKeyPressed(KEY_SPACE)) {
            if (hpOrc > 0) {
                hpOrc -= 15;
                statusAksi = "kamu menebas orc sebesar 15 damage";
                if (hpOrc < 0) hpOrc = 0;
            }
        }

        // ─── LOGIKA GAMBAR (DRAW) ───
        BeginDrawing();
        ClearBackground(BLACK); 
        
        DrawText("dungeon battlefield", 250, 30, 24, GOLD);
        DrawText(statusAksi.c_str(), 50, 350, 20, WHITE); 
        
        string teksHPPlayer = "hp kamu: " + to_string(hpPlayer);
        DrawText(teksHPPlayer.c_str(), 50, 150, 20, BLUE); 
        
        // Perbaikan struktur IF-ELSE untuk menggambar HP Orc
        if (hpOrc > 0) {
            string teksHPOrc = "hp orc : " + to_string(hpOrc);
            DrawText(teksHPOrc.c_str(), 600, 150, 20, RED);
        } else {
            DrawText("orc mati!", 600, 150, 20, GRAY);
        }
        
        EndDrawing();  
    } 
    
    CloseWindow();
    return 0;
}