#include <vector>
#include "raylib.h"
#include <string>

using namespace std;

const int lebarL = 1600;
const int tinggiL = 800;
const float lantai = 500.0f;
const float BATAS_JURANG = 1000.0f; // Koordinat Y di mana player dianggap jatuh total

// ==========================================
// 1. CLASS PLAYER
// ==========================================
class Player {
private:
    Vector2 posisi;
    Vector2 ukuran;
    float kecepatanX;
    float kecepatanY;
    bool sdgMelompat;
    bool statusMatiJurang; 
    Color warna;

    const float gravitasi = 0.5f;
    const float kekuatanLompat = 12.0f;

public:
    Player(float xAwal, float yAwal, Color warnaAwal) {
        ResetPosisi(xAwal, yAwal);
        ukuran = {40, 40};
        kecepatanX = 5.0f;
        warna = warnaAwal;
    }
    
    ~Player() {}

    void ResetPosisi(float x, float y) {
        posisi = {x, y};
        kecepatanY = 0.0f;
        sdgMelompat = false;
        statusMatiJurang = false;
    }

    void GerakX() {
        if (statusMatiJurang) return;

        if (IsKeyDown(KEY_D)) posisi.x += kecepatanX;
        if (IsKeyDown(KEY_A)) posisi.x -= kecepatanX;
    }

    void GerakY() {
        if (IsKeyPressed(KEY_SPACE) && !sdgMelompat && !statusMatiJurang) {
            kecepatanY = -kekuatanLompat;
            sdgMelompat = true;
        }

        kecepatanY += gravitasi;
        posisi.y += kecepatanY;

        // PERBAIKAN UTAMA: Mengunci lantai dari X = -500 sampai X = 1400
        // Sekarang jika kamu melewati X = -500 ke arah belakang, karakter akan jatuh (tidak melayang lagi)
        if (posisi.x >= -500.0f && posisi.x < 1400.0f) {
            if (posisi.y + ukuran.y >= lantai) {
                posisi.y = lantai - ukuran.y;
                kecepatanY = 0.0f;
                sdgMelompat = false;
            }
        }
    }

    void draw() {
        DrawRectangleV(posisi, ukuran, warna);
    }
    
    // Getter & Setter
    float GetPosisiX() { return posisi.x; }
    void SetPosisiX(float baruX) { posisi.x = baruX; }
    float GetPosisiY() { return posisi.y; }
    void SetPosisiY(float baruY) { posisi.y = baruY; }
    float GetKecepatanY() { return kecepatanY; }
    void SetKecepatanY(float baruKecY) { kecepatanY = baruKecY; }
    void SetSdgMelompat(bool status) { sdgMelompat = status; }
    
    bool IsMatiJurang() { return statusMatiJurang; }
    void SetMatiJurang(bool status) { statusMatiJurang = status; }

    Vector2 GetPosisi() { return posisi; }
    Rectangle GetRect() { return { posisi.x, posisi.y, ukuran.x, ukuran.y }; }
};

// ==========================================
// 2. CLASS RINTANGAN
// ==========================================
class Rintangan {
private:
    Rectangle rect;
    Color warna;
    
public:
    Rintangan(float x, float y, float lebar, float tinggi, Color warnaAwal) {
        rect = {x, y, lebar, tinggi};
        warna = warnaAwal;
    }
    ~Rintangan() {}
    void gambar() { DrawRectangleRec(rect, warna); }
    Rectangle GetRect() { return rect; }
};

// ==========================================
// 3. CLASS GAME (Manajer Utama)
// ==========================================
class Game {
private:
    Player player;
    vector<Rintangan> daftarRintangan;
    Camera2D kamera;
    
    float timerJatuh;
    const float DURASI_RESPAWN = 5.0f; 

public:
    Game() : player(100, 360, BLUE) {
        daftarRintangan.push_back(Rintangan(500, 420, 100, 80, RED));
        daftarRintangan.push_back(Rintangan(800, 350, 150, 150, RED));
        daftarRintangan.push_back(Rintangan(1100, 400, 120, 100, RED));
        
        timerJatuh = 0.0f;

        kamera = {0};
        kamera.target = player.GetPosisi();
        kamera.offset = {lebarL / 2.0f, tinggiL / 2.0f };
        kamera.rotation = 0.0f;
        kamera.zoom = 1.0f;
    }
    
    ~Game() {}

    void updateGame() {
        if (player.IsMatiJurang()) {
            player.GerakY(); 
            timerJatuh += GetFrameTime();
            if (timerJatuh >= DURASI_RESPAWN) {
                player.ResetPosisi(100, 360); 
                timerJatuh = 0.0f;            
            }
            return; 
        }

        float xSebelumnya = player.GetPosisiX();
        player.GerakX(); 

        // Deteksi Tabrakan Sumbu X
        for (size_t i = 0; i < daftarRintangan.size(); i++) {
            if (CheckCollisionRecs(player.GetRect(), daftarRintangan[i].GetRect())) {
                if (player.GetPosisiX() > xSebelumnya) player.SetPosisiX(daftarRintangan[i].GetRect().x - 40);
                else if (player.GetPosisiX() < xSebelumnya) player.SetPosisiX(daftarRintangan[i].GetRect().x + daftarRintangan[i].GetRect().width);
            }
        }

        player.GerakY(); 

        // Deteksi Tabrakan Sumbu Y
        for (size_t i = 0; i < daftarRintangan.size(); i++) {
            if (CheckCollisionRecs(player.GetRect(), daftarRintangan[i].GetRect())) {
                if (player.GetKecepatanY() > 0.0f) {
                    player.SetPosisiY(daftarRintangan[i].GetRect().y - 40);
                    player.SetKecepatanY(0.0f);
                    player.SetSdgMelompat(false);
                }
                else if (player.GetKecepatanY() < 0.0f) {
                    player.SetPosisiY(daftarRintangan[i].GetRect().y + daftarRintangan[i].GetRect().height);
                    player.SetKecepatanY(0.0f);
                }
            }
        }

        if (player.GetPosisiY() >= BATAS_JURANG) {
            player.SetMatiJurang(true); 
        }

        if (!player.IsMatiJurang()) {
            kamera.target.x = player.GetPosisiX();
        }
    }

    void drawGame() {
        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        BeginMode2D(kamera);
            // Lantai digambar secara visual dari X = -500 sampai 1400 (Lebar total 1900)
            DrawRectangle(-500, lantai, 1900, 50, GRAY); 
            
            for (size_t i = 0; i < daftarRintangan.size(); i++) {
                daftarRintangan[i].gambar();
            }
            player.draw();
        EndMode2D();
        
        if (player.IsMatiJurang()) {
            DrawRectangle(0, 0, lebarL, tinggiL, Fade(BLACK, 0.4f)); 
            DrawText(TextFormat("ANDA JATUH! Mengulang kembali dalam: %.1f detik", DURASI_RESPAWN - timerJatuh), 450, 350, 30, RAYWHITE);
        } else {
            DrawText("FIXED: Batas belakang (X < -500) dan batas depan (X > 1400) sekarang adalah JURANG!", 20, 20, 20, BLACK);
            DrawText(TextFormat("Posisi X Player: %.0f", player.GetPosisiX()), 20, 50, 20, BLUE);
        }
        
        EndDrawing();
    }
};

// ==========================================
// 4. MAIN PROGRAM
// ==========================================
int main() {
    InitWindow(lebarL, tinggiL, "Raylib Platformer - Fixed Ground Boundaries");
    SetTargetFPS(60);

    Game myGame;

    while (!WindowShouldClose()) {
        myGame.updateGame();
        myGame.drawGame();
    }
    
    CloseWindow();
    return 0;
}