#include "raylib.h"
#include <string>

using namespace std;

struct toko{
    string namaBarang;
    int harga;
    int stok;
    Vector2 posisiTombol;
};

int main()
{
    const int lebarL=800;
    const int tinggiL=450;
    InitWindow(lebarL,tinggiL, "raylib berlajar");

    toko etalase[3];
    etalase[0] = { "Beras 1kg", 15000, 10, { 50, 150, 200, 80 } };
    etalase[1] = { "Minyak 1L", 18000, 5,  { 280, 150, 200, 80 } };
    etalase[2] = { "Gula 1kg",  14000, 8,  { 510, 150, 200, 80 } };

    int totalBelanja = 0;
    string barangTerakhir = "belum ada";
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        Vector2 posisiMouse =GetMousePosition();

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            for(int i=0; i<3; i++){
                if(CheckCollisionPointRec(posisiMouse, etalase[i].areaKlik)){
                    if (etalase[i].stok > 0){
                        etalase[i].stok--;                
                        totalBelanja += etalase[i].harga; 
                        barangTerakhir = etalase[i].namaBarang;
                    }
                }
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawRectangle(0,0, lebarL, 67, LIGHTGRAY);
        DrawText("TOKO SEMBAKO JAYA - KLIK BARANG UNTUK MEMBELI", 20, 20, 20, BLACK);

        for(int i=0; i<3; i++){
            DrawRectangleRec(etalase[i].areaKlik, SKYBLUE);
            DrawRectangleLinesEx(etalase[i].areaKlik, 2, BLUE);
        }
    }

}