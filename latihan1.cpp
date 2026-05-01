#include <iostream>
#include <string>

using namespace std;

int main(){
   int angka;
   cout << "masukkan angka: ";
   cin >> angka;
   for(int i=1; i<=10;  i++){
    cout << "hasil "<< i << "X" << angka<< "=" <<i * angka<<"\n";
   }
    return 0;

   }
