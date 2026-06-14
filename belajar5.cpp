#include <iostream>
#include <string>
#include <vector>

using namespace std;

class equipment{
    protected:
    string nama;
    string bahanDasar;
    int kualitas;

    public:
    equipment(string nama, string bahanDasar){
        this->nama =nama;
        this->bahanDasar =bahanDasar;
        this->kualitas = 70;
    }

    void tempa(){
        if(kualitas<100){
            kualitas+=30;
            if(kualitas >100) kualitas=100;
            cout<<">>"<< nama <<"sedang di tempa... Kualitas sekarang :"<<kualitas<<endl;
        }else{
            cout << ">> " << nama << " sudah mencapai kualitas maksimal!\n";
        }


    }
    string getNama() { return nama; }
    int getKualitas() { return kualitas; }
    string getBahan() { return bahanDasar; }
};

class weapon:public equipment{
    private:
    int baseDamage;
    public:
    weapon(string nama, string bahanDasar, int damage):equipment(nama, bahanDasar){
        this->baseDamage=damage;
    }
    int hitungDamageAkhir(){
        return baseDamage + (kualitas * 0.5);
    }

    int hitungHargaJual(){
        int hargaBahan = (bahanDasar == "mithril") ? 500:150;
        return hargaBahan + (hitungDamageAkhir()*10);
    }
};


int main()
{
    cout << "=== SIMULASI BLACKSMITH REBORN ===" << endl;
    cout << "Membuat senjata baru...\n\n";

    // Membuat OBJEK dari Class Weapon
    // Format: Weapon(Nama, Bahan, Base Damage)
    weapon pedangBaru("Pedang Besar Keberanian", "Mithril", 50);

    cout << "--- STATUS AWAL SENJATA ---" << endl;
    cout << "Nama Senjata : " << pedangBaru.getNama() << endl;
    cout << "Bahan Dasar  : " << pedangBaru.getBahan() << endl;
    cout << "Kualitas     : " << pedangBaru.getKualitas() << "%" << endl;
    cout << "Damage Awal  : " << pedangBaru.hitungDamageAkhir() << " DMG" << endl;
    cout << "Harga Jual   : " << pedangBaru.hitungHargaJual() << " Gold" << endl;
    cout << "---------------------------" << endl;

    // Proses Menempa Senjata (Memanggil fungsi dari objek)
    cout << "\n[Proses Penempaan Dimulai]" << endl;
    pedangBaru.tempa();
    pedangBaru.tempa();
    pedangBaru.tempa();

    // Status Senjata Setelah Ditempa
    cout << "\n--- STATUS AKHIR SENJATA ---" << endl;
    cout << "Nama Senjata : " << pedangBaru.getNama() << endl;
    cout << "Kualitas     : " << pedangBaru.getKualitas() << "%" << endl;
    cout << "Damage Baru  : " << pedangBaru.hitungDamageAkhir() << " DMG" << endl;
    cout << "Harga Jual   : " << pedangBaru.hitungHargaJual() << " Gold" << endl;
    cout << "----------------------------" << endl;

    cout << "\nSenjata siap dijual ke pelanggan!" << endl;
    return 0;

}