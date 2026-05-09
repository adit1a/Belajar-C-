#include <iostream>
#include <string>

using namespace std;

struct  Produk{
    string nama;
    int harga;
    int kategori;
};

string cekKategori(int kode){
    switch (kode)
    {
        case 1:
        return "makanan";
        case 2:
        return "minuman";
        case 3:
        return "alat tulis";
        case 4:
        return "alat it";
        default:
        return "Tanpa kategori";
    }
}

int main()
{
    Produk barang1;
    Produk barang2;

    cout<<"input barang disini"<<"\n";
    cout<<"nama barang 1 : ";
    getline(cin, barang1.nama);
    cout<<"nama barang 2 : ";
     getline(cin, barang2.nama);
    cout<<"Harga barang : ";
    cin>>barang1.harga;

    cout<<"\nKode Kategori:\n1. Makanan \n2. Minuman \n3. alat tulis \n4. alat it \n.Pilih(1-4)";
    cin>>barang1.kategori;

    string hasilKategori = cekKategori(barang1.kategori);
    

    cout<<"ringkasan belanja"<<endl;
    cout<<"Nama 1 : "<<barang1.nama<< "| nama 2: "<<barang2.nama<<endl;
    cout<<"Harga : Rp "<<barang1.harga<<endl;
    cout<<"Kategori : "<<hasilKategori<<endl;
    return 0;
}
