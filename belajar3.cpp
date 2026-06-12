#include "raylib.h"
#include <string>

using namespace std;

struct karakter{
    Vector2 posisi;
    int darah;
    float kecepatan;
    Color warna;
    float kecepatanY;
    bool sedangMelompat;
};

int main (){
    const int tinggiL=800;
    const int lebarL=450;
    InitWindow(tinggiL,lebarL, "rayli-belajar");
    
    karakter mc;
    mc.posisi = {450.0f, 255.0f };
    mc.darah= 100;
    mc.kecepatan=10.0f;
    mc.warna =RED;
    mc.kecepatanY = 0.0f;
    mc.sedangMelompat=false;

    karakter npc;
    npc.posisi = {450.0f, 400.0f};
    npc.darah = 100;
    npc.kecepatan = 5.0f;
    npc.warna = BLUE;
    mc.kecepatanY = 0.0f;
    mc.sedangMelompat=false;

    float gravitasi =0.5f;
    float posisiTanah = 350.0f;
    float radiusMc = 30.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // logika gravitasi karakter
        mc.kecepatanY += gravitasi;
        mc.posisi.y += mc.kecepatanY;

        // Hitung batas titik terbawah (kaki) MC berdasarkan posisi tengah + radius
        float kakiMc = mc.posisi.y + radiusMc;

        // DETEKSI TABRAKAN GARIS TANAH
        if (kakiMc >= posisiTanah){
            // Paksa posisi kaki MC tepat menempel di atas garis tanah (tidak tembus)
            mc.posisi.y=posisiTanah-radiusMc;
            mc.kecepatanY=0.0f;
            mc.sedangMelompat = false;
        }
        if (IsKeyPressed(KEY_SPACE) && !mc.sedangMelompat){
            mc.kecepatanY = -12.0f;
            mc.sedangMelompat = true;
        }
        if ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) && (mc.posisi.x < 770.0f)) {
        mc.posisi.x += mc.kecepatan;
        }
        if ((IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))&& (mc.posisi.x > 30.0f)) {
            mc.posisi.x -= mc.kecepatan;
        }

        BeginDrawing();
        ClearBackground(GRAY);
        DrawText("tekan space untuk lompat dan tekan A ke kiri dan D ke kanan", 20, 20, 20, GRAY);
        DrawLine(0, posisiTanah, 800, posisiTanah, BLACK);
        DrawCircleV(mc.posisi, radiusMc, mc.warna);
        DrawText("MC", mc.posisi.x - 12, mc.posisi.y - 5, 20, WHITE);
        DrawCircleV(npc.posisi, 20, npc.warna);
        DrawText("npc", npc.posisi.x - 40, npc.posisi.y - 35, 16, GRAY);

        EndDrawing();
    }
    CloseWindow();
    return 0; 
}
