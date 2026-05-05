#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct produk{
    string namaBarang;
    string satuan;
    int stok;
    int harga;

};

int main ()
{
    const int jenisBarang = 3;
    produk barang[jenisBarang];
    cout<<"=======Latihan=======""\n";
    
    for(int i=0; i<jenisBarang; i++){
        cout<<"\nInput barang : "<<" - "<<i+1<<endl;
        cout<<"Nama barang : ";
        
        getline(cin, barang[i].namaBarang);
        cout<<"satuan barang : ";
        getline(cin, barang[i].satuan);
        cout<<"stok : ";
        cin>>barang[i].stok;
        cout<<"harga : ";
        cin>>barang[i].harga;
        cin.ignore();

        
    }
    cout<<"===Laporan===""\n";
    cout<<left<<setw(5)<<"no"
    <<setw(15)<<"Nama barang"
    <<setw(10)<<"satuan"
    <<setw(10)<<"stok"
    <<setw(10)<<"harga"
    <<setw(5)<<"total nilai"<<endl;

    
    

    long modal = 0;
    for(int k=0; k<jenisBarang; k++){
        long totalNilaiInventaris = barang[k].stok * barang[k].harga;
        modal+=totalNilaiInventaris;
        cout<<left<<setw(5)<<k+1
        <<setw(15)<<barang[k].namaBarang
        <<setw(10)<<barang[k].satuan
        <<setw(10)<<barang[k].stok
        <<setw(10)<<barang[k].harga
        <<setw(5)<<totalNilaiInventaris
        <<setw(5)<<modal<<endl;

        if(barang[k].stok<5){
        cout<<"restok segera"<<endl;   
    }
    
    
}
    cout<<"--------------------------""\n";
    cout<<"total keseluruhan modal : Rp "<<modal<<endl;
     
    return 0;
}