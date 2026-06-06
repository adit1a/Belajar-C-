#include <iostream>
#include <string>
#include "raylib.h"

using namespace std;

int main(){
    const int lebarLayar = 800;
    const int tinggiLayar = 400;
    InitWindow(lebarLayar, tinggiLayar, "FIsika Dasar Ui Belajar Raylib");

    // karakter dengan logika

    float karakterX = 500;
    float karakterY = 300;
    float kecepatanY = 5;
    const float nilaiGravitasi = 0.5f;
    const float kekuatanLompatan = -10.0f;
    const int batasTanah = 300;

    // variable ui tombol reset

    Rectangle tombolReset = { 650, 50, 100, 50 };
    string teksTombol = "restart";
    int ukuranTombol = 15;

    SetTargetFPS(60);

    while (!WindowShouldClose()){
        Vector2 mousePos = GetMousePosition();
        karakterY += kecepatanY;
        kecepatanY += nilaiGravitasi;
        
        if(IsKeyDown(KEY_RIGHT)){
            karakterX += kecepatanY;
        }
        if(IsKeyDown(KEY_LEFT)){
            karakterX -= kecepatanY;
        }
        
        if (karakterY >= batasTanah){
            karakterY = batasTanah;
            kecepatanY = 0;
        }
        if(IsKeyPressed(KEY_SPACE) && karakterY >= batasTanah){
            kecepatanY = kekuatanLompatan;

        }
        bool mouseDiAtasTombol = CheckCollisionPointRec(mousePos, tombolReset);
        if (mouseDiAtasTombol && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            karakterX = 100;
            karakterY = 300;
            kecepatanY = 0;
        }
        BeginDrawing();
        ClearBackground (GetColor(0x111827ff));

        // 1. Gambar Batas Tanah Pijakan (Lantai)
        DrawLine(0, batasTanah + 50, lebarLayar, batasTanah + 50, GRAY);
        DrawRectangle(0, batasTanah + 50, lebarLayar, tinggiLayar - (batasTanah + 50), GetColor(0x1f2937ff));

        // 2. Gambar Karakter (Kotak Merah yang dipengaruhi Gravitasi)
        DrawRectangle(karakterX, karakterY, 50, 50, RED);
        DrawText("Tekan Spasi untuk Melompat", karakterX - 40, karakterY - 25, 14, WHITE);

        // 3. gambar ui

        DrawRectangle(30,20, 320, 60, GetColor(0x1f2937ff));
        DrawRectangleLines(30, 20, 320, 60, SKYBLUE);

        string teksStatusY ="Koordinat Y Karakter: " + to_string((int)karakterY);
        DrawText(teksStatusY.c_str(), 45, 40, 16, SKYBLUE);

        // 4. Gambar UI INTERAKTIF: Tombol Reset dengan State Warna
        Color warnaTombolSaatIni = warnaTombolSaatIni = mouseDiAtasTombol ? LIGHTGRAY : GetColor(0x374151ff);
        DrawRectangleRec(tombolReset, warnaTombolSaatIni);
        DrawRectangleLinesEx(tombolReset, 2, mouseDiAtasTombol ? WHITE : GRAY);

        // Trik Matematis Menaruh Teks Tepat di Tengah Kotak Tombol

        int lebarTeks =MeasureText(teksTombol.c_str(), ukuranTombol);
        int posisiTeksX=tombolReset.x + (tombolReset.width / 2) - (lebarTeks / 2);
        int posisiTeksY = tombolReset.y + (tombolReset.height /2) - (ukuranTombol /2);
        DrawText(teksTombol.c_str(), posisiTeksX, posisiTeksY, ukuranTombol, WHITE);

        EndDrawing();

    }
    CloseWindow();
    return 0;
}