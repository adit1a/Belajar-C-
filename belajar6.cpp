#include <iostream>
#include <string>

using namespace std;

class kendaraan {
    protected:
        string tipe;
        float bensin;
    public:
        kendaraan(string tipe){
            this->tipe=tipe;
            this->bensin =50.0f;
        }
    void isiBensin(float liter){
        bensin +=liter;
        if(bensin >100.0)bensin =100.0;
        cout<<">> Bensin berhasil diisi. Total sekarang:"<<bensin<<"\n";
    }
};

class mobilBalap : public kendaraan {
    private:
        int topSpeed;
    public:
    mobilBalap(string nama, int speed):kendaraan (nama){
        this->topSpeed=speed;
    }
    void aktifkanNitro(){
        bensin -=20.0;
        if (bensin<0.0)bensin =0.0;
        cout<<">> nitro  aktif! kecepatan menembus"<<topSpeed<<"km/jam"<<"\n";
    }
};

int main(){
    mobilBalap mobilAdit("ferarri", 200);

    mobilAdit.aktifkanNitro();
    mobilAdit.isiBensin(50.0);

    return 0;
}