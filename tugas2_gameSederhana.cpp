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
        return "tidak ada bodoh";
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
    Ketik("halo pemain selamat datang di penghancuran hahah,", 10);
    
    Ketik("kamu berada di sebuah chamber gelap huuuuu", 15);
    
    ketik("nama kamu siapa wahai pemuda ", 10);
    getline(cin, pemain1.nama);
    Ketik("ok jadi nama kamu adalah " + pemain1.nama + " hhahah nama yang lucu", 10);
    Ketik("sekarang " + pemain1.nama + " kamu harus memilih senjata agar bertahan hidup", 10);
    cout<<"di depan kamu ada 3 kotak silahkan pilih"<<endl;
    cout<<" silahkan pilih :";
    cin>>pemain1.senjata;
    string senjataPemain=cekSenjata(pemain1.senjata);
    pemain1.musuh =rand () % 6;
    if(senjataPemain == "pisau"  && pemain1.musuh <= 1){
       cout<<"kamu menang ya""\n";
    }else if(senjataPemain == "pisau"  && pemain1.musuh >= 2){
        cout<<"kamu mati \n";
        return 0;
    }
    else if(senjataPemain == "pistol" && pemain1.musuh <= 4){
        cout<<"kamu menangg  selamat""\n";
    }
    else if(senjataPemain == "Desert Eagel" && pemain1.musuh <= 6){
        cout<<"kamu menang"<<endl;
    }else{
        cout<< "kamu kalah "<<endl;
    }
    return 0;

}


