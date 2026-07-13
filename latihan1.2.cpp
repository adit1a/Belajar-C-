#include <vector>
#include "raylib.h"

using namespace std;

void layar(){
    const int lebarLayar = 800;
    const int tinggiLayar = 400;
    InitWindow(lebarLayar, tinggiLayar, " Belajar Logika koin");

}

int main(){
    layar();
    SetTargetFPS(60);

    // karakter
    Rectangle player ={100, 250, 40, 40};
    float speed = 5.0f;
    int totalKoin = 0;

    // wadah
    vector<Rectangle> daftarKoin;
    daftarKoin.push_back({300, 260, 20, 20});
    daftarKoin.push_back({500, 200, 20, 20});
    daftarKoin.push_back({600, 400, 20, 20});

    while(!WindowShouldClose()){
        // pergerakan player
        if(IsKeyDown(KEY_D)) player.x += speed;
        if(IsKeyDown(KEY_A)) player.x -= speed;
        if(IsKeyDown(KEY_W)) player.y -= speed;
        if(IsKeyDown(KEY_S)) player.y += speed;

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
            DrawText(TextFormat("koin dikoleksi : %d", totalKoin), 20,20,22, BLACK);
            DrawText("dekati koin emas untuk di koleksi", 20, 50, 20, GRAY);
        EndDrawing();
    }
CloseWindow();
return 0;
}