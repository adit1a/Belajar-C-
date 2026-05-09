#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
#include <cstdlib>

using namespace std;

void ketik(string teks, int jeda ){
    for(int i=0; i<teks.length(); i++ ){
        cout<<teks[i]<<flush;
        Sleep(jeda);
    }
    cout<<endl;
}

void Ketik(string teks, int jeda ){
    for(int i=0; i<teks.length(); i++ ){
        cout<<teks[i]<<flush;
        Sleep(jeda);
    }
}

int main (){
    ketik("Harusnya aku katakan dari dulu", 200);
    ketik("Sebelum semua jadi begini", 200);
    Ketik("Kini terlanjur,", 240);
    ketik(" kisah sudah tak sama", 250);
    Ketik("Seperti ", 270);
    ketik( "Kamu telah banyak berubah", 200 );
    ketik( "Tak s'perti yang ku kenal dahulu, mm", 200 );
    

    return 0;
    
}