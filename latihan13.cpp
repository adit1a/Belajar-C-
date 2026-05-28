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
    kata("proses hacking.......", 200);
    kata("sabar...", 300);
    kata("universitas hackk......", 300);
    kata("elon musk hackk......", 300);
    kata("hasil = " + to_string(nilai + nilai), 300);
    return 0;

}
