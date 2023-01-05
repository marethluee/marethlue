#include "tubes.h"

void createListDivisi(list_divisi &L){
    L.first=NULL;
}

adr_anggota createAnggota(string nama,string proker){
    adr_anggota p;
    p = new elmAnggota;
    p->info.nama = nama;
    p->info.proker = proker;
    p->next=NULL;
    return p;
}
adr_divisi createDivisi(string nama,string desc){
    adr_divisi p;
    p = new elmDivisi;
    p->info.nama = nama;
    p->info.desc = desc;
    p->info.jumlah_anggota = 0;
    p->kadiv = NULL;
    p->next = NULL;
    return p;
}

//insert last
void tambahAnggota(adr_divisi &L,adr_anggota &p){
    adr_anggota q;
    q = L->kadiv;
    L->info.jumlah_anggota = L->info.jumlah_anggota + 1;
    if(q != NULL){
        while(q->next != NULL){
            q = q->next;
        }
        q->next = p;
    }else{
        L->kadiv = p;
    }
}

adr_anggota hapusKadiv(adr_divisi &L){
    adr_anggota p;
    L->info.jumlah_anggota = L->info.jumlah_anggota - 1;
    p = L->kadiv;
    L->kadiv = L->kadiv->next;
    p->next=NULL;
    return p;
}
adr_anggota deleteLastAnggota(adr_divisi &L){
    adr_anggota p,q;
    L->info.jumlah_anggota = L->info.jumlah_anggota - 1;
    p = L->kadiv;
    if(p->next == NULL){
        L->kadiv = NULL;
        return p;
    }
    while(p->next != NULL){
        q=p;
        p=p->next;
    }
    q->next = NULL;
    return p;
}
adr_anggota deleteAfterAnggota(adr_divisi &L,adr_anggota &p){

    L->info.jumlah_anggota = L->info.jumlah_anggota - 1;
    if(p!=NULL){
        adr_anggota q = p->next;
        p->next = q->next;
        q->next = NULL;
        return q;
    }
    return NULL;
}

adr_anggota searchAnggota(adr_divisi L, string nama){
    adr_anggota p = L->kadiv;
    while(p!=NULL){
        if(p->info.nama == nama){
            return p;
        }
        p=p->next;
    }
    return p;
}
adr_anggota hapusAnggotaDivisi(adr_divisi &L, string nama){
    adr_anggota p = searchAnggota(L,nama);
    if(p == NULL){
        return p;
    }
    if(p == L->kadiv){
        return hapusKadiv(L);
    }
    if(p->next == NULL){
        return deleteLastAnggota(L);
    }
    adr_anggota q = L->kadiv;
    while(q->next != p && q != NULL){
        q=q->next;
    }
    return deleteAfterAnggota(L,q);
}
adr_anggota hapusAnggota(list_divisi L, string nama){
    adr_divisi p=L.first;
    while(p!=NULL){
        adr_anggota a = hapusAnggotaDivisi(p,nama);
        if(a!=NULL){
            return a;
        }
        p=p->next;
    }
    return NULL;
}

void printAnggota(adr_divisi L){
    if(L->kadiv!=NULL){
        cout << "Kepala Divisi:" << L->kadiv->info.nama << endl;
            cout << "Anggota:" << endl;
            adr_anggota a = L->kadiv->next;
            while(a!=NULL){
                cout << endl;
                cout << a->info.nama << endl;
                cout << "Job desc:" << a->info.proker << endl;
                a = a->next;
            }
    }
}
void insertFirstDivisi(list_divisi &L, adr_divisi &p){
    p->next = L.first;
    L.first = p;
}
void insertLastDivisi(list_divisi &L,adr_divisi &p){
    adr_divisi q = L.first;
    q = L.first;
    if(q != NULL){
        while(q->next != NULL){
            q = q->next;
        }
        q->next = p;
    }else{
        L.first = p;
    }
}
void insertAfterDivisi(adr_divisi &p, adr_divisi &q){
    q->next = p->next;
    p->next = q;
}

void deleteAllAnggota(adr_divisi &p){
    while(p->kadiv!=NULL){
        adr_anggota q = hapusKadiv(p);
        delete(q);
    }
}

adr_divisi deleteFirstDivisi(list_divisi &L){
    adr_divisi p;
    p = L.first;
    L.first = L.first->next;
    p->next=NULL;
    return p;
}
adr_divisi deleteLastDivisi(list_divisi &L){
    adr_divisi p,q;
    p = L.first;
    if(p->next == NULL){
        L.first = NULL;
        return p;
    }
    while(p->next != NULL){
        q=p;
        p=p->next;
    }
    q->next = NULL;
    return p;
}
adr_divisi deleteAfterDivisi(adr_divisi &p){
    if(p!=NULL){
        adr_divisi q = p->next;
        p->next = q->next;
        q->next = NULL;
        return q;
    }
    return NULL;
}

adr_divisi searchDivisi(list_divisi L, string nama){
    adr_divisi p = L.first;
    while(p!=NULL){
        if(p->info.nama == nama){
            return p;
        }
        p=p->next;
    }
    return p;
}

adr_divisi hapusDivisi(list_divisi &L, string nama){
    adr_divisi p = searchDivisi(L,nama);
    if(p == NULL){
        return p;
    }
    if(p == L.first){
        return deleteFirstDivisi(L);
    }
    if(p->next == NULL){
        return deleteLastDivisi(L);
    }
    adr_divisi q = L.first;
    while(q->next != p && q != NULL){
        q=q->next;
    }
    return deleteAfterDivisi(q);
}

void printDivisi(list_divisi L){
    adr_divisi p = L.first;
    while(p!=NULL){
        cout << p->info.nama << endl;
        cout << p->info.desc << endl;
        cout << "jumlah anggota:" << p->info.jumlah_anggota << endl;
        if(p->kadiv != NULL) {
            cout << "Kepala Divisi:" << p->kadiv->info.nama << endl;
        }
        p=p->next;
    }
}
void printAll(list_divisi L){
    adr_divisi p = L.first;
    while(p!=NULL){
        cout << p->info.nama << endl;
        cout << p->info.desc << endl;
        cout << "jumlah anggota:" << p->info.jumlah_anggota << endl;
        if(p->kadiv != NULL) {
            printAnggota(p);
        }

        p=p->next;
    }
}
