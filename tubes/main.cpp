#include "tubes.h"

int main()
{
    list_divisi L;
    createListDivisi(L);
    int pilihan;
    do{
        cout << "|||||||||||MENU|||||||||||||||"<<endl;
        cout << "0. Keluar" << endl;
        cout << "1. Print Divisi serta Anggota" << endl;
        cout << "2. Print Divisi saja" << endl;
        cout << "3. Print Anggota sebuah Divisi" << endl;
        cout << "4. Tambah Divisi" << endl;
        cout << "5. Tambah Anggota" << endl;
        cout << "6. Cabut Anggota" << endl;
        cout << "7. Bubar Divisi" << endl;
        cout << "Pilih:";
        cin >> pilihan;
        adr_anggota tmpA=NULL;
        adr_divisi tmpD=NULL;
        string nama,desc;
        switch(pilihan){
        case 1:
            printAll(L);
            break;
        case 2:
            printDivisi(L);
            break;
        case 3:
            cout << "Nama Divisi(hindari spasi, pakai underscore):";
            cin >> nama;
            tmpD = searchDivisi(L,nama);
            if(tmpD!=NULL){
                cout << tmpD->info.nama << endl;
                printAnggota(tmpD);
            }
            break;
        case 4:
            cout << "Nama Divisi(hindari spasi, pakai underscore):";
            cin >> nama;
            cout << "Deskripsi(hindari spasi, pakai underscore):";
            cin >> desc;
            tmpD = createDivisi(nama,desc);
            insertFirstDivisi(L,tmpD);
            break;
        case 5:
            cout << "Nama Divisi(hindari spasi, pakai underscore):";
            cin >> nama;
            tmpD = searchDivisi(L,nama);
            if(tmpD!=NULL){
                cout << tmpD->info.nama << endl;
                cout << "Nama (hindari spasi, pakai underscore):";
                cin >> nama;
                cout << "Proker (hindari spasi, pakai underscore):";
                cin >> desc;
                tmpA = createAnggota(nama,desc);
                tambahAnggota(tmpD,tmpA);
            }
            break;
        case 6:
            cout << "Nama Anggota:";
            cin >> nama;
            tmpA = hapusAnggota(L,nama);
            if(tmpA == NULL){
                cout << "Nama anggota tidak ada" << endl;
            }else{
                cout << tmpA->info.nama << " status keanggotaan dicabut" << endl;
                delete(tmpA);
            }
            break;
        case 7:
            cout << "Nama Divisi:";
            cin >> nama;
            tmpD = hapusDivisi(L,nama);
            if(tmpD == NULL){
                cout << "Nama divisi tidak ada" << endl;
            }else{
                cout << "Divisi "<< tmpD->info.nama << " dilepas" <<endl;
                deleteAllAnggota(tmpD);
                delete(tmpD);
            }
            break;
        }
    }while(pilihan!=0);
    return 0;
}
