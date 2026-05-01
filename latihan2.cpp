#include <iostream>

using namespace std;

int main(){
    int jumlahBarang;
    double total, harga;
    cout<<"Kasir Mini"<<"\n";
    cout<<"=============================="<<endl;
    cout<<"Masukkan jumlah beli barang kamu : ";
    cin>>jumlahBarang;
    for(int i=1; i<=jumlahBarang; i++){
        cout<<"Masukkan harga barang "<<i<<": ";
        cin>>harga;
        total = total + harga;
    }
    if (total > 100000){
        cout<<"Total belanja kamu : "<<total<<endl;
        cout<<"Selamat kamu mendapatkan diskon 10%!"<<endl;
        cout<<"Total yang harus dibayar : "<<(total - (total * 0.1))<<endl;
    }else{
        cout<<"Total belanja kamu : "<<total<<endl;
        cout<<"Maaf kamu tidak mendapatkan diskon"<<endl;
        cout<<"Total yang harus dibayar : "<<total<<endl;
    }

    return 0;
}
