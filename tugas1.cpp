#include "raylib.h"
#include <string>

using namespace std;

int main() {
    const int lebarLayar = 800;
    const int tinggiLayar = 450;
    
    // 1. Perbaikan: Sesuaikan variabel string pesanStatus
    string pesanStatus = "Silakan tempa pedangmu, Adit!"; 

    InitWindow(lebarLayar, tinggiLayar, "tugas 1 BLACKSMITH - Adit");

    int levelSenjata = 1;
    int bahanBesi = 20;

    
    // Memuat font eksternal
    Font fontKeren = LoadFont("fonts/Inter-Bold.ttf");

    Rectangle panelInfo = { 200, 40, 400, 100 };
    Rectangle tombolUpgrade = { 300, 250, 200, 50 };
    int ukuranTeks = 15;

    SetTargetFPS(60);

    // Jantung Game Loop Mulai
    while (!WindowShouldClose()) {
        Vector2 mousePos = GetMousePosition();
        bool mouseDiAtasTombol = CheckCollisionPointRec(mousePos, tombolUpgrade);
        
        // 2. Perbaikan: Definisikan apa itu tombolDitekan (Klik kiri mouse ATAU tombol F)
       // 1. Definisikan aksi input keyboard
bool tekanSpasi = IsKeyPressed(KEY_SPACE);
bool tekanF     = IsKeyPressed(KEY_F);
bool klikTombol = mouseDiAtasTombol && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

// 2. Jalankan logika berdasarkan aksi pemain
if (klikTombol || tekanSpasi) { 
    // AKSI 1: Menempa Pedang
    if (bahanBesi >= 5) {
        levelSenjata++;
        bahanBesi -= 5;
        pesanStatus = "Sukses! Pedang berhasil ditempa +1 Level.";
    } else {
        pesanStatus = "Gagal Menempa! Bahan Besi Tidak Cukup.";
    }
} 
else if (tekanF) { 
    // AKSI 2: Mengisi Ulang Besi (Hanya jika besi habis)
    if (bahanBesi <= 0) {
        bahanBesi += 20; // Langsung tambah banyak biar bisa tempa lagi
        pesanStatus = "Bahan Besi berhasil ditambahkan!";
    } else {
        pesanStatus = "Besi masih ada, silakan tempa dulu!";
    }
}
        
   
        // PROSES DRAWING
        BeginDrawing();
        
        // 3. Perbaikan: ClearBackground WAJIB di baris pertama setelah BeginDrawing
        ClearBackground(GetColor(0x111827ff)); 
       
        // Gambar Panel Informasi
        DrawRectangleRec(panelInfo, GetColor(0x1e293bff));
        DrawRectangleLinesEx(panelInfo, 2, SKYBLUE);
        
        DrawText("Pedang Excalibur Adit", 220, 55, 20, WHITE);
        
        string teksStatus = "Level: " + to_string(levelSenjata) + "   |   Besi: " + to_string(bahanBesi);
        DrawText(teksStatus.c_str(), 220, 95, 18, LIGHTGRAY);
        
        // Gambar Tombol Upgrade
        Color warnaTombol = mouseDiAtasTombol ? LIGHTGRAY : GetColor(0x475569ff);
        DrawRectangleRec(tombolUpgrade, warnaTombol);
        
        // 4. Perbaikan: Trik matematika menaruh teks tepat di tengah tombol upgrade
        string teksTombol = "TAMBAH (F)";
        int lebarTeksTombol = MeasureText(teksTombol.c_str(), ukuranTeks);
        int posisiTeksX = tombolUpgrade.x + (tombolUpgrade.width / 2) - (lebarTeksTombol / 2);
        int posisiTeksY = tombolUpgrade.y + (tombolUpgrade.height / 2) - (ukuranTeks / 2);
        DrawText(teksTombol.c_str(), posisiTeksX, posisiTeksY, ukuranTeks, WHITE);
        
        //  5. tombol penambah bahan besi
        string teksTombol2 = "TEMPA PEDANG (SPACE)";
        int lebarTeksTombol2 = MeasureText(teksTombol2.c_str(), ukuranTeks);
        int posisiTeksX2 = tombolUpgrade.x + (tombolUpgrade.width / 2) - (lebarTeksTombol2 / 2);
        int posisiTeksY2 = tombolUpgrade.y + tombolUpgrade.height + 20; // Sedikit jarak di bawah tombol pertama
        DrawText(teksTombol2.c_str(), posisiTeksX2, posisiTeksY2, ukuranTeks, BLUE);
        // Gambar Teks Status Pesan di bawah Panel (Biar kelihatan pas besinya habis)
        DrawText(pesanStatus.c_str(), 220, 160, 16, GOLD);
        
        EndDrawing();
    } // <--- Kurung kurawal while loop yang benar ada di sini!

    // 5. Perbaikan: Hapus font dari memori sebelum aplikasi ditutup
    UnloadFont(fontKeren); 
    CloseWindow();
    return 0;
}