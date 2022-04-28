#include <iostream>
#include <windows.h>

using namespace std;

const int maksimal_tumpukan = 10;
bool keluar = false;
char ya_tidak;
int pilihan;
string data_masuk;

struct tumpukan{
    int posisi;
    string data[maksimal_tumpukan];
};

tumpukan buku;

void inisialisasi(){
    buku.posisi = -1;
}

bool kosong(){
    if(buku.posisi == -1){
        return true;
    }else{
        return false;
    }
}

bool penuh(){
    if(buku.posisi == maksimal_tumpukan - 1){
        return true;
    }else{
        return false;
    }
}

void push_tumpukan(string data_masukkan){
    if(kosong() == true){
        buku.posisi++;
        buku.data[buku.posisi] = data_masukkan;
        cout<<"Berhasil memasukkan : "<<data_masukkan<<endl;
    }else if(penuh() == false){
        buku.posisi++;
        buku.data[buku.posisi] = data_masukkan;
        cout<<"Berhasil memasukkan : "<<data_masukkan<<endl;
    }else{
        cout<<"Tumpukan sudah penuh"<<endl;
    }
}

void pop_tumpukan(){
    if(kosong() == true){
        cout<<"Tumpukan kosong"<<endl;
    }else{
        buku.posisi--;
        cout<<"Data berhasil dihapus"<<endl;
    }
}

void tampil_data(){
    if(kosong() == true){
        cout<<"Tidak ada data"<<endl;
    }else{
        for(int c = buku.posisi; c >= 0; c--){
            cout<<buku.data[c]<<endl;
        }
    }
}


int main()
{
    inisialisasi();
    do{
        cout<<"\t"<<"Stack Apps"<<endl;
        cout<<"1. Masukkan data kedalam Stack"<<endl;
        cout<<"2. Hapus data dari Stack"<<endl;
        cout<<"3. Tampilkan data Stack"<<endl;
        cout<<"4. Keluar"<<endl;
        cout<<"Silahkan pilih (1-4) : ";
        cin>>pilihan;

        switch(pilihan){
            case 1 :
                cout<<"Silahkan masukkan data : ";
                cin>>data_masuk;
                push_tumpukan(data_masuk);
                cout<<"Keluar (y/t) ? ";
                cin>>ya_tidak;
                if(ya_tidak == 'y' || ya_tidak == 'Y'){
                    cout<<" Jumpa kembali "<<endl;
                    keluar = true;
                }else{
                    system("cls");
                }
                break;
            case 2 :
                pop_tumpukan();
                cout<<"Keluar (y/t) ? ";
                cin>>ya_tidak;
                if(ya_tidak == 'y' || ya_tidak == 'Y'){
                    cout<<" Terima kasih"<<endl;
                    keluar = true;
                }else{
                    system("cls");
                }
                break;
            case 3 :
                tampil_data();
                cout<<"Keluar (y/t) ? ";
                cin>>ya_tidak;
                if(ya_tidak == 'y' || ya_tidak == 'Y'){
                    cout<<" Terima kasih"<<endl;
                    keluar = true;
                }else{
                    system("cls");
                }
                break;
            case 4 :
                cout<<"Yakin ingin keluar (y/t) ? ";
                cin>>ya_tidak;
                if(ya_tidak == 'y' || ya_tidak == 'Y'){
                    cout<<" Terima kasih"<<endl;
                    keluar = true;
                }else {
                    system("cls");
                }
                break;
            default :
                cout<<"Pilihan tidak tersedia..."<<endl;
                cout<<"Keluar (y/t) ? ";
                cin>>ya_tidak;
                if(ya_tidak == 'y' || ya_tidak == 'Y'){
                    cout<<" Terima kasih"<<endl;
                    keluar = true;
                }else{
                    system("cls");
                }
        }
    }while(keluar == false);

    return 0;
}
