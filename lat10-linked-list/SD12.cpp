#include<iostream>
using namespace std;
//deklarasi struct double linklist bolak-balik dengan pointer next prev
struct node
{
    int value;
    struct node* next;
    struct node* prev;
};
struct node* head;
struct node* tail;
void init()
{
//head ditunjuk dengan pointer prev yang menunjuk ke NULL
//tail ditunjuk dengan pointer next yang menunjuk ke NULL
//untuk kembali ke head , kita gunakan pointer prev dari tail hingga ke head
    head=NULL;
    tail=NULL;
}
// fungsi insert di awal node
void insertFirst(int element)
{
    struct node* newItem;
    newItem=new node;
    if(head==NULL)
    {
        head=newItem;
        newItem->prev=NULL;
        newItem->value=element;
        newItem->next=NULL;
        tail=newItem;
    }
    else
    {
//untuk insert di awal node, arahkan next ke head (awal), prev ke null , kemudian mengassign head sesuai newitem
        newItem->next=head;
        newItem->value=element;
        newItem->prev=NULL;
        head->prev=newItem;
        head=newItem;
    }
}
//fungsi insert di akhir node
void insertLast(int element)
{
    struct node* newItem;
    newItem=new node;
    newItem->value=element;
    if(head==NULL)
    {
        head=newItem;
        newItem->prev=NULL;
        newItem->next=NULL;
        tail=newItem;
    }
    else
    {
//untuk insert di akhir node, arahkan prev ke tail (akhir), next ke null , kemudian mengassign tail sesuai newitem
        newItem->prev=tail;
        tail->next=newItem;
        newItem->next=NULL;
        tail=newItem;
    }
}
//fungsi insert setelah node tertentu
void insertAfter(int old, int element)
{
//gunakan bantuan node temp untuk mencari data
    struct node* newItem;
    newItem=new node;
    struct node* temp;
    temp=head;
    if(head==NULL)
    {
        cout<<"could not insert"<<endl;
        return;
    }
//lakukan pengecekan apakah kode yang dicari sama dengan head, apabila sesuai maka operasi insert dilakukan jika tidak lanjutkan
    if(head==tail)
    {
        if(head->value!=old)
        {
            cout<<"could not insert"<<endl;
            return;
        }
//Arahkan pointer next ke newitem
        newItem->value=element;
        head->next=newItem;
        newItem->next=NULL;
        head->prev=NULL;
        newItem->prev=head;
        tail=newItem;
        return;
    }
    if(tail->value==element)
    {
        newItem->next=NULL;
        newItem->prev=tail;
        tail->next=newItem;
        tail=newItem;
        return;
    }
    while(temp->value!=old)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            cout<<"Could not insert"<<endl;
            cout<<"element not found"<<endl;
            return;
        }
    }
//arahkan pointer prev yang berada setelah node temp untuk menunjuk node newitem
    newItem->next=temp->next;
    newItem->prev=temp;
    newItem->value=element;
    temp->next->prev=newItem;
    temp->next=newItem;
}
//fungsi insert sebelum node tertentu
void insertBefore(int old, int element)
{
//gunakan bantuan node temp mencari node yang berisi data
//cek apakah sebelum node temp adalah head, jika iya lanjut langkah selanjutnya
    struct node* newItem;
    newItem=new node;
    struct node* temp;
    temp=head;
    if(head==NULL)
    {
        cout<<"could not insert"<<endl;
        return;
    }
    if(head==tail)
    {
        if(head->value!=old)
        {
            cout<<"could not insert"<<endl;
            return;
        }
        newItem->value=element;
        head->next=newItem;
        newItem->next=NULL;
        head->prev=NULL;
        newItem->prev=head;
        tail=newItem;
        return;
    }
    if(tail->value==element)
    {
        newItem->next=tail;
        newItem->prev=NULL;
        tail->next=newItem;
        tail=newItem;
        return;
    }
    while(temp->value!=old)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            cout<<"Could not insert"<<endl;
            cout<<"element not found"<<endl;
            return;
        }
    }
//arahkan pointer next ke node newitem dan menunjuk node temp
    newItem->prev=temp->prev;
    newItem->next=temp;
    newItem->value=element;
    temp->prev->next=newItem;
    temp->prev=newItem;
}
//fungsi hapus node diawal
void deleteFirst()
{
    if(head==NULL)
    {
        return;
    }
    if(head==tail)
    {
//menggunakan bantuan node cur untuk menghapus data di awal setelah di assign dengan head
        struct node* cur;
        cur=head;
        head=NULL;
        tail=NULL;
        delete cur;
        return;
    }
    else
    {
        struct node* cur;
        cur=head;
//pindahkan head ke element setelah head
        head=head->next;
        head->prev=NULL;
        delete cur;
    }
}
//fungsi hapus node diakhir
void deleteLast()
{
//isi head sama dengan tail, gunakan node cur untuk menghapus tail
    if(head==NULL) return;
    if(head==tail)
    {
        struct node* cur;
        cur=head;
        head=NULL;
        tail=NULL;
        delete cur;
        return;
    }
    else
    {
        struct node* cur;
        cur=tail;
        tail=tail->prev;
        tail->next=NULL;
        delete cur;
    }
}
//fungsi hapus node tertentu
void deleteItem(int element)
{
//gunakan node temp untuk mencari dan menunjuk node data element
    struct node* temp;
    temp=head;
    if(head==tail)
    {
        if(head->value!=element)
        {
            cout<<"could not delete"<<endl;
            return;
        }
        head=NULL;
        tail=NULL;
        delete temp;
        return;
    }
//jika x ditemukan , cek apakah ada data selanjutnya atau tidak
    if(head->value==element)
    {
        head=head->next;
        head->prev=NULL;
        delete temp;
        return;
    }
    else if(tail->value==element)
    {
        temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        delete temp;
        return;
    }
    while(temp->value!=element)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            cout<<"element not found"<<endl;
            return;
        }
    }
//arahkan pointer next pada node temp untuk menunjuk element setelah node temp
//arahkan pointer prev pada node temp untuk menunjuk element sebelum node temp
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    delete temp;
}
//fungsi untuk menampilkan node
void printList()
{
    struct node* temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->value);
        temp=temp->next;
    }
    puts("");
}
int main()
{
 cout<<"http://helmykediri.com/\n";
 cout<<"\n";
//Buat opsi pilihan sesuai fungsi masing-masing
    init();
    int choice;
    while(1)
    {
//Tampilan list menu yang bisa dipilih
        printf("1.InsertFirst \n2.InsertLast \n3.InsertAfter \n4.Insertbefore \n5.DeleteFirst \n6.DeleteLast \n7.Delete Node \n8.Lihat node");
        cout<<"\n\nMasukkan pilihan=";
        cin>>choice;
        if(choice==1)
        {
//Untuk memanggil fungsi yang sudah di deklarasikan diatas
            int element;
            cout<<"Masukkan node=";
            cin>>element;
            insertFirst(element);
            printList();
        }
        else if(choice==2)
        {
            int element;
            cout<<"Masukkan node=";
            cin>>element;
            insertLast(element);
            printList();
        }
        else if(choice==3)
        {
            int old,newitem;
            cout<<"Node setelah item=";
            cin>>old;
            cout<<"Masukkan node baru=";
            cin>>newitem;
            insertAfter(old,newitem);
            printList();
        }
        else if(choice==4)
        {
            int old,newitem;
            cout<<"Node sebelum item=";
            cin>>old;
            cout<<"Masukkan node baru=";
            cin>>newitem;
            insertBefore(old,newitem);
            printList();
        }
        else if(choice==5)
        {
            deleteFirst();
            printList();
        }
        else if(choice==6)
        {
            deleteLast();
            printList();
        }
        else if(choice==7)
        {
            int element;
            cout<<"Masukkan node yang akan dihapus=";
   cin>>element;
            deleteItem(element);
            printList();
        }
                else if(choice==8)
        {
            printList();
        }
    }
return 0;
}
