#include "raylib.h"
#include <string>

using namespace std;

int main (){
    const int lebarLayar = 800;
    const int tinggiLayar = 450;
    InitWindow(lebarLayar, tinggiLayar, "Latihan 2 - teks dan tombol");

    string isiTeks = "belum ada isi....";

    Rectangle areaTeks = { 50, 50, 300, 50 };
    Rectangle button = { 50, 150, 200, 50 };
    int ukuranTeks = 20;

    SetTargetFPS(60);
    
    // 1. Perbaikan: WindowShouldClose (tanpa s)
    while(!WindowShouldClose()){
        Vector2 mousePos = GetMousePosition();
        bool mouseAtas = CheckCollisionPointRec(mousePos, button);

        if (mouseAtas && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            isiTeks = "Tombol Ditekan!";
        }
        
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // 4. Perbaikan: Nilai roundness diubah dari 10.0f ke 0.3f agar tumpulnya pas
        
        DrawRectangleRounded(areaTeks, 0.3f, 10, LIGHTGRAY);
        DrawRectangleRoundedLines(areaTeks, 0.3f, 10, GRAY);
        
        // 3. Perbaikan: Menambahkan ukuran font dan warna BLACK di DrawText
        int isiTeksY = areaTeks.y + (areaTeks.height / 2) - (ukuranTeks / 2);
        DrawText(isiTeks.c_str(), areaTeks.x + 10, isiTeksY, ukuranTeks, BLACK);

        // 2. Perbaikan: 'color' diubah menjadi 'Color' kapital
        Color tombolWarna = mouseAtas ? DARKBLUE : BLUE;
        DrawRectangleRounded(button, 0.3f, 10, tombolWarna);

        Color warnaTeks = mouseAtas ? YELLOW : WHITE;

        // 5. Perbaikan: Sinkronisasi teks "silahkan klik" di MeasureText
        int lebarTeksTombol = MeasureText("silahkan klik", ukuranTeks);
        int teksX = button.x + (button.width / 2) - (lebarTeksTombol / 2);
        int teksY = button.y + (button.height / 2) - (ukuranTeks / 2);
        DrawText("silahkan klik", teksX, teksY, ukuranTeks, warnaTeks);

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}