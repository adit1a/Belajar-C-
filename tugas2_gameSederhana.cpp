#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>


using namespace std;

struct game
{
    string nama;
    int senjata;
    int musuh;
    int jalan;
};
struct karakter{
    string nama;

};

string cekSenjata(int kode)
{
    switch (kode)
    {
    case 1:
        return "pisau";
    case 2:
        return "pistol";
    case 3:
        return "Desert Eagle";
    default:
        return "salah";
    }
}

void Ketik(string teks, int jeda){
    for (int i=0; i<teks.length(); i++){
        cout<<teks[i]<<flush;
        Sleep(jeda);
    }
    cout<<endl;
}
void ketik(string teks, int jeda){
    for (int i=0; i<teks.length(); i++){
        cout<<teks[i]<<flush;
        Sleep(jeda);
    }
    
}
int main(){
    srand(time(0));
    game pemain1;
    karakter npc1;
    npc1.nama = "Gorgon";
    Ketik( npc1.nama + " :halo pemain selamat datang di penghancuran hahah,", 10);
    
    Ketik( npc1.nama +" :kamu berada di sebuah chamber gelap huuuuu", 15);
    
    ketik(npc1.nama +" :nama kamu siapa wahai pemuda ", 10);
    getline(cin, pemain1.nama);
    Ketik( npc1.nama +" :ok jadi nama kamu adalah " + pemain1.nama + " hhahah nama yang lucu", 10);
    Ketik(npc1.nama + " :sekarang " + pemain1.nama + " kamu harus memilih senjata agar bertahan hidup", 10);
    cout<<npc1.nama +" :di depan kamu ada 5 kotak silahkan pilih"<<endl;
    cout<<"silahkan pilih :";
    int pilihan;
    cin>>pilihan;
    if( pilihan < 1 || pilihan > 3){
        Ketik("pilihan kamu tidak ada bodoh dan mati", 10);
        return 0;
    }
    Ketik("Kamu membuka kotak nomor " + to_string(pilihan) + "...", 50);
    pemain1.senjata=rand() % 3+1;
    string senjataPemain=cekSenjata(pemain1.senjata);
    Ketik("Ternyata isinya adalah: " + senjataPemain + "!", 20);
    pemain1.musuh =rand () % 12;
    if(senjataPemain == "salah"){
        Ketik("kamu salah pilih dan dibunuh game over bunng", 150);
        return 0;
    }
    else if(senjataPemain == "pisau"  && pemain1.musuh <= 4){
       cout<<"kamu menang ya""\n";
       Ketik(npc1.nama +" :hahah bagus sekarang maju kedepan ", 20);
       ketik(npc1.nama +" :awas ada percabangan kanan atau kiri : ", 20);
       int pilihan;
       cin>>pilihan;

       if (pilihan == 1 )
       {
            ketik("kamu memilih " + to_string(pilihan) + "kamu keren",20);

       }
       else{
        Ketik("kamu memilih jalan salah", 20);
       }
       
    }else if(senjataPemain == "pisau"  && pemain1.musuh > 5){
        cout<<"kamu mati \n";
        return 0;
    }
    else if(senjataPemain == "pistol" && pemain1.musuh <= 6){
        cout<<"kamu menangg""\n";
       Ketik(npc1.nama +" :hahah bagus sekarang maju kedepan ", 20);
       ketik(npc1.nama +" :awas ada percabangan kanan atau kiri", 20);
       int pilihan;
       cin>>pilihan;

       if (pilihan == 1 )
       {
            ketik("kamu memilih " + to_string(pilihan) + " kamu keren",20);

       }
       else{
        Ketik("kamu memilih jalan salah", 20);
       }

    }
    else if(senjataPemain == "pistol" && pemain1.musuh > 7){
        cout<<"kamu mati \n";
        return 0;
    }
    else if(senjataPemain == "Desert Eagle" && pemain1.musuh <= 7){
        cout<<"kamu menang"<<endl;
       Ketik(npc1.nama +" :hahah bagus sekarang maju kedepan ", 20);
       ketik(npc1.nama +" :awas ada percabangan kanan atau kiri ", 20);
       int pilihan;
       cin>>pilihan;

       if (pilihan == 1 )
       {
            ketik("kamu memilih " + to_string(pilihan) + " kamu keren",20);

       }
       else{
        Ketik("kamu memilih jalan salah", 20);
       }
    }
    else if(senjataPemain == "Desert Eagle" && pemain1.musuh > 9){
        cout<<"kamu mati \n";
        return 0;
    }else{
        cout<< "kamu kalah "<<endl;
    }
    return 0;

}


