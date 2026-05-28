#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

struct player{
    string nama;
    
};

void kata(string teks, int kecepatan){
    for(int i=0; i<teks.length(); i++){
        cout<<teks[i];
        Sleep(kecepatan);
    }
    cout<<endl;
}
void Kata(string teks, int kecepatan){
    for(int i=0; i<teks.length(); i++){
        cout<<teks[i];
        Sleep(kecepatan);
    }
   
}
void garis(){
    cout<<"=============================="<<endl;
}

void loading(){
    kata("Loading", 100);
    for(int i=0; i<5; i++){
        cout<<".";
        Sleep(500);
    }
    cout<<endl;
}
void senjata(int pilihan, int kode){
    switch(pilihan){
        case 1:
                cout<<"senjata kamu adalah pisau""\n";
                break;
        case 2:
                cout<<"senjata kamu adalah pedang""\n";
                break;
        case 3:
                cout<<"senjata kamu adalah kapak""\n";
                break;
        case 4:
                cout<<"senjata kamu adalah tombak""\n";
                break;
        default:               
         cout<<"pilihan tidak valid""\n";
         break;
            
        
    }
}
int main()
{
    player p1;
    int pilihanUser =0;
    string musuh[] = {"goblin", "great goblin", "orc", "dragon"};
    srand(time(0));
    garis();
    cout<<"===========Ryuhlon============="<<endl;
    garis();
    Kata("Masukkan nama player 1 : ", 200);
    getline(cin, p1.nama);
    loading();
    kata("nama kamu adalah ... " + p1.nama + " karakter", 200);
    kata("wahai pemuda "+p1.nama+" wahai pemuda tolong kami, selamatkan kami", 100);
    Kata("silahkan pilih senjata kamu (1-3) " +p1.nama, 100);
    cin>>pilihanUser;
    senjata(pilihanUser, 0);
    int musuhRandom = rand() % 4;
    kata("tiba-tiba muncul " + musuh[musuhRandom], 200);
    if(pilihanUser == 1 && musuh[musuhRandom] == "goblin"){
        kata("kamu menghadapi goblin dengan pisau", 200);
        kata("kamuharus melempar dadu 1-6 untuk menentukan damage yg kamu berikan", 200);
        int dadu = rand() % 6+1;
        int hpMusuh = 25;
        loading();
        if (dadu == 1){
            kata("damage kamu adalah 10 " + to_string(hpMusuh - 10) + "hp", 200);
            kata("lempar lagi dadunya untuk menentukan damage tambahan", 200);
            int daduTambahan = rand() % 6+1;
            if(daduTambahan == 1){
                kata("damage tambahan kamu adalah 5 hp musuh " + to_string(hpMusuh - 5) + "hp", 200);
            }
            else if(daduTambahan > 1 && daduTambahan <=3){
                kata("damage tambahan kamu adalah 10 hp musuh " + to_string(hpMusuh - 10) + "hp", 200);
            }
            else if(daduTambahan > 3 && daduTambahan <=5 ){
                kata("damage tambahan kamu adalah 15 hp musuh " + to_string(hpMusuh - 15) + "hp", 200);
            }
            else if(daduTambahan == 6){
                kata("damage tambahan kamu adalah 20 hp musuh " + to_string(hpMusuh - 20) + "hp", 200);
            }
        }
        else if(dadu > 1 && dadu <=3){
            kata("damage kamu adalah 15 hp musuh " + to_string(hpMusuh - 15) + "hp", 200);
        }
        else if(dadu > 3 && dadu <=5 ){
            kata("damage kamu adalah 20 hp musuh" + to_string(hpMusuh - 20) + "hp", 200);
        }
        else if(dadu == 6){
            kata("damage kamu adalah 25 hp musuh" + to_string(hpMusuh - 25) + "hp", 200);
        }
        }
    else if(pilihanUser == 1 && musuh[musuhRandom] == "orc"){
        kata("kamu menghadapi musuh yaitu " + musuh[musuhRandom] + " dengan pisau", 200);
        kata("kamuharus melempar dadu 1-6 untuk menentukan damage yg kamu berikan", 200);
        int dadu = rand() % 6+1;
        int hpMusuh = 35;
        kata("kamu melempar dadu dan mendapatkan angka " + to_string(dadu), 200);
        if(dadu == 1){
            kata("damage kamu adalah 10 " + to_string(hpMusuh - 10) + "hp", 200);
            kata("damage kamu kurang lempar lagi dadu)", 200);
            int tambahanDadu = rand() % 6+1;
            if(tambahanDadu == 1){
                kata("damage tambahan kamu adalah 5 hp musuh " + to_string(hpMusuh - 5) + "hp", 200);
            }
            else if(tambahanDadu  > 1 && dadu >=3){
                kata("damage tambahan kamu adalah 10 hp musuh " + to_string(hpMusuh - 10) + "hp", 200);
            }
            else if(tambahanDadu > 3 && dadu <=5 ){
                kata("damage tambahan kamu adalah 15 hp musuh " + to_string(hpMusuh - 15) + "hp", 200);
            }
            else if(tambahanDadu == 6){
                kata("damage tambahan kamu adalah 20 hp musuh " + to_string(hpMusuh - 20) + "hp", 200);
            }
        }
        else if(dadu > 1 && dadu <=3){
            kata("damage kamu adalah 15 hp musuh " + to_string(hpMusuh - 15) + "hp", 200);
            kata("damage kamu kurang lempar lagi dadu)", 200);
            int tambahanDadu = rand() % 6+1;
            if(tambahanDadu == 1){
                kata("damage tambahan kamu adalah 5 hp musuh " + to_string(hpMusuh - 5) + "hp", 200);
            }
            else if(tambahanDadu  > 1 && dadu >=3){
                kata("damage tambahan kamu adalah 10 hp musuh " + to_string(hpMusuh - 10) + "hp", 200);
            }
            else if(tambahanDadu > 3 && dadu <=5 ){
                kata("damage tambahan kamu adalah 15 hp musuh " + to_string(hpMusuh - 15) + "hp", 200);
            }
            else if(tambahanDadu == 6){
                kata("damage tambahan kamu adalah 20 hp musuh " + to_string(hpMusuh - 20) + "hp", 200);
            }
        }
        else if(dadu > 3 && dadu <=5 ){
            kata("damage kamu adalah 20 hp musuh " + to_string(hpMusuh - 20) + "hp", 200);
        }
        else if(dadu == 6){
            kata("damage kamu adalah 35 hp musuh " + to_string(hpMusuh - 35) + "hp", 200);
            if (hpMusuh == 0){
               kata("selamat kamu menang!", 200);
            }
        }

    }
    else if(pilihanUser == 2 && musuh[musuhRandom] == "great goblin"){
        kata("kamu menghadapi great goblin dengan pedang", 200);
        kata("kamuharus melempar dadu 1-6 untuk menentukan damage yg kamu berikan", 200);
        int dadu = rand() % 6+1;
        int hpMusuh = 50;
        loading();
        if (dadu == 1){
            kata("damage kamu adalah 10 " + to_string(hpMusuh - 10) + "hp", 200);
            kata("lempar lagi dadunya untuk menentukan damage tambahan", 200);
            int daduTambahan = rand() % 6+1;
            if(daduTambahan == 1){
                kata("damage tambahan kamu adalah 5 hp musuh " + to_string(hpMusuh - 5) + "hp", 200);
            }
            else if(daduTambahan > 1 && daduTambahan <=3){
                kata("damage tambahan kamu adalah 10 hp musuh " + to_string(hpMusuh - 10) + "hp", 200);
            }
            else if(daduTambahan > 3 && daduTambahan <=5 ){
                kata("damage tambahan kamu adalah 15 hp musuh " + to_string(hpMusuh - 15) + "hp", 200);
            }
            else if(daduTambahan == 6){
                kata("damage tambahan kamu adalah 20 hp musuh " + to_string(hpMusuh - 20) + "hp", 200);
            }
        }
        else if(dadu > 1 && dadu <=3){
            kata("damage kamu adalah 15 hp musuh " + to_string(hpMusuh - 15) + "hp", 200);
            kata("lempar lagi dadunya untuk menentukan damage tambahan", 200);
            int daduTambahan = rand() % 6+1;
            if(daduTambahan == 1){
                kata("damage tambahan kamu adalah 5 hp musuh " + to_string(hpMusuh - 5) + "hp", 200);
            }
            else if(daduTambahan > 1 && daduTambahan <=3){
                kata("damage tambahan kamu adalah 10 hp musuh " + to_string(hpMusuh - 10) + "hp", 200);
            }
            else if(daduTambahan > 3 && daduTambahan <=5 ){
                kata("damage tambahan kamu adalah 15 hp musuh " + to_string(hpMusuh - 15) + "hp", 200);
            }
            else if(daduTambahan == 6){
                kata("damage tambahan kamu adalah 20 hp musuh " + to_string(hpMusuh - 20) + "hp", 200);
            }
        }
        else if(dadu > 3 && dadu <=5 ){
            kata("damage kamu adalah 20 hp musuh" + to_string(hpMusuh - 20) + "hp", 200);
            kata("lempar lagi dadunya untuk menentukan damage tambahan ", 200);
            int daduTambahan = rand() % 6+1;
            if(daduTambahan == 1){
                kata("damage tambahan kamu adalah 5 hp musuh " + to_string(hpMusuh - 5) + "hp", 200);
            }
            else if(daduTambahan > 1 && daduTambahan <=3){
                kata("damage tambahan kamu adalah 10 hp musuh " + to_string(hpMusuh - 10) + "hp", 200);
            }
            else if(daduTambahan > 3 && daduTambahan <=5 ){
                kata("damage tambahan kamu adalah 15 hp musuh " + to_string(hpMusuh - 15) + "hp", 200);
            }
            else if(daduTambahan == 6){
                kata("damage tambahan kamu adalah 20 hp musuh " + to_string(hpMusuh - 20) + "hp", 200);
            }
        }
        else if(dadu == 6){
            kata("damage kamu adalah 25 hp musuh " + to_string(hpMusuh - 25) + "hp", 200);
            kata("lempar lagi dadunya untuk menentukan damage tambahan ", 200);
            int daduTambahan = rand() % 6+1;
            if(daduTambahan == 1){
                kata("damage tambahan kamu adalah 5 hp musuh " + to_string(hpMusuh - 5) + "hp", 200);
            }
            else if(daduTambahan > 1 && daduTambahan <=3){
                kata("damage tambahan kamu adalah 10 hp musuh " + to_string(hpMusuh - 10) + "hp", 200);
            }
            else if(daduTambahan > 3 && daduTambahan <=5 ){
                kata("damage tambahan kamu adalah 15 hp musuh " + to_string(hpMusuh - 15) + "hp", 200);
            }
            else if(daduTambahan == 6){
                kata("damage tambahan kamu adalah 20 hp musuh " + to_string(hpMusuh - 20) + "hp", 200);
            }
        }
    }
    return 0;
    }
    
