#include <iostream>
#include <string>

using namespace std;

struct kendaraan{
    string jenisKend;
    int waktuMasuk;
};

void hitungParkir(kendaraan k, int waktuKeluar, int &totalBayar){
    int durasi =waktuKeluar - k.waktuMasuk;
    if (durasi < 1) durasi = 1;
    if(k.jenisKend == "motor"){
        totalBayar = 2000 + (durasi-1) * 1000;
    }else if(k.jenisKend == "mobil"){
        totalBayar= 5000 + (durasi - 1) * 2000;
    }
}

int main()
{
    kendaraan k1;
    int waktuKeluar, totalBayar=0;
    cout<<"sistem parkir otomatis""\n";
    cout<<"=====================""\n";
    cout<<"masukkan jenis kendaraan = ";
    cin>>k1.jenisKend;
    cout<<"waktu masuk = ";
    cin>>k1.waktuMasuk;
    cout<<"waktu keluar jam = ";
    cin>>waktuKeluar;
    hitungParkir(k1, waktuKeluar, totalBayar);
    cout<<"durasi parkir = "<<waktuKeluar-k1.waktuMasuk<< " jam "<<endl;
    cout<<"total = "<<totalBayar<<endl;
    return 0;
    
    

}