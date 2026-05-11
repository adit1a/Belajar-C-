#include <iostream>
#include <string>

using namespace std;

void cekTotal(int &total,int harga, int jumlah){ 
        total = harga * jumlah;    
}

void barang(int kode, string &nama, int &harga)
    {
        switch (kode)
        {
        case 1:
            nama ="beras";
            harga =12000;
            break;
        case 2:
            nama ="telur";
            harga =2000;
            break;
        case 3:
            nama ="gula";
            harga =7000;
            break;
        default:
            nama="tidak ada";
            harga=0;
            break;
        }
    }

int main()
{

    int pilihan, jumlah, total =0;
    int harga =0;
    string nama;

    cout<<"selamat datang pemebeli"<<endl;
    cout<<"silahkan berbelanja"<<endl;
    cout<<"=========================""\n";
    cout<<"kita punya pilihan""\n";
    cout<<"1. beras"<<endl;
    cout<<"2. gula"<<endl;
    cout<<"3. telur"<<endl;
    cout<<"silahkan pilih :";
    cin>>pilihan;
    barang(pilihan, nama, harga);
    if(nama == "tidak ada"){
        cout<<"tidak ada"<<endl;
        return 0;
    }else{
        cout<<"kamu memilih "<<nama<<endl;
        cout<<"jumlah nya berapa :";
        cin>>jumlah;
        cekTotal(total, harga, jumlah);

        cout<<"============================""\n";
        cout<<"total bayar untuk "<<jumlah << " " <<nama<<" adalah Rp: "<<total<<endl;
        

    }

    
    
    return 0;
    
}