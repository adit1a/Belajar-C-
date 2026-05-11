#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct chest{
    string nama;
    int item;
    int maxItem;
};

void chestInv(string &nama, int &item, int &maxItem, int &kode, int &jumlah){
    switch (kode)
    {
    case 1:
    nama="pickaxe";
    item=1;
    maxItem=64;
        break;
    case 2:
    nama="oakPlank";
    item=2;
    maxItem=64;
        break;
    case 3:
    nama="diamond";
    item=3;
    maxItem=64;
        break;
    default:
        cout<<"tidak ada nama item"<<endl;
        break;
    }
    if(maxItem >= jumlah){
        for(int j=jumlah; j<=maxItem; j++){
            cout<<"jumlah ke - "<<j<<endl;
        }
    }else{
        cout<<"max item sudah terpenuhi"<<endl;
    }
}

void cekInventory( int &jumlah, int &item){
    if(jumlah <= item){
        cout<<"inventory kurang""\n";
    }else{
        cout<<"inventory cukup""\n";
    }
}

int main()
{
    chest barang1;
    string nama;
    int kode;
    int jumlah, item=0;
    int selisih=0;
    int maxItem=0;

    cout<<"selamat datang"<<endl;
    cout<<"masukkan jumlah barang= ";
    cin>>jumlah;
    cout<<"masukkan item = ";
    cin>>item;
    selisih=jumlah - item;
    cekInventory(jumlah, item);

    cout<<"jumlah baranag = "<<jumlah<<endl;
    cout<<"item = "<<item<<" dan inventory kurang berapa = "<< selisih <<endl;

    cout<<"selamat datang pengecekan chest"<<endl;
    cout<<"silahkan masukkan barang = ";
    cin>>kode;
    cout<<"silahkan masukkan jumalah barang = ";
    cin>>jumlah;
    chestInv(nama, item, maxItem, kode, jumlah);
    cout<<"nama item = "<<nama<<endl;
    cout<<"jumlah = "<<jumlah<<endl;

     return 0;



    
}