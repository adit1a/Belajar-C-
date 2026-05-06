#include <iostream>
#include <string>
#include "fungsi_kasir.h"


using namespace std;

int main()
{
    produk barang1;
    barang1.nama="susu kaleng";
    barang1.harga=15000;
    barang1.jumlahBeli=5;

    int total = hitungSubtotal(barang1.harga, barang1.jumlahBeli);
    
    cout<<"nama barang : "<<barang1.nama<<"\n";
    cout<<"total : "<<total<<"\n";

    return 0;
    
}