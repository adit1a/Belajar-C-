#ifndef FUNGSI_KASIR_H
#define FUNGSI_KASIR_H

#include <string>
using namespace std;

struct produk{
    string nama;
    int harga;
    int jumlahBeli;
};

int hitungSubtotal(int harga, int jumlah);
string struckNama(string nama, int harga);




#endif
