#include "raylib.h"
#include <string>

using namespace std;

int main(){
    const int lebarLayar = 800;
    const int tinggiLayar = 450;

    InitWindow(lebarLayar, tinggiLayar, "tugas 1 BLACKSMITH");

    int levelSenjata = 1;
    int bahanBesi = 20;
    
    Font fontKeren = LoadFont("fonts/Inter-Bold.ttf");

    
    Rectangle panelInfo = { 200, 40, 400, 100 };
    Rectangle tombolUpgrade = { 300, 250, 200, 50 };
 
    int ukuranTeks = 15;


    SetTargetFPS(60);

    while (!WindowShouldClose()){
        Vector2 mousePos = GetMousePosition();
        bool mouseDiAtasTombol = CheckCollisionPointRec(mousePos, tombolUpgrade);

        BeginDrawing();
        DrawRectangleRec(panelInfo, GetColor(0x1e293bff));
        DrawRectangleLinesEx(panelInfo, 2, SKYBLUE);
        
        DrawText("Pedang Excalibur Adit", 220, 55, 20, WHITE);
        
        string teksStatus = "Level: " + to_string(levelSenjata) + "   |   Besi: " + to_string(bahanBesi);
        DrawText(teksStatus.c_str(), 220, 95, 18, LIGHTGRAY);
        
        Color warnaTombol = mouseDiAtasTombol ? LIGHTGRAY : GetColor(0x475569ff);
        DrawRectangleRec(tombolUpgrade, warnaTombol);
        
        ClearBackground (GetColor(0x111827ff));
        
        EndDrawing();
    }
    CloseWindow();
    return 0;


}