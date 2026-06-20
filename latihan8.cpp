#include "raylib.h"
#include <string>

using namespace std;

const int lebarL=1600;
const int tinggiL=800;

class kendaraan{
    protected:
        string nama;
        float posX;
        float posY;
        float kecepatan;
        Color Warna;
    public:
        kendaraan(string namaBaru, float xAwal, float yAwal, float kecAwal, Color warnaAwal);
        ~kendaraan();

        // fungsi
        void updateInput();
        void gambar();
        void tampilkanInfo();
};

kendaraan::kendaraan(string namaBaru, float xAwal, float yAwal, float kecAwal, Color warnaAwal)
    : nama(namaBaru), posX(xAwal), posY(yAwal), kecepatan(kecAwal), Warna(warnaAwal)
{
}
kendaraan::~kendaraan() 
{
}
void kendaraan::updateInput(){
    if(IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) posX += kecepatan;
    if(IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) posX -= kecepatan;
    if(IsKeyDown(KEY_UP)) posY -= kecepatan;
    if(IsKeyDown(KEY_DOWN)) posY += kecepatan;
}
void kendaraan::gambar(){
    DrawRectangle(posX,posY, 60, 40, Warna);
}
void kendaraan::tampilkanInfo(){
    DrawRectangle(0, 700, lebarL, 100, DARKGRAY);
    string teksNama = "KENDARAAN: " + nama;
    DrawText(teksNama.c_str(), 20, 735, 20, RAYWHITE);
}

int main()
{
    InitWindow(lebarL,tinggiL, "raylib");
    SetTargetFPS(60);

    kendaraan myMobil("mobilS", 100.0f, 250.0f, 5.0f, BLUE);

    while(!WindowShouldClose())
    {
        myMobil.updateInput();
        BeginDrawing();
        ClearBackground(RAYWHITE);

        myMobil.gambar();
        myMobil.tampilkanInfo();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}