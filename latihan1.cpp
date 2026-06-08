#include "raylib.h"
#include <string>

using namespace std;

int main(){
    const int lebarL=1000;
    const int tinggiL=600;
    InitWindow(lebarL,tinggiL,"latihan 1 - kotak dengan teks");

    int ukuranTeks=20;
    int lebarKotak=200;
    int tinggiKotak=100;

    int kotakX=(lebarL/2)-(lebarKotak/2);
    int kotakY=(tinggiL/2)-(tinggiKotak/2);

    Rectangle kotakTengah = { (float)kotakX, (float)kotakY, (float)lebarKotak, (float)tinggiKotak };
    Rectangle tombol = { 396, 80, 200, 50 };
    int ukuranTeksTombol = 18;

     SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // 1. Gambar Kotak Pertama
        DrawRectangleRec(kotakTengah, GetColor(0xFF6C5B7B)); 
        DrawRectangleLinesEx(kotakTengah, 4, GetColor(0xFFF67280)); 
        DrawText("Halo, Raylib!", kotakX + 20, kotakY + (tinggiKotak / 2) - (ukuranTeks / 2), ukuranTeks, BLACK);
        
        // 2. Gambar Kotak Kedua (Tombol Rounded)
        DrawRectangleRounded(tombol, 0.3f, 6, GetColor(0x38bdf8ff)); // Biru kustom

        // PERBAIKAN MATEMATIKA: Menghitung teks agar tepat di tengah tombol rounded
        int lebarTeksTombol = MeasureText("MULAI GAME", ukuranTeksTombol);
        int teksTombolX = tombol.x + (tombol.width / 2) - (lebarTeksTombol / 2);
        int teksTombolY = tombol.y + (tombol.height / 2) - (ukuranTeksTombol / 2);
        
        // Gambar teksnya di koordinat hasil hitungan dinamis
        DrawText("MULAI GAME", teksTombolX, teksTombolY, ukuranTeksTombol, GetColor(0x0f172aff));
        
        EndDrawing();
    }
    CloseWindow();
    return 0;

}