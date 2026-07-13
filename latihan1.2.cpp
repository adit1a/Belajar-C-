#include <vector>
#include <cstdlib>
#include <ctime>
#include "raylib.h"

using namespace std;

// void layar(){
//     const int lebarLayar = 800;
//     const int tinggiLayar = 400;
//     InitWindow(lebarLayar, tinggiLayar, " Belajar Logika koin");

// }

int main(){
    // layar();
    const int lebarLayar = 800;
    const int tinggiLayar = 400;
    InitWindow(lebarLayar, tinggiLayar, " Belajar Logika koin");
    SetTargetFPS(60);

    srand(time(0)); 

    // karakter
    Rectangle player ={100, 250, 40, 40};
    float speed = 5.0f;
    int totalKoin = 0;

    // wadah
    vector<Rectangle> daftarKoin;
    for(int i=0; i<3; i++){
        float acakX = rand() % (lebarLayar - 40)+20;
        float acakY = rand() % (tinggiLayar - 100)+60;
        daftarKoin.push_back({acakX, acakY, 20, 20});
    }
    Rectangle tombolReset = { 660, 20, 120, 40 };
    Color warnaTombol = LIGHTGRAY;

    while(!WindowShouldClose()){
        // pergerakan player
        if(IsKeyDown(KEY_D)) player.x += speed;
        if(IsKeyDown(KEY_A)) player.x -= speed;
        if(IsKeyDown(KEY_W)) player.y -= speed;
        if(IsKeyDown(KEY_S)) player.y += speed;

        // ambil posisi mouse
        Vector2 posisiMouse = GetMousePosition();

        // cek apakah mouse hover di tombol reset
        if(CheckCollisionPointRec(posisiMouse, tombolReset)){
            warnaTombol = GRAY;
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                totalKoin = 0;
                daftarKoin.clear();
                for(int i=0; i<3; i++){
                    float acakX = rand() % (lebarLayar - 40)+20;
                    float acakY = rand() % (tinggiLayar - 100)+60;
                    daftarKoin.push_back({acakX, acakY, 20, 20});
                }
            }
        } else {
            warnaTombol = LIGHTGRAY;
        }

        // logika memakan koin
        auto it = daftarKoin.begin();
        while(it != daftarKoin.end()){
            // cek tabrakan
            if(CheckCollisionRecs(player, *it)){
                totalKoin +=1;
                it = daftarKoin.erase(it);
            } else {
                ++it;
            }
        }
        BeginDrawing();
            ClearBackground(RAYWHITE);
            for (const auto& koin : daftarKoin){
                DrawRectangleRec(koin, GOLD);
            }
            DrawRectangleRec(player, BLUE);
            DrawRectangleRec(tombolReset, warnaTombol);
            DrawRectangleLinesEx(tombolReset, 2, BLACK);
            DrawText("RESET", tombolReset.x + 30, tombolReset.y + 12, 16, BLACK);
            DrawText(TextFormat("koin dikoleksi : %d", totalKoin), 20,20,22, BLACK);
            DrawText("dekati koin emas untuk di koleksi", 20, 50, 20, GRAY);
            
        EndDrawing();
    }
CloseWindow();
return 0;
}