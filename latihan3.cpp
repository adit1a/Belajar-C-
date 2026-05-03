#include <iostream>
#include<string>
using namespace std;

void cetakGaris(){
    cout<<"=============================="<<"\n";
}
bool stokBarang(int jumlahBarang){
  int stokGudang = 5;
  if(jumlahBarang <= stokGudang){
    cout<<"stok barang tersedia"<<endl;
    return true;
  }else{
    cout<<"stok barang habis"<<endl;
    return false;
  }
}
int main(){
    double total =0;
    int jumlahBarang;
    cetakGaris();
    cout<<"===kasir pro dengan struk==="<<"\n";
    cetakGaris();
    
    cout<<"jumlah barang yang kamu beli: ";
    cin>>jumlahBarang;
    if(stokBarang(jumlahBarang) == false){
        return 0;
    }

    double daftarHarga[jumlahBarang];
    string daftarNamaBarang[jumlahBarang];

    for(int i=0; i<jumlahBarang; i++){
        cout<<"nama barang ke : "<<i+1<<" : ";
        cin.ignore();
        getline(cin, daftarNamaBarang[i]);
        cout<<"harga barang ke : "<<i+1<<" : ";
        cin>>daftarHarga[i];
        total += daftarHarga[i];
    }
    
    cout<<"\n===struk belanja==="<<endl;
    for(int i=0; i<jumlahBarang; i++){
        cout<<i+1<<". " <<daftarNamaBarang[i]<<"\t: - Rp"<<daftarHarga[i]<<endl;
    }
    cout<<"------------------------------"<<endl;
    cout<<"subtotal : "<<total<<endl;
    
    if(total > 100000){
        double diskon = total * 0.1;
        cout<<"diskon 10% : Rp"<<diskon<<endl;
        cout<<"total yang harus di bayar : Rp"<<total-diskon<<endl;

    }else{
        cout<<"total yang harus di bayar : Rp"<<total<<"\n";
    }
   
    return 0;
}