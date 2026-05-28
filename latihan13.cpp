#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void garis(){
    cout<<"=============================="<<endl;
}
void kata(string teks, int kecepatan){
    for(int i=0; i<teks.length(); i++){
        cout<<teks[i];
        Sleep(kecepatan);
    }
    cout<<endl;

}

int main(){
    int nilai;
    garis();
    cout<<"kalkulator sederhana"<<endl;
    garis();
    cout<<"masukkan angka = ";
    cin>>nilai;
    kata("proses menghitung...", 500);
    kata("sabar...", 500);
    kata("proses berhasil...", 700);
    cout<<"hasil = "<<nilai+nilai<<endl;
    return 0;

}
