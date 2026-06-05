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
void lempar(){
    kata("sedang melempar dadu", 100);
        for(int i=0; i<5; i++){
            cout<<".";
            Sleep(500);
        }
        cout<<endl;
}
void senjata(int pilihan, int kode){
    switch(pilihan){
        case 1:
                cout<<" pisau""\n";
                break;
        case 2:
                cout<<" pedang""\n";
                break;
        case 3:
                cout<<" kapak""\n";
                break;
        case 4:
                cout<<" tombak""\n";
                break;
        default:               
         cout<<"tangan""\n";
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
    cout<<"===========Ryuhlon=========="<<endl;
    garis();
    cout<<"Masukkan nama player : ";
    getline(cin, p1.nama);
    loading();
    kata("nama kamu adalah ... " + p1.nama + " karakter", 200);
    kata("wahai pemuda " +p1.nama+"  tolong kami, selamatkan kami", 100);
    Kata("silahkan pilih senjata kamu (1-4) " + p1.nama, 100);
    cin>>pilihanUser;
    senjata(pilihanUser, 0);
    int musuhRandom = rand() % 4;
    kata("tiba-tiba muncul " + musuh[musuhRandom], 100);
                         // musuh 1 goblin
    if(pilihanUser == 1 && musuh[musuhRandom] == "goblin"){
        kata("kamu menghadapi goblin dengan", 100);
        senjata(pilihanUser, 0);
        kata("kamu harus melempar dadu 1-6 untuk menentukan damage yg kamu berikan", 100);
        int dadu = rand() % 6+1;
        int hpMusuh = 25;
        lempar();
        if (dadu == 1){
            kata("damage kamu adalah 10 " + to_string(hpMusuh - 10) + "hp", 200);
            kata("lempar lagi dadunya untuk menentukan damage tambahan", 100);
            lempar();
            cout<<"kamu mendapatkan dadu nomor " + to_string(dadu)<<endl;
            int daduTambahan = rand() % 6+1;
            if(daduTambahan == 1){
                kata("damage tambahan kamu adalah 5 hp musuh " + to_string(hpMusuh - 5) + "hp", 100);
            }
            else if(daduTambahan > 1 && daduTambahan <=3){
                kata("damage tambahan kamu adalah 10 hp musuh " + to_string(hpMusuh - 10) + "hp", 100);
            }
            else if(daduTambahan > 3 && daduTambahan <=5 ){
                kata("damage tambahan kamu adalah 15 hp musuh " + to_string(hpMusuh - 15) + "hp", 100);
            }
            else if(daduTambahan == 6){
                kata("damage tambahan kamu adalah 20 hp musuh " + to_string(hpMusuh - 20) + " hp", 100);
            }
        }
        else if(dadu > 1 && dadu <=3){
            int tambahanDadu =0;
            cout<<"kamu mendapatkan dadu nomor " + to_string(dadu)<<endl;
            kata("damage kamu adalah 15 hp musuh " + to_string(hpMusuh - 15) + "hp", 100);
            kata("damage kamu kurang lempar lagi dadu)", 100);
            lempar();
            tambahanDadu = rand() % 6+1;
            do{
                
                kata("sliahkan lempar dadu lagi", 100);
                lempar();
                if(tambahanDadu <= 3){
                    kata("kamu mendapatkan dadu nomor " + to_string(tambahanDadu), 100);
                    kata("damage kamu adalah 5 hp mush " + to_string(hpMusuh - 5) + "hp", 100);
                    kata("kamu membunuh musuh pertama kamu kamu hebat " + p1.nama, 100);
                }
                else if(tambahanDadu <= 5 && tambahanDadu == 6){
                    kata("kamu mendapatkan dadu nomor " + to_string(tambahanDadu), 100);
                    kata("damage yang kamu berikan adalah 10 hp", 100);
                    kata("kamu telah membunuh musuh pertama kamu kamu hebat " + p1.nama, 100);
                }
            }while(tambahanDadu != 4);
            
        }
        else if(dadu > 3 && dadu <=5 ){
            int tambahanDadu = rand() % 6+1;
            lempar();
            cout<<"kamu mendapatkan dadu nomor " + to_string(dadu)<<endl;
            kata("damage kamu adalah 20 hp musuh " + to_string(hpMusuh - 20) + "hp", 100);
            kata("damage kamu kurang lempar lagi dadunya ", 100);
            lempar();
            do{
                int tambahanDadu = rand() % 6+1;
                kata("kamu tergelincir saat melempar dadu..... lempar lagi ",100);
                
                if (tambahanDadu <=4 &&  tambahanDadu >=5){
                    kata("damage yang kamu berikan adalah 5 hp musuh " +to_string(hpMusuh -5) + "hp", 100);
                    kata("kamu telah membunuh musuh pertama kamu kamu hebat " + p1.nama, 100);
                }
            }while(tambahanDadu != 3 && tambahanDadu != 1);
        }
        else if(dadu == 6){
            cout<<"kamu mendapatkan dadu nomor " + to_string(dadu)<<endl;
            kata("damage kamu adalah 25 hp musuh  " + to_string(hpMusuh - 25) + "hp", 100);
            kata("kamu telah membunuh musuh pertama kamu kamu hebat " + p1.nama, 100);
             if (hpMusuh == 0){
               kata("selamat kamu menang!", 100);
            }
        }
        }
                         // musuh 2 orc senjata pisau

    else if(pilihanUser == 1 && musuh[musuhRandom] == "orc"){
        kata("kamu menghadapi musuh yaitu " + musuh[musuhRandom] + " dengan", 100);
        senjata(pilihanUser, 0);
        kata("kamu harus melempar dadu 1-6 untuk menentukan damage yg kamu berikan", 100);
        lempar();
        int dadu = rand() % 6+1;
        int hpMusuh = 35;
        kata("kamu melempar dadu dan mendapatkan angka " + to_string(dadu), 200);
        if(dadu == 1){
            cout<<"kamu mendapatkan dadu nomor " + to_string(dadu)<<endl;
            kata("damage kamu adalah 10 " + to_string(hpMusuh - 10) + "hp", 200);
            kata("damage kamu kurang lempar lagi dadu)", 100);
            int tambahanDadu = rand() % 6+1;
            if(tambahanDadu == 1){
                kata("damage tambahan kamu adalah 5 hp musuh " + to_string(hpMusuh - 5) + "hp", 100);
            }
            else if(tambahanDadu  > 1 && dadu >=3){
                kata("damage tambahan kamu adalah 10 hp musuh " + to_string(hpMusuh - 10) + "hp", 100);
            }
            else if(tambahanDadu > 3 && dadu <=5 ){
                kata("damage tambahan kamu adalah 15 hp musuh " + to_string(hpMusuh - 15) + "hp", 100);
            }
            else if(tambahanDadu == 6){
                kata("damage tambahan kamu adalah 20 hp musuh " + to_string(hpMusuh - 20) + "hp", 100);
            }
        }
    
        else if(dadu > 1 && dadu <=3){
            cout<<"kamu mendapatkan dadu nomor " + to_string(dadu)<<endl;
            kata("damage kamu adalah 15 hp musuh " + to_string(hpMusuh - 15) + "hp", 100);
            kata("damage kamu kurang lempar lagi dadu)", 100);
            int tambahanDadu = rand() % 6+1;
            if(tambahanDadu == 1){
                kata("damage tambahan kamu adalah 5 hp musuh " + to_string(hpMusuh - 5) + "hp", 100);
            }
            else if(tambahanDadu  > 1 && dadu >=3){
                kata("damage tambahan kamu adalah 10 hp musuh " + to_string(hpMusuh - 10) + "hp", 100);
            }
            else if(tambahanDadu > 3 && dadu <=5 ){
                kata("damage tambahan kamu adalah 15 hp musuh " + to_string(hpMusuh - 15) + "hp", 100);
            }
            else if(tambahanDadu == 6){
                kata("damage tambahan kamu adalah 20 hp musuh " + to_string(hpMusuh - 20) + "hp", 100);
            }
        }
        else if(dadu > 3 && dadu <=5 ){
            cout<<"kamu mendapatkan dadu nomor " + to_string(dadu)<<endl;
            kata("damage kamu adalah 20 hp musuh " + to_string(hpMusuh - 20) + "hp", 100);
        }
        else if(dadu == 6){
            cout<<"kamu mendapatkan dadu nomor " + to_string(dadu)<<endl;
            kata("damage kamu adalah 35 hp musuh " + to_string(hpMusuh - 35) + "hp", 100);
            if (hpMusuh == 0){
               kata("selamat kamu menang!", 100);
            }
        }
    }

                        // musuh 2 orc senjata pedang
    
    else if(pilihanUser == 2 && musuh[musuhRandom] == "orc"){
        int dadu =0;
        int hpMusuh = 55;
        kata("kamu menghadapi musuh yaitu " + musuh[musuhRandom] + " dengan ", 100);   
        senjata(pilihanUser, 0);
        kata("kamu harus melempar dadu 1-6 untuk menentukan damage yg kamu berikan", 100);
        lempar();
        dadu = rand() % 6+1;
        kata("kamu melempar dadu dan mendapatkan angka " + to_string(dadu), 200);
        if(dadu == 1){
            cout<<"kamu mendapatkan dadu nomor " + to_string(dadu)<<endl;
            hpMusuh -=10;
            kata("damage kamu kurang lempar lagi dadu)", 100);
            do{
                int tambahanDadu = rand() % 6+1;
                if(tambahanDadu == 1){
                kata("damage tambahan kamu adalah 10 hp musuh " + to_string(hpMusuh - 10) + "hp", 100);
            }
            else if(tambahanDadu  > 1 && dadu >=3){
                hpMusuh -=15;
                kata("damage tambahan kamu adalah 15 hp musuh " + to_string(hpMusuh) + "hp", 100);
            }
            else if(tambahanDadu > 4 && dadu <=6 ){
                hpMusuh -=15;
                kata("damage tambahan kamu adalah 15 hp musuh " + to_string(hpMusuh) + "hp", 100);
                kata("kamu telah membunuh musuh " + p1.nama + "kamu hebat", 100);
            }
            }while(hpMusuh > 0);
        }
            
        else if(dadu > 1 && dadu <=3){
            cout<<"kamu mendapatkan dadu nomor " + to_string(dadu)<<endl;
            hpMusuh -=15;
            kata("damage kamu adalah 15 hp musuh " + to_string(hpMusuh) + "hp", 100);
            kata("damage kamu kurang lempar lagi dadu", 100);
            do{
                int tambahanDadu = rand() % 6+1;
                tambahanDadu = rand() % 6+1;
                if(tambahanDadu == 1){
                hpMusuh -=5;
                kata("damage tambahan kamu adalah 5 hp musuh " + to_string(hpMusuh ) + "hp", 100);
            }
            else if(tambahanDadu  > 1 && dadu >=3){
                hpMusuh -=10;
                kata("damage tambahan kamu adalah 10 hp musuh " + to_string(hpMusuh - 10) + "hp", 100);
            }
            else if(tambahanDadu > 3 && dadu <=5 ){
                kata("damage tambahan kamu adalah 15 hp musuh " + to_string(hpMusuh - 15) + "hp", 100);
            }
            else if(tambahanDadu == 6){
                kata("damage tambahan kamu adalah 20 hp musuh " + to_string(hpMusuh - 20) + "hp", 100);
                kata("kamu telah membunuh musuh " + p1.nama + "kamu hebat", 100);
            }
            if(hpMusuh < 0) hpMusuh = 0;
            }while(hpMusuh > 0);
            
        }
        else if(dadu > 3 && dadu <=5 ){
            cout<<"kamu mendapatkan dadu nomor " + to_string(dadu)<<endl;
            hpMusuh -=20;
            kata("damage kamu adalah 20 hp musuh " + to_string(hpMusuh) + "hp", 100);
            kata("damage kamu kurang lempar lagi dadu)", 100);
            do{
                int tambahanDadu = rand() %6+1;
                if(tambahanDadu >= 1 && tambahanDadu <=5){
                    hpMusuh -=35;
                    if(hpMusuh < 0) hpMusuh = 0;    
                    kata("kamu berhasil membunuh musuh " + p1.nama + "kamu hebat", 100);
                }
            }while(hpMusuh > 0);
        }
        else if(dadu == 6){
            cout<<"kamu mendapatkan dadu nomor " + to_string(dadu)<<endl;
            hpMusuh -=55;
            kata("damage kamu adalah 55 hp musuh " + to_string(hpMusuh) + "hp", 100);
            if (hpMusuh == 0){
               kata("selamat kamu menang!", 100);
            }
        }
    
    }
    // ========== musuh  3 great goblin senjata pedang =============

    else if(pilihanUser == 1 && musuh[musuhRandom] == "great goblin"){
        Kata("kamu menghadapi great goblin dengan", 100);
        senjata(pilihanUser, 0);
        kata("kamu harus melempar dadu 1-6 untuk menentukan damage yg kamu berikan", 100);
        int dadu = rand() % 6+1;
        int hpMusuh = 50;
        lempar();
        if (dadu == 1){
            cout<<"kamu mendapatkan dadu nomor " + to_string(dadu)<<endl;
            kata("damage kamu adalah 10 " + to_string(hpMusuh - 10) + "hp", 100);
            kata("lempar lagi dadunya untuk menentukan damage tambahan", 100);
            int daduTambahan = rand() % 6+1;
            if(daduTambahan == 1){
                kata("damage tambahan kamu adalah 5 hp musuh " + to_string(hpMusuh - 5) + "hp", 100);
            }
            else if(daduTambahan > 1 && daduTambahan <=3){
                kata("damage tambahan kamu adalah 10 hp musuh " + to_string(hpMusuh - 10) + "hp", 100);
            }
            else if(daduTambahan > 3 && daduTambahan <=5 ){
                kata("damage tambahan kamu adalah 15 hp musuh " + to_string(hpMusuh - 15) + "hp", 100);
            }
            else if(daduTambahan == 6){
                kata("damage tambahan kamu adalah 20 hp musuh " + to_string(hpMusuh - 20) + "hp", 100);
            }
        }
    
        else if(dadu > 1 && dadu <=3){
            cout<<"kamu mendapatkan dadu nomor " + to_string(dadu)<<endl;
            kata("damage kamu adalah 15 hp musuh " + to_string(hpMusuh - 15) + "hp", 100);
            kata("lempar lagi dadunya untuk menentukan damage tambahan", 100);
            int daduTambahan = rand() % 6+1;
            if(daduTambahan == 1){
                kata("damage tambahan kamu adalah 5 hp musuh " + to_string(hpMusuh - 5) + "hp", 100);
            }
            else if(daduTambahan > 1 && daduTambahan <=3){
                kata("damage tambahan kamu adalah 10 hp musuh " + to_string(hpMusuh - 10) + "hp", 100);
            }
            else if(daduTambahan > 3 && daduTambahan <=5 ){
                kata("damage tambahan kamu adalah 15 hp musuh " + to_string(hpMusuh - 15) + "hp", 100);
            }
            else if(daduTambahan == 6){
                kata("damage tambahan kamu adalah 20 hp musuh " + to_string(hpMusuh - 20) + "hp", 100);
            }
        }
        else if(dadu > 3 && dadu <=5 ){
            cout<<"kamu mendapatkan dadu nomor " + to_string(dadu)<<endl;
            kata("damage kamu adalah 20 hp musuh" + to_string(hpMusuh - 20) + "hp", 100);
            kata("lempar lagi dadunya untuk menentukan damage tambahan ", 100);
            int daduTambahan = rand() % 6+1;
            if(daduTambahan == 1){
                kata("damage tambahan kamu adalah 5 hp musuh " + to_string(hpMusuh - 5) + "hp", 100);
            }
            else if(daduTambahan > 1 && daduTambahan <=3){
                kata("damage tambahan kamu adalah 10 hp musuh " + to_string(hpMusuh - 10) + "hp", 100);
            }
            else if(daduTambahan > 3 && daduTambahan <=5 ){
                kata("damage tambahan kamu adalah 15 hp musuh " + to_string(hpMusuh - 15) + "hp", 100);
            }
            else if(daduTambahan == 6){
                kata("damage tambahan kamu adalah 20 hp musuh " + to_string(hpMusuh - 20) + "hp", 100);
            }
        }
        else if(dadu == 6){
            cout<<"kamu mendapatkan dadu nomor " + to_string(dadu)<<endl;
            kata("damage kamu adalah 25 hp musuh " + to_string(hpMusuh - 25) + "hp", 100);
            kata("lempar lagi dadunya untuk menentukan damage tambahan ", 100);
            int daduTambahan = rand() % 6+1;
            if(daduTambahan == 1){
                kata("damage tambahan kamu adalah 5 hp musuh " + to_string(hpMusuh - 5) + "hp", 100);
            }
            else if(daduTambahan > 1 && daduTambahan <=3){
                kata("damage tambahan kamu adalah 10 hp musuh " + to_string(hpMusuh - 10) + "hp", 100);
            }
            else if(daduTambahan > 3 && daduTambahan <=5 ){
                kata("damage tambahan kamu adalah 15 hp musuh " + to_string(hpMusuh - 15) + "hp", 100);
            }
            else if(daduTambahan == 6){
                kata("damage tambahan kamu adalah 20 hp musuh " + to_string(hpMusuh - 20) + "hp", 100);
            }
        }
    }

    // musuh great goblin senjata pedang

     else if(pilihanUser == 2 && musuh[musuhRandom] == "great goblin"){
        kata("kamu menghadapi great goblin dengan pedang", 100);
        kata("kamu harus melempar dadu 1-6 untuk menentukan damage yg kamu berikan", 100);
        int dadu = rand() % 6+1;
        int hpMusuh = 50;
        lempar();
        if (dadu == 1){
            cout<<"kamu mendapatkan dadu nomor " + to_string(dadu)<<endl;
            hpMusuh-=10;
            kata("damage kamu adalah 10 " + to_string(hpMusuh) + "hp", 100);
            kata("lempar lagi dadunya untuk menentukan damage tambahan", 100);
            int daduTambahan = rand() % 6+1;
            do{
            if(daduTambahan == 1){
            hpMusuh-=5;
            kata("damage tambahan kamu adalah 5 hp musuh " + to_string(hpMusuh) + "hp", 100);
            }
            else if(daduTambahan > 1 && daduTambahan <=3){
                hpMusuh-=10;
                kata("damage tambahan kamu adalah 10 hp musuh " + to_string(hpMusuh) + "hp", 100);
            }
            else if(daduTambahan > 3 && daduTambahan <=5 ){
                hpMusuh-=15;
                kata("damage tambahan kamu adalah 15 hp musuh " + to_string(hpMusuh) + "hp", 100);
            }
            
            else if(daduTambahan == 6){
                hpMusuh -=20;
                kata("damage tambahan kamu adalah 20 hp musuh " + to_string(hpMusuh) + "hp", 100);
                kata("kamu telah membunuh musuh " + p1.nama + "kamu hebat", 100);
            if (hpMusuh < 0) hpMusuh = 0;
            }}while(hpMusuh > 0);
            
        }

        else if(dadu > 1 && dadu <=3){
            cout<<"kamu mendapatkan dadu nomor " + to_string(dadu)<<endl;
            kata("damage kamu adalah 15 hp musuh " + to_string(hpMusuh - 15) + "hp", 100);
            kata("lempar lagi dadunya untuk menentukan damage tambahan", 100);
            int daduTambahan = rand() % 6+1;
            do{
                if(daduTambahan == 1){
                kata("damage tambahan kamu adalah 5 hp musuh " + to_string(hpMusuh - 5) + "hp", 100);
            }
            else if(daduTambahan > 1 && daduTambahan <=3){
                kata("damage tambahan kamu adalah 10 hp musuh " + to_string(hpMusuh - 10) + "hp", 100);
            }
            else if(daduTambahan > 3 && daduTambahan <=5 ){
                kata("damage tambahan kamu adalah 15 hp musuh " + to_string(hpMusuh - 15) + "hp", 100);
            }
            else if(daduTambahan == 6){
                kata("damage tambahan kamu adalah 20 hp musuh " + to_string(hpMusuh - 20) + "hp", 100);
            }
        }while(hpMusuh > 0);
        }
        else if(dadu > 3 && dadu <=5 ){
            cout<<"kamu mendapatkan dadu nomor " + to_string(dadu)<<endl;
            hpMusuh -= 20;
            kata("damage kamu adalah 20 hp musuh" + to_string(hpMusuh) + "hp", 100);
            kata("lempar lagi dadunya untuk menentukan damage tambahan ", 100);
            int daduTambahan = rand() % 6+1;
            do{
            if(daduTambahan == 1){
                hpMusuh -= 5;
                kata("damage tambahan kamu adalah 5 hp musuh " + to_string(hpMusuh) + "hp", 100);
            }
            else if(daduTambahan > 1 && daduTambahan <=3){
                hpMusuh -= 10;
                kata("damage tambahan kamu adalah 10 hp musuh " + to_string(hpMusuh) + "hp", 100);
            }
            else if(daduTambahan > 3 && daduTambahan <=5 ){
                hpMusuh -= 15;
                kata("damage tambahan kamu adalah 15 hp musuh " + to_string(hpMusuh) + "hp", 100);
            }
            else if(daduTambahan == 6){
                hpMusuh -= 20;
                kata("damage tambahan kamu adalah 20 hp musuh " + to_string(hpMusuh) + "hp", 100);
                kata("kamu telah membunuh musuh " + p1.nama + "kamu hebat", 100);
            }
         }while(hpMusuh > 0);
     }
        else if(dadu == 6){
            cout<<"kamu mendapatkan dadu nomor " + to_string(dadu)<<endl;
            hpMusuh -=25;
            kata("damage kamu adalah 25 hp musuh " + to_string(hpMusuh) + "hp", 100);
            kata("lempar lagi dadunya untuk menentukan damage tambahan ", 100);
            int daduTambahan = rand() % 6+1;
            do{
            if(daduTambahan == 1){
                hpMusuh -= 5;
                kata("damage tambahan kamu adalah 5 hp musuh " + to_string(hpMusuh) + "hp", 100);
            }
            else if(daduTambahan > 1 && daduTambahan <=3){
                kata("damage tambahan kamu adalah 10 hp musuh " + to_string(hpMusuh - 10) + "hp", 100);
            }
            else if(daduTambahan > 3 && daduTambahan <=5 ){
                hpMusuh -= 15;
                kata("damage tambahan kamu adalah 15 hp musuh " + to_string(hpMusuh) + "hp", 100);
            }
            else if(daduTambahan == 6){
                hpMusuh -= 20;
                kata("damage tambahan kamu adalah 20 hp musuh " + to_string(hpMusuh) + "hp", 100);
            }
            if(hpMusuh < 0) hpMusuh = 0;
            
        }while(hpMusuh > 0);}
            kata("selamat kamu menang!", 100);
    }

    return 0;
}


    
