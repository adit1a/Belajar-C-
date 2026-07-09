# Resep otomatis untuk compile game Raylib
all:
	g++ game1.cpp -o game1.exe -O3 -std=c++17 -Wall -I./Raylib/src -L./Raylib/src -lraylib -lopengl32 -lgdi32 -lwinmm -mwindows
	./game1.exe