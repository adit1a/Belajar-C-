#include <iostream>
#include <string>

using namespace std;

void garis(){
    cout<<"=============================="<<endl;
}

int main()
{
    string nama;
    double ipk;
    garis();
    cout<<"selamt datang di sisttem ini "<<endl;
    garis();
    cout<<"masukkan nama kamu = ";
    cin>>nama;
    cout<<"masukkan ipk kamu = ";
    cin>>ipk;
    garis();
    cout<<"nama kamu adalah "<<nama<<endl;
    cout<<"ipk kamu adalah "<<ipk<<endl;
    garis();
    if (ipk <= 3.5){
        cout<<"lulus dengan memuaskan"<<endl;
    }else if(ipk >= 3.0){
        cout<<"lulus dengan baik"<<endl;
    }else if(ipk >= 2.5){
        cout<<"lulus dengan cukup"<<endl;
    }else{
        cout<<"maaf kamu lulu saja"<<endl;
    }
    return 0;
}


