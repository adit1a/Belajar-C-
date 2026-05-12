#include <iostream>
#include <string>

using namespace std;

struct karyawan {
    string nama;
    string jabatan;
    int jamKerja;
};

void hitungTotalGaji(karyawan k, int &totalGaji){
    int jamNormal = 40;
    int gajiPerJam = 50000;
    int lembur =75000;

    if(k.jamKerja < jamNormal){
        totalGaji=k.jamKerja * gajiPerJam;
        
    }else{
        int jamLembur =k.jamKerja - jamNormal;
        totalGaji =(jamNormal * gajiPerJam)+(jamLembur*lembur);
    }
}

int main()
{
    karyawan k1;
    int total=0;
    cout<<"sistem penggajian karywan"<<endl;
    cout<<"masukkan nama = ";
    cin>>k1.nama;
    cout<<"masukkan jabatan = ";
    cin>>k1.jabatan;
    cout<<"masukkan jamKerja = ";
    cin>>k1.jamKerja;
    cout<<"nama kamu adalah "<<k1.nama<<endl;
    cout<<"jabatan kamu adalah "<<k1.jabatan<<endl;
    cout<<"jam kerja  kamu adalah "<<k1.jamKerja<<endl;
    hitungTotalGaji(k1, total);
    cout<<"total gaji  kamu adalah = Rp "<<total<<endl;
    return 0;

}