#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

void push_data(char huruf);
char pop_data();
char tumpukan[100];
int posisi = -1;

int main(){
    char kata[100];
    int i, panjang, penghitung = 0;

    cout<<"Masukkan sebuah kata (akhiri dengan enter): ";
    gets(kata);

    panjang = strlen(kata);

    for(i = 0; i < panjang; i++){
        push_data(tolower(kata[i]));
    }
    for(i = 0; i < panjang; i++){
        if(tolower(kata[i]) == pop_data()){
            penghitung++;
        }
    }
    if(penghitung == panjang){
        cout<< kata <<" adalah palindrom"<<endl;
    }else{
        cout<< kata <<" bukan palindrom"<<endl;
    }

    return 0;
}

void push_data(char huruf){
    tumpukan[++posisi] = huruf;
}

char pop_data(){
    return tumpukan[posisi--];
}
