#include <iostream>
using namespace std;
int main(){
    double total =0;
    int jumlahBarang;
    cout<<"===kasir pro dengan struk==="<<"\n";
    cout<<"jumlah barang yang kamu beli: ";
    cin>>jumlahBarang;

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