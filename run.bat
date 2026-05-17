@echo off
echo Mengompilasi kode Raylib Adit...
C:\raylib\w64devkit\bin\g++.exe latihan11.cpp -o aplikasi.exe -B C:\raylib\w64devkit\bin\ -I C:\raylib\w64devkit\x86_64-w64-mingw32\include -L C:\raylib\w64devkit\x86_64-w64-mingw32\lib -lraylib -lopengl32 -lgdi32 -lwinmm

if %errorlevel% equ 0 (
    echo Kompilasi Berhasil! Menjalankan aplikasi...
    aplikasi.exe
) else (
    echo Ada yang error, cek kodinganmu lagi Dit!
)
pause