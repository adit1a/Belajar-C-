#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct pemain{
    string nama;
    string agent;
    int kill;
    int death;
    int score;
};

void hasil(){
    cout << left << setw(15) << "Nama|" << setw(10) << "|Agent" << endl;
    cout << "-----------------------------------" << endl;
    cout << left << setw(15) << "Ardir" << setw(10) << "Jett" << endl;
    cout << left << setw(15) << "Iyan" << setw(10) << "Omen" << endl;
}

string cekPeforma(int skor){
    if (skor >= 300)return "memuaskan(MVP)";
    else if(skor >= 290)return "cukup baik";
    else if(skor >=250)return "baik";
    else return "beban jir";  
}

int main (){
    const int jumlahPemain = 5;
    pemain tim[jumlahPemain];
    int totalSkorTim=0;
    int indexMVP=0;
   
    hasil();
    cout<<"=== valorant track sederhana===== \n";
     

    for(int i=0; i<jumlahPemain; i++){
        cout << "\nInput data Pemain ke - " << i+1 << " : " << endl;
        cout << "nama player : ";
        
        
        getline(cin, tim[i].nama); 
        
        cout << "agent : ";
        getline(cin, tim[i].agent); 
        cout << "kill : ";
        cin >> tim[i].kill;
        cout << "death : ";
        cin >> tim[i].death;
        cout << "score (ACS) : ";
        cin >> tim[i].score;
        cin.ignore(); 
        totalSkorTim += tim[i].score;
        if(tim[i].score > tim[indexMVP].score) indexMVP = i;
    }

    
    cout << "\nLaporan Pertandingan Valorant" << endl;
    cout << left << setw(5) << "No" 
         << setw(15) << "| Nama" 
         << setw(12) << "| Agent" 
         << setw(8) << "| Kill" 
         << setw(8) << "| Death" 
         << setw(8) << "| Score" 
         << "| Performa" << endl;

    for(int k=0; k<jumlahPemain; k++){
        cout << left << setw(5) << k+1 
             << setw(15) << tim[k].nama 
             << setw(12) << tim[k].agent 
             << setw(8) << tim[k].kill 
             << setw(8) << tim[k].death 
             << setw(8) << tim[k].score 
             << cekPeforma(tim[k].score) << endl;
    }


        cout<<"-------------------------------------""\n";
        cout<<"MVP pertandingan ini: "<<tim[indexMVP].nama
            <<" dengan agent : "<<tim[indexMVP].agent<<"!"<<endl;
        cout<<"rata-rata tim acs tim : "<<totalSkorTim/jumlahPemain<<endl;
        cout<<"========================================"<<endl;
        return 0;

}




