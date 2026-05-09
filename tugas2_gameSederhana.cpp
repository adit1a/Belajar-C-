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
    int serang;
};
struct karakter{
    string nama;
    int senjata;
    int musuh;
    int attack;
    int hp;
    int level;
    int exp;

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

void kenaSerang(karakter &k, int damage){
    k.hp -= damage;
    cout<<"kamu terkena serang sebesar "<< damage << endl;
    if(k.hp <= 0){
        cout<<"kamu meninggal"<<endl;
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
    karakter pemain1;
    pemain1.hp=100;
    pemain1.level=1;
    pemain1.exp=1;
    karakter npc1;
    karakter npc2;
    npc1.nama = "Gorgon";
    Ketik( npc1.nama + " :halo pemain selamat datang di penghancuran hahah,", 10);
    
    Ketik( npc1.nama +" :kamu berada di sebuah chamber gelap huuuuu", 15);
    
    ketik(npc1.nama +" :nama kamu siapa wahai pemuda ", 10);
    getline(cin, pemain1.nama);
    Ketik( npc1.nama +" :ok jadi nama kamu adalah " + pemain1.nama + " hhahah nama yang lucu", 10);
    Ketik(npc1.nama + " :sekarang " + pemain1.nama + " kamu harus memilih senjata agar bertahan hidup", 10);
    cout<<"silahkan pilih :";
    int pilihan;
    do{
        cout<<npc1.nama +" :di depan kamu ada 3 kotak silahkan pilih"<<endl;
        ketik(npc1.nama+" silahkan pilih "+ pemain1.nama +" percayalah hatimu", 20);
        cin>>pilihan;
        if( pilihan < 1 || pilihan > 3){
        Ketik("pilihan kamu tidak ada bodoh dan mati", 10);
    }
    } while (pilihan  < 1  || pilihan > 3);
   
    
    Ketik("Kamu membuka kotak nomor " + to_string(pilihan) + "...", 50);
    pemain1.senjata=rand() % 3+1;
    string senjataPemain=cekSenjata(pemain1.senjata);
    Ketik("Ternyata isinya adalah: " + senjataPemain + "!", 20);
    pemain1.musuh =rand () % 12;
    if(senjataPemain == "pisau"  && pemain1.musuh <= 4){
       kenaSerang(pemain1, 30);
       cout<<"kamu menang ya""\n";
       Ketik(npc1.nama +" :hahah bagus sekarang maju kedepan ", 20);
       ketik(npc1.nama +" :awas ada percabangan kanan atau kiri : ", 20);
       Ketik("darah kamu saat ini : " + to_string(pemain1.hp), 20);
       int pilihan;
       cin>>pilihan;
       if (pilihan == 1 )
       {
            Ketik("kamu memilih " + to_string(pilihan) + " kamu keren",20);
            Ketik(npc1.nama+ " :kamu lewat jalan ini awas hati hati...", 20);
            if (senjataPemain == "pisau" && pemain1.musuh < 1)
            {
                kenaSerang(pemain1, 10);
                Ketik(npc1.nama+ " :kamu menghadapi musuh serang ", 20);
                Ketik("darah kamu saat ini " + to_string(pemain1.hp), 20);
                Ketik(npc1.nama + " :kamu harus membunuh musuh" ,20);

            }
       }
       else if(pilihan == 2){
        kenaSerang(pemain1, 100);
        Ketik("kamu memilih jalan kiri ", 20);
        
       }
        if (senjataPemain == "pisau" && pemain1.musuh > 5) {
            
            cout<<"kamu mati "<< pemain1.hp <<"\n";
        }
    }
    else if(senjataPemain == "pistol" && pemain1.musuh <= 6){
       kenaSerang(pemain1, 30);
       cout<<"kamu menangg""\n";
       Ketik(npc1.nama +" :hahah bagus sekarang maju kedepan ", 20);
       Ketik("darah kamu saat ini : " + to_string(pemain1.hp), 20);
       ketik(npc1.nama +" :awas ada percabangan kanan atau kiri", 20);
       int pilihan;
       cin>>pilihan;

       if (pilihan == 1 )
       {
            kenaSerang(pemain1, 5);
            Ketik("kamu memilih " + to_string(pilihan) + " kamu keren",20);
            Ketik(npc1.nama+ " :kamu lewat jalan ini awas hati hati...", 20);
            if (senjataPemain == "pistol" && pemain1.musuh <= 2);
            ketik("darah kamu saat ini : " + to_string(pemain1.hp), 20);
       }
       else if(pilihan == 2){
        kenaSerang(pemain1, 5);
        Ketik("kamu memilih " + to_string(pilihan) + " kamu keren",20);
        Ketik(npc1.nama+ " :kamu lewat jalan ini awas hati hati...", 20);
        Ketik("darah kamu saat ini : " + to_string(pemain1.hp), 20);
            if (senjataPemain == "pistol" && pemain1.musuh >= 3){
                kenaSerang(pemain1, 100);
                Ketik(npc1.nama + " :kamu memilih ini dan mati", 20);
            }
       }

    }
    else if(senjataPemain == "pistol" && pemain1.musuh > 7){
        cout<<"kamu mati \n";
        return 0;
    }
    else if(senjataPemain == "Desert Eagle" && pemain1.musuh <= 7){
        kenaSerang(pemain1, 30);
        cout<<"kamu menang"<<endl;
       Ketik(npc1.nama +" :hahah bagus sekarang maju kedepan ", 20);
       Ketik("darah kamu saat ini : " + to_string(pemain1.hp), 20);
       ketik(npc1.nama +" :awas ada percabangan kanan atau kiri ", 20);
       int pilihan;
       cin>>pilihan;
       if (pilihan == 1 )
       {
            kenaSerang(pemain1, 30);
            Ketik("kamu memilih " + to_string(pilihan) + " kamu keren",20);
            ketik("darah kamu saat ini : " + pemain1.hp, 20);
            Ketik(npc1.nama+ " :kamu lewat jalan ini awas hati hati...", 20);
            if (senjataPemain == "Desert Eagle" && pemain1.musuh < 6){
                kenaSerang(pemain1, 5);
                Ketik(npc1.nama +" :kamu membantai ya di jalan ini", 20);
                Ketik("darah kamu saat ini : " + to_string(pemain1.hp), 20);
            }else{
                Ketik(npc1.nama +" kamu sangat pandai memilih", 20);
            }

       }
       else{
        Ketik("kamu memilih jalan salah", 20);
       }
    }
    else if(senjataPemain == "Desert Eagle" && pemain1.musuh > 9){
        cout<<"kamu mati \n";
    }else{
        cout<< "kamu kalah "<<endl;
    }
    Ketik("selamat telah menamatkan game ini " + pemain1.nama, 20);
    return 0;

}


