#include<stdio.h> 
#include<iostream> 
#include<conio.h>
#include<iomanip>
using namespace std;

int main ()
{
	//deklarasi variabel
	int Nilai [ 20 ];
	int i, j, N;
	int temp, awal, akhir, tengah, Bilangan, angka; 
	
	//proses penginputan data
	cout<<"Banyak bilangan: ";
	cin>>N;
	for (i=0; i<N; i++)
	{
		cout<<"Elemen ke-"<<i<<" = ";
		cin>>Nilai [i];
	}
	
	cout<<"Elemen Sebelumnya diurut = ";
	for (i=0; i<N; i++)
	cout<<setw (3)<<Nilai[i];
	
	//proses pengurutan data
	for (i=0; i<N; i++)
	{
		for (j=i+1; j<N; j++)
		{
			if (Nilai [ i ] > Nilai [j])
			{
				temp = Nilai [i];
				Nilai [i] = Nilai [j];
				Nilai [j] = temp;
			}
		}
	}
	
	cout<<"\nElemen Setelah diurut = ";
	for (i=0; i<N;i++){
		cout<<setw (3)<< Nilai [ i ];
	}
	
	cout<<"\nIndeks Elemen = ";
		for (i=0; i<N; i++){
			cout<<setw ( 3 )<<i;
		}
		 
	cout<<"\nMasukan data yang akan anda cari: "; 
	cin>>Bilangan;
		
	//proses pencarian data
	awal = 0 ;
	akhir = N-1;
	do{
		 tengah =( akhir + awal ) / 2;
		 if ( Bilangan < Nilai [ tengah ] )
		 akhir = tengah - 1;
		 else 
		 awal = tengah + 1 ;
	} while (( akhir >= awal) && ( Nilai [ tengah ] != Bilangan )) ;
	 
	if ( Nilai [ tengah ] == Bilangan ){
		cout<<"\nData "<<Bilangan<<" ada dalam array pada posisi ke ";
		for(int i=0; i<N; i++){
			if (Nilai[i] == Bilangan) cout<<i<<" ";
		}
	} else {
		cout<<"\nData "<<Bilangan<<" tidak ada dalam array\n";
	}
	getch () ;
}

