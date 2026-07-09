#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "raylib.h"

using namespace std;

// Konstanta Ukuran Layar dan Posisi Lantai
const int WINDOW_W = 1600;
const int WINDOW_H = 800;
const float lantai = 600.0f;

// Status Game
enum class GameState { MENU, PLAYING, GAMEOVER, WIN };

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
    
    // Status Karakter
    int hp, maxHp, damage, coins;
    int facing; // 1 = kanan, -1 = kiri
    int attackCooldown;

    // Variabel Fisika
    float gravitasi = 0.5f;
    float kekuatanLompat = 50.0f; // Lompatan Tinggi/Super bawaan Adit

public:
    Player(float xAwal, float yAwal) {
        posisi = {xAwal, yAwal};
        ukuran = {40, 60};
        kecepatanX = 6.0f;
        kecepatanY = 0.0f;
        sdgMelompat = false;
        
        hp = 100; maxHp = 100;
        damage = 15;
        coins = 0;
        attackCooldown = 0;
        facing = 1;
    }

    void GerakX() {
        if (attackCooldown > 0) attackCooldown--;

        if (IsKeyDown(KEY_D)) { posisi.x += kecepatanX; facing = 1; }
        if (IsKeyDown(KEY_A)) { posisi.x -= kecepatanX; facing = -1; }
    }

    void GerakY() {
        if (IsKeyPressed(KEY_SPACE) && !sdgMelompat) {
            kecepatanY = -kekuatanLompat;
            sdgMelompat = true;
        }

        kecepatanY += gravitasi;
        posisi.y += kecepatanY;

        if (posisi.y + ukuran.y >= lantai) {
            posisi.y = lantai - ukuran.y;
            kecepatanY = 0.0f;
            sdgMelompat = false;
        }
    }

    void Draw() {
        DrawRectangleV(posisi, ukuran, BLUE);
        
        if (facing == 1) DrawRectangle(posisi.x + ukuran.x, posisi.y + 20, 15, 10, GOLD);
        else DrawRectangle(posisi.x - 15, posisi.y + 20, 15, 10, GOLD);

        DrawRectangle(posisi.x - 5, posisi.y - 15, ukuran.x + 10, 6, BLACK);
        float ratio = (float)hp / maxHp;
        DrawRectangle(posisi.x - 5, posisi.y - 15, (ukuran.x + 10) * ratio, 6, GREEN);
    }

    Rectangle GetRect() { return { posisi.x, posisi.y, ukuran.x, ukuran.y }; }
    Rectangle GetAttackRect() {
        return { facing == 1 ? posisi.x + ukuran.x : posisi.x - 50, posisi.y + 10, 50, 30 };
    }
    
    Vector2 GetPosisi() { return posisi; }
    float GetPosX() { return posisi.x; }
    void SetPosX(float x) { posisi.x = x; }
    float GetPosY() { return posisi.y; }
    void SetPosY(float y) { posisi.y = y; }
    float GetKecY() { return kecepatanY; }
    void SetKecY(float ky) { kecepatanY = ky; }
    void SetMelompat(bool status) { sdgMelompat = status; }
    
    int GetHp() { return hp; }
    void KurangiHp(int t) { hp -= t; if(hp < 0) hp = 0; }
    int GetDamage() { return damage; }
    int GetCoins() { return coins; }
    void TambahCoins(int c) { coins += c; }
    bool CanAttack() { return attackCooldown == 0; }
    void ResetAttackCooldown() { attackCooldown = 20; }
};

// ==========================================
// 2. CLASS ENEMY
// ==========================================
class Enemy {
private:
    Rectangle rect;
    int hp, maxHp, damage, loot;
    float startX, range;
    int dir;
    float speed;
    bool alive;
    int hitCooldown;

public:
    Enemy(float px, float py, float r) {
        rect = { px, py, 40, 50 };
        hp = 40; maxHp = 40;
        damage = 25;
        startX = px; range = r;
        dir = 1; speed = 2.0f;
        alive = true;
        loot = 15 + (rand() % 10);
        hitCooldown = 0;
    }

    void Update() {
        if (!alive) return;
        if (hitCooldown > 0) declineTrack();

        if (range > 0) {
            rect.x += dir * speed;
            if (rect.x > startX + range || rect.x < startX - range) dir *= -1;
        }
    }
    
    void declineTrack() { if (hitCooldown > 0) hitCooldown--; }

    void Draw() {
        if (!alive) return;
        DrawRectangleRec(rect, RED);
        
        DrawRectangle(rect.x - 2, rect.y - 12, rect.width + 4, 5, BLACK);
        float ratio = (float)hp / maxHp;
        DrawRectangle(rect.x - 2, rect.y - 12, (rect.width + 4) * ratio, 5, MAROON);
    }

    Rectangle GetRect() { return rect; }
    bool IsAlive() { return alive; }
    int GetDamage() { return damage; }
    int GetLoot() { return loot; }
    bool CanHit() { return hitCooldown == 0; }
    void ResetHitCooldown() { hitCooldown = 45; }
    
    void TerimaDamage(int dmg) {
        hp -= dmg;
        if (hp <= 0) alive = false;
    }
};

// ==========================================
// 3. CLASS OBSTACLE
// ==========================================
class Obstacle {
private:
    Rectangle rect;
public:
    Obstacle(float x, float y, float w, float h) { rect = {x, y, w, h}; }
    void Draw() { DrawRectangleRec(rect, DARKBROWN); }
    Rectangle GetRect() { return rect; }
};

// ==========================================
// 4. CLASS GAME (Manajer Level)
// ==========================================
class Game {
private:
    GameState state;
    Player player;
    vector<Enemy> enemies;
    vector<Obstacle> obstacles;
    Camera2D kamera;

public:
    Game() : player(100, 300) {
        state = GameState::MENU;
        ResetLevel();
    }

    void ResetLevel() {
        player = Player(100, 300);
        
        enemies.clear();
        enemies.push_back(Enemy(500, lantai - 50, 100));
        enemies.push_back(Enemy(900, lantai - 130, 80));
        enemies.push_back(Enemy(1300, lantai - 50, 99));

        obstacles.clear();
        obstacles.push_back(Obstacle(400, lantai - 60, 60, 60));
        obstacles.push_back(Obstacle(850, lantai - 80, 150, 80));

        // SETUP KAMERA AWAL
        kamera = {0};
        kamera.target = { player.GetPosX(), player.GetPosY() }; // PERBAIKAN: Target Y awal mengikuti player
        kamera.offset = { WINDOW_W / 2.0f, WINDOW_H / 2.0f };
        kamera.zoom = 1.0f;
    }

    void Update() {
        if (state == GameState::MENU) {
            if (IsKeyPressed(KEY_ENTER)) state = GameState::PLAYING;
        } 
        else if (state == GameState::PLAYING) {
            
            // --- 1. UPDATE SUMBU X PLAYER ---
            float xSebelumnya = player.GetPosX();
            player.GerakX(); 
            
            for (auto& o : obstacles) {
                if (CheckCollisionRecs(player.GetRect(), o.GetRect())) {
                    if (player.GetPosX() > xSebelumnya) player.SetPosX(o.GetRect().x - player.GetRect().width);
                    else player.SetPosX(o.GetRect().x + o.GetRect().width);
                }
            }

            // --- 2. UPDATE SUMBU Y PLAYER ---
            player.GerakY(); 
            
            for (auto& o : obstacles) {
                if (CheckCollisionRecs(player.GetRect(), o.GetRect())) {
                    if (player.GetKecY() > 0.0f) {
                        player.SetPosY(o.GetRect().y - player.GetRect().height);
                        player.SetKecY(0.0f);
                        player.SetMelompat(false);
                    } else if (player.GetKecY() < 0.0f) {
                        player.SetPosY(o.GetRect().y + o.GetRect().height);
                        player.SetKecY(0.0f);
                    }
                }
            }

            // --- 3. SERANGAN PLAYER KE MUSUH ---
            if (IsKeyPressed(KEY_J) && player.CanAttack()) {
                player.ResetAttackCooldown();
                for (auto& e : enemies) {
                    if (e.IsAlive() && CheckCollisionRecs(player.GetAttackRect(), e.GetRect())) {
                        e.TerimaDamage(player.GetDamage());
                        if (!e.IsAlive()) player.TambahCoins(e.GetLoot());
                    }
                }
            }

            // --- 4. UPDATE MUSUH ---
            bool allDead = true;
            for (auto& e : enemies) {
                if (e.IsAlive()) {
                    allDead = false;
                    e.Update();
                    
                    if (CheckCollisionRecs(player.GetRect(), e.GetRect()) && e.CanHit()) {
                        player.KurangiHp(e.GetDamage());
                        e.ResetHitCooldown();
                    }
                }
            }

            if (player.GetHp() <= 0) state = GameState::GAMEOVER;
            if (allDead) state = GameState::WIN;

            // --- 6. PERBAIKAN: UPDATE POSISI KAMERA MENGIKUTI LOMPATAN ---
            kamera.target.x = player.GetPosX();
            
            // Pilihan Opsi A (Kaku/Instan):
            // kamera.target.y = player.GetPosY();

            // Pilihan Opsi B (Halus / Smooth Tracking - REKOMENDASI):
            // Kamera mengejar koordinat Y player secara perlahan (0.1f = kecepatan kejar)
            kamera.target.y += (player.GetPosY() - kamera.target.y) * 0.1f;
        } 
        else if (state == GameState::GAMEOVER || state == GameState::WIN) {
            if (IsKeyPressed(KEY_R)) {
                ResetLevel();
                state = GameState::PLAYING;
            }
        }
    }

    void Draw() {
        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        if (state == GameState::MENU) {
            DrawRectangle(0, 0, WINDOW_W, WINDOW_H, DARKBLUE);
            DrawText("KNIGHT QUEST (RAYLIB OOP)", WINDOW_W/2 - 300, 250, 45, GOLD);
            DrawText("A/D: Jalan  |  SPACE: Lompat  |  J: Serang", WINDOW_W/2 - 250, 350, 20, RAYWHITE);
            DrawText("Tekan ENTER untuk Mulai", WINDOW_W/2 - 150, 420, 22, GREEN);
        } 
        else if (state == GameState::PLAYING) {
            
            BeginMode2D(kamera);
                // Langit kita tinggikan ukuran vertikalnya ke -4000 agar saat melompat tinggi, latar belakang tidak bocor hitam
                DrawRectangle(-1000, -4000, 7000, lantai + 4000, LIGHTGRAY); 
                DrawRectangle(800, 0, 100, 900, BLUE);
                DrawCircle(1200, 150, 60, YELLOW); 
                DrawRectangle(-1000, lantai, 7000, WINDOW_H - lantai + 2000, GRAY); // Tanah juga diperluas ke bawah

                for (auto& o : obstacles) o.Draw();
                for (auto& e : enemies) e.Draw();
                
                player.Draw();
                
                if (IsKeyDown(KEY_J)) DrawRectangleRec(player.GetAttackRect(), Fade(YELLOW, 0.4f));
            EndMode2D();

            DrawText(TextFormat("HP: %d/100", player.GetHp()), 20, 20, 24, RED);
            DrawText(TextFormat("KOIN: %d", player.GetCoins()), 250, 20, 24, GOLD);
        } 
        else if (state == GameState::GAMEOVER) {
            DrawRectangle(0, 0, WINDOW_W, WINDOW_H, BLACK);
            DrawText("GAME OVER", WINDOW_W/2 - 150, 300, 50, RED);
            DrawText("Tekan R untuk Main Lagi", WINDOW_W/2 - 140, 400, 20, RAYWHITE);
        } 
        else if (state == GameState::WIN) {
            DrawRectangle(0, 0, WINDOW_W, WINDOW_H, DARKGREEN);
            DrawText("KAMU MENANG!", WINDOW_W/2 - 180, 300, 50, GOLD);
            DrawText(TextFormat("Total Koin: %d", player.GetCoins()), WINDOW_W/2 - 80, 380, 24, RAYWHITE);
            DrawText("Tekan R untuk Main Lagi", WINDOW_W/2 - 140, 450, 20, RAYWHITE);
        }

        EndDrawing();
    }
};

int main() {
    InitWindow(WINDOW_W, WINDOW_H, "Knight Quest RPG - Final Version");
    SetTargetFPS(60);
    srand(time(0)); 
    Game myGame;

    while (!WindowShouldClose()) {
        myGame.Update();
        myGame.Draw();
    }
    
    CloseWindow();
    return 0;
}