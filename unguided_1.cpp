#include <iostream>
#include <windows.h>

using namespace std;

string judul, pengarang;
int harga, jumlah_halaman;
const int maks_tumpukan = 10;
bool keluar = false;

char out;
int pilih;


struct tumpukan{
       int posisi;
       int hal[maks_tumpukan];
       int harga[maks_tumpukan];
       string pengarang[maks_tumpukan];
       string judul[maks_tumpukan];
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
     if(buku.posisi == maks_tumpukan - 1){
         return true;
     }else{
          return false;
      }
  }
void push_tumpukan(string judul_masukan, string pengarang_masukan, int 
harga_masukan, int halaman_masukan){
      if(kosong() == true){
          buku.posisi++;
          buku.judul[buku.posisi] = judul_masukan;
          buku.pengarang[buku.posisi] = pengarang_masukan;
          buku.harga[buku.posisi] = harga_masukan;
          buku.hal[buku.posisi] = halaman_masukan;
          cout<<"Berhasil memasukkan";
     }else if(penuh() == false){
          buku.posisi++;
          buku.judul[buku.posisi] = judul_masukan;
          buku.pengarang[buku.posisi] = pengarang_masukan;
          buku.harga[buku.posisi] = harga_masukan;
          buku.hal[buku.posisi] = halaman_masukan;
          cout<<"Berhasil memasukkan";
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
          cout<<"Tidak ada data"<<endl;}else{
          for(int c = buku.posisi; c >= 0; c--){
               cout<<buku.judul[c]<<endl;
               cout<<buku.pengarang[c]<<endl;
               cout<<buku.harga[c]<<endl;
               cout<<buku.hal[c];
          }
      }
  }
  int main()
  {
      do{
               cout<<"\t"<<"Stack Apps"<<endl;
               cout<<"1. Masukkan data kedalam Stack"<<endl;
              cout<<"2. Hapus data dari Stack"<<endl;
              cout<<"3. Tampilkan data Stack"<<endl;
              cout<<"4. Keluar"<<endl;
              cout<<"Silahkan pilih (1-4) : ";
              cin>>pilih;
              switch(pilih){
              case 1 :
                  cout<<"masukkan judul buku : ";
                  cin>>judul;
                  cout<<"masukkan nama pengarang buku : ";
                  cin>>pengarang;
                  cout<<"masukkan jumlah halaman : ";
                  cin>>jumlah_halaman;
                  cout<<"masukkan harga buku : ";
                  cin>>harga;
                  push_tumpukan(judul,pengarang,jumlah_halaman,harga);
                  cout<<endl;
                 cout<<"Keluar (y/t) ? ";
                 cin>>out;
                 if(out == 'y' || out == 'Y'){
                     cout<<" bye bye "<<endl;
                     keluar = true;
                 }else{
                     system("cls");
                  }
                  break;

             case 2 :
                  pop_tumpukan();
                  cout<<"Keluar (y/t) ? ";
                  cin>>out;
                  if(out == 'y' || out == 'Y'){
                      cout<<" Thank you"<<endl;
                      keluar = true;
                 }else{
                     system("cls");
                  }
                  break;
            case 3 :
                tampil_data();
                cout<<"Keluar (y/t) ? ";
                cin>>out;
                if(out == 'y' || out == 'Y'){
                    cout<<" Thank you"<<endl;
                    keluar = true;
                 }else{
                      system("cls");
                  }
                  break;
         case 4 :
             cout<<"Apakah ingin keluar (y/t) ? ";
             cin>>out;
             if(out == 'y' || out == 'Y'){
                cout<<" Terima kasih"<<endl;
                keluar = true;
            }
            system("cls");
            break;
         default :
              cout<<"Pilihan tidak tersedia..."<<endl;
              cout<<"Keluar (y/t) ? ";
              cin>>out;
              if(out == 'y' || out == 'Y'){
                   cout<<" Terima kasih"<<endl;
                   keluar = true;
              }else{
              system("cls");
      }
   }
  }while(keluar == false);
  return 0;
  }
