#include<iostream>
#include<conio.h>
#include<stdlib.h>
#define true 1
#define false 0
using namespace std;
typedef struct node *simpul;
struct node{
 char Isi;
 simpul kanan;
 simpul kiri;
};

void Sisip_Depan (simpul &DL, char elemen );
void Sisip_Belakang (simpul &DL, char elemen ) ;
void Sisip_Tengah1 (simpul &DL, char elemen1, char elemen2 ) ;
void Sisip_Tengah2 (simpul &DL, char elemen1, char elemen2 ) ;
void Hapus_Depan (simpul &DL);
void Hapus_Belakang (simpul &DL);
void Hapus_Tengah (simpul &DL, char elemen);
void Cetak (simpul DL);

int main ( )
{
 char huruf, huruf2;
 simpul DL = NULL; //Pastikan Bahwa DL kosong
 int i;
 cout<<"==>OPERASI PADA DOUBLY LINKED LIST\n\n";
 
 cout<<"==>PENYISIPAN SIMPUL DI DEPAN\n\n";
 for (i=1;i<=4;i++)
 {
 cout<<"Masukan Huruf : "; cin>>huruf;
 Sisip_Depan (DL, huruf );
 }
 Cetak (DL);
 cout<<"==>PENYISIPAN SIMPUL DI BELAKANG\n\n";
 for (i=1;i<=4;i++)
 {
 cout<<"Masukan Huruf : "; cin>>huruf;
 Sisip_Belakang (DL, huruf );
 }
 Cetak (DL);
 cout<<"==>SISIP SIMPUL SETELAH SIMPUL TERTENTU\n\n";
 cout<<"Masukan Huruf : "; cin>>huruf;
 cout<<"Disisip Setelah Huruf : "; cin>>huruf2;
 cout<<huruf<<" Disisip Setelah "<<huruf2<<endl;
 Sisip_Tengah1 (DL, huruf, huruf2);
 Cetak (DL) ;
 cout<<"==>SISIP SIMPUL SEBELUM SIMPUL TERTENTU\n\n";
 cout<<"Masukan Huruf : "; cin>>huruf;
 cout<<"Disisip Sebelum Huruf : "; cin>>huruf2;
 cout<<huruf<<" Disisip Sebelum "<<huruf2<<endl;
 Sisip_Tengah2 (DL, huruf, huruf2);
 Cetak (DL) ; 
 cout<<"==>HAPUS SIMPUL DEPAN\n\n";
 cout<<"Setelah Hapus Simpul Depan "<<endl;
 Hapus_Depan (DL);
 Cetak (DL);
 cout<<"==>HAPUS SIMPUL BELAKANG\n\n";
 cout<<"Setelah Hapus Simpul Belakang "<<endl;
 Hapus_Belakang (DL);
 Cetak (DL);
 cout<<"==>HAPUS SIMPUL TENGAH\n\n";
 cout<<"Masukkan Huruf Tengah Yang akan dihapus : ";cin>>huruf;
 Hapus_Tengah (DL,huruf);
 Cetak (DL);
 getch ( ) ;
}

void Sisip_Depan (simpul &DL, char elemen)
{ 
 simpul baru; 
 baru = (simpul) malloc (sizeof(simpul));
 baru->Isi = elemen ;
 baru-> kanan = NULL;
 baru-> kiri = NULL;
 if (DL== NULL)
 DL=baru;
 else
 {
 baru->kanan = DL;
 DL->kiri = baru;
 DL= baru;
 }
}

void Sisip_Tengah1 (simpul &DL, char elemen1, char elemen2)
{
 simpul bantu,baru;
 baru = (simpul) malloc (sizeof(simpul));
 baru->Isi = elemen1 ;
 baru-> kanan = NULL;
 baru-> kiri = NULL;
 if (DL== NULL)
 cout << "List Kosong............"<<endl;
 else
 {
 bantu = DL;
 while (bantu ->Isi != elemen2) 
 bantu = bantu -> kanan;
 baru->kanan = bantu ->kanan;
 baru->kiri = bantu;
 bantu->kanan->kiri = baru;
 bantu->kanan = baru;
 }
}

void Sisip_Tengah2 (simpul &DL, char elemen1, char elemen2)
{
 simpul bantu, baru;
 baru = (simpul) malloc (sizeof(simpul));
 baru->Isi = elemen1 ;
 baru-> kanan = NULL;
 baru-> kiri = NULL;
 if (DL== NULL)
 cout<<"List Kosong.............."<<endl;
 else
 {
 bantu = DL;
 while (bantu->kanan->Isi != elemen2) 
 bantu = bantu -> kanan;
 baru->kanan = bantu ->kanan;
 baru->kiri = bantu;
 bantu->kanan->kiri = baru;
 bantu->kanan = baru;
 }
}

void Sisip_Belakang (simpul &DL, char elemen)
{
 simpul bantu, baru;
 baru = (simpul) malloc (sizeof(simpul));
 baru->Isi = elemen ;
 baru-> kanan = NULL;
 baru-> kiri = NULL;
 if (DL== NULL)
 DL=baru;
 else
 {
 bantu = DL;
 while (bantu->kanan != NULL)
 bantu = bantu -> kanan;
 bantu->kanan = baru;
 baru->kiri = bantu;
 }
}

void Cetak (simpul DL)
{
 simpul bantu ;
 if (DL==NULL)
 cout<<"Linked List Kosong......."<<endl;
 else
 {
 bantu =DL;
 cout<<"Isi Linked List : ";
 while (bantu ->kanan != NULL)
 {
 cout<<bantu->Isi<<" <==> ";
 bantu=bantu->kanan;
 }
 cout<<bantu->Isi;
}
cout<<"\n\n";
}

void Hapus_Depan (simpul &DL)
{
 simpul Hapus ;
 if (DL==NULL)
 cout<<"Linked List Kosong.............";
 else
 {
 Hapus = DL;
 DL = DL-> kanan ;
 DL ->kiri = NULL;
 Hapus -> kanan = NULL;
 free (Hapus);
 }
}

void Hapus_Belakang (simpul &DL)
{
 simpul bantu, hapus;
 if (DL==NULL)
 cout<<"Linked List Kosong.............";
 else
 {
 bantu = DL;
 while (bantu ->kanan->kanan != NULL) bantu=bantu->kanan;
 hapus = bantu -> kanan;
 bantu -> kanan = NULL;
 hapus -> kiri = NULL;
 free (hapus);
 }
}

void Hapus_Tengah(simpul &DL, char elemen)
{
 simpul bantu,hapus;
 if (DL==NULL)
 cout<<"Linked List Kosong.............";
 else
 {
 bantu = DL;
 while (bantu ->kanan->Isi != elemen) 
 bantu=bantu->kanan;
 hapus = bantu -> kanan;
 bantu ->kanan->kanan->kiri = bantu;
 bantu ->kanan = bantu->kanan->kanan;
 hapus -> kanan = NULL;
 hapus -> kiri = NULL;
 free (hapus);
 }
}


