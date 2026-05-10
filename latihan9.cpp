#include <iostream>
#include <string>

using namespace std;

void cekTotal(int &total,int harga, int jumlah){ 
        total = harga * jumlah;    
}

string barang(int brg)
    {
        switch (brg)
        {
        case 1:
            return "beras";
        case 2:
            return  "gula";
        case 3:
            return "telur";
        default:
            return "barang tidak ada";
        }
    }

int main()
{

    int pilihan, jumlah, total =0;
    int harga =12000;

    cout<<"selamat datang pemebeli"<<endl;
    cout<<"silahkan berbelanja"<<endl;
    cout<<"=========================""\n";
    cout<<"kita punya pilihan""\n";
    cout<<"1. beras"<<endl;
    cout<<"2. gula"<<endl;
    cout<<"3. telur"<<endl;
    cout<<"silahkan pilih :";
    cin>>pilihan;
    string nama=barang(pilihan);
    if(nama == "barang tidak ada"){
        cout<<"tidak ada"<<endl;
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