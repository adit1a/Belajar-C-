#include <iostream>
#include<string>

using namespace std;

struct siswa{
    string nama;
    double nilai;
};
string cekStatus(double nilai=0){
    if(nilai >=67)return "lulus";
    else return "remedial";
}

int main(){
    int jumlahSiswa;
    double totalNilai=0;
    cout<<"=== sistem nilai siswa ==="<<endl;
    cout<<"masukan jumlah siswa : ";
    cin>>jumlahSiswa;
    if (jumlahSiswa > 10 ){
        cout<<"kuota penuh"<<endl;
        return 0;
    }
    siswa daftarSiswa[jumlahSiswa];
    for (int i=0; i<jumlahSiswa; i++){
        cout<<"\ndata siswa ke - "<<i+1<<" : "<<endl;

        cout<<"nama :";
        cin.ignore();
        getline(cin, daftarSiswa[i].nama);

        cout<<"nilai :";
        cin>>daftarSiswa[i].nilai;
        totalNilai += daftarSiswa[i].nilai;
    }
    double rataRata = totalNilai / jumlahSiswa;
    cout<<"------------------------------------"<<"\n";
    cout<<"\nlaporan nilai siswa"<<endl;
    for(int i=0; i<jumlahSiswa; i++){
        cout<<i+1<<". "<<daftarSiswa[i].nama<<"\t: "<<daftarSiswa[i].nilai<<"\t";
        cout<<cekStatus(daftarSiswa[i].nilai)<<endl;
    }
    cout<<"------------------------------------""\n";
    cout<<"rata rata kelas : "<<rataRata<<endl;
}