#include <iostream>
#include<string>

using namespace std;

void cekStatus(double nilai=0){
    if(nilai >=70){
        cout<<"lulus"<<endl;
    }else{
        cout<<"Remedial"<<endl;
    }
}


int main(){
    int jumlahSiswa;
    double totalNilai=0;
    cout<<"=== sistem nilai siswa ==="<<endl;
    cout<<"masukan jumlah siswa : ";
    cin>>jumlahSiswa;

    if(jumlahSiswa > 10){
        cout<<"kuota penuh"<<endl;
        return 0;
    }else{
        double daftarNilai[jumlahSiswa];
        string daftarNama[jumlahSiswa];

        for (int i=0; i<jumlahSiswa; i++){
            cout<<"\nmasukan nilai siswa ke - "<<i+1<<" : ";
            double nilai=0;
            cin>>nilai;
            daftarNilai[i] = nilai;
            totalNilai += nilai;
            cout<<"\nmasukan nama siswa ke - "<<i+1<<" : ";
            string nama;
            cin>>nama;
            daftarNama[i] = nama;
           
        }
        cout<<"\ntotal nilai siswa : "<<totalNilai<<endl;
        double rataRata = totalNilai / jumlahSiswa;
        cout<<"\nrata-rata nilai siswa : "<<rataRata<<endl;
        cout<<"\nlaporan nilai siswa"<<endl;
        
        for(int i=0; i<jumlahSiswa; i++){
                cout<<i+1<<". "<<daftarNama[i]<<"\t: "<<daftarNilai[i]<<"\t";
                cekStatus(daftarNilai[i]);
            }
        
    
        cout<<"\n=== status kelulusan siswa ==="<<endl;

    }
 return 0;   
}