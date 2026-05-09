#include <iostream>
#include <string>

using namespace std;

struct karakter{
    string nama;
    int serangan;
    int level;
    int hp;
    int exp;

};

struct enemy{
    string nama;
    int serangan;
    int level;
    int hp;
    int exp;

};

void kenaSerangan(karakter &K, int damage){
    K.hp -= damage;
    cout<<K.nama<< " terkena damage sebesar " << damage << "!" <<endl;
    if(K.hp <= 0){
        cout<<K.nama<<" kamu mati"<<"\n";
    }
}
void tambahExp(karakter &K, int jumlah){
    K.exp += jumlah;
    cout<<K.nama<<" mendapatkan jumlah " <<jumlah<< " exp."<<endl;
    if(K.exp >= 100){
        K.level ++;
        K.exp -=100;
        K.hp += 20;
        cout<<"Level up " <<K.nama<< " Sekarang level " << K.level <<endl;
    }
}

int main(){
    karakter pemain;
    pemain.nama = "adit";
    pemain.level=1;
    pemain.hp = 100;
    pemain.exp = 0;

    cout<< "---- Status Awal-----"<<endl;
    cout<<"nama : "<< pemain.nama << "| Hp :"<<pemain.hp<<endl;

    kenaSerangan(pemain, 100);
    tambahExp(pemain, 400);

    cout<<"status pemain : "<<endl;
    cout<<"Nama : "<<pemain.nama<< "| Hp :"<<pemain.hp<<"| Level : "<<pemain.level<<"\n";
}