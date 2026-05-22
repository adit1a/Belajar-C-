#include <iostream>
#include <string>

using namespace std;

void garis(){
    cout<<"=============================="<<endl;
}

void indexKumulatif(double ipk){
    if (ipk >= 3.5){
        cout<<"lulus dengan memuaskan"<<endl;
    }else if(ipk <= 3.0){
        cout<<"lulus dengan baik"<<endl;
    }else if(ipk <= 1.5){
        cout<<"lulus dengan cukup"<<endl;
    }else{
        cout<<"maaf kamu lulu saja"<<endl;
    }
}
void hariKerja(int hari, int &gajiHari){
    gajiHari = 0;
    for(int i=1; i<=5; i++){
        cout<<"hari senin (1), sampai sabtu(6) hari ke- "<<i<<endl;
        cout<<"masukkan hari  = ";
        cin>>hari;
        cout<<"hari kerja kamu adalah = "<<hari<<endl;
        if(hari >=1 && hari <=5){
            gajiHari += 5000;
        }else if(hari <= 6){
            gajiHari += 10000;  
    }else{
            cout<<"hari yang kamu masukkan salah"<<endl;
        }
    }
}
void staf(int jamKerja, int &gajiLembur, int &gaji, int &gajiTotal){
    if (jamKerja > 8){
        gajiLembur = (jamKerja - 8) *5000;
    }else{
        gajiLembur = 0;
    }
    
    gajiTotal = (8 * gaji) + gajiLembur;
}

int main()
{
    string nama;
    
    garis();
    cout<<"selamt datang di sisttem ini "<<endl;
    garis();
    cout<<"masukkan nama kamu = ";
    cin>>nama;
    // cout<<"masukkan ipk kamu = ";
    garis();
    // double ipk;
    // cin>>ipk;
    // garis();
    cout<<"nama kamu adalah "<<nama<<endl;
    // indexKumulatif(ipk);
    // cout<<"ipk kamu adalah "<<ipk<<endl;
    // garis();
    int jamKerja;
    int gajiLembur;
    int gaji;
    int gajiTotal;
    cout<<"masukkan jam kerja kamu = ";
    cin>>jamKerja;
    staf(jamKerja, gajiLembur, gaji, gajiTotal);
    cout<<"masukkan gaji kamu = ";
    cin>>gaji;
    cout<<"jam kerja kamu adalah "<<jamKerja<<endl;
    cout<<"gaji lembur kamu adalah "<<gajiLembur<<endl;
    cout<<"gaji total kamu adalah "<<gajiTotal<<endl;

    return 0;
}


