#include "raylib.h"
#include <string>

using namespace std;

class karakter{
    protected:
        string nama;
        Vector2 posisi;
        float kecepatan;
    public:
        karakter(string namAwal, float x, float y, float speed){
            nama =namAwal;
            posisi={x,y};
            kecepatan=speed;
        }
    void updateInput(){
        if(IsKeyDown(KEY_RIGHT)||IsKeyDown(KEY_D)) posisi.x += kecepatan;
        if(IsKeyDown(KEY_LEFT)||IsKeyDown(KEY_A)) posisi.x -= kecepatan;

    }
    void Draw(){
        float radiusSesuai = 45.0f;
        DrawCircleV(posisi, radiusSesuai, BLUE);
        DrawText(nama.c_str(), posisi.x - 22, posisi.y - 7, 20, WHITE);
    }

};

int main()
{
    const int lebarL = 800;
    const int tinggiL = 450;
    InitWindow(lebarL,tinggiL, "raylib belajar lagi");

    karakter mc("ardir", 400.0f, 225.0f, 15.0f);

    SetTargetFPS(60);
    while(!WindowShouldClose()){
        mc.updateInput();
        BeginDrawing();
        ClearBackground(RAYWHITE);

        mc.Draw();
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}