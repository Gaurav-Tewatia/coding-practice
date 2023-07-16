#include<iostream>
#include<cstring>
using namespace std;
template<typename T>
class node{
    public:
    T value;
    
    string name;
    
    node<T>*next;

    node(string name,int v){
        this->name=name;
        value=v;
        next=NULL;
    }

    ~node(){
        if(next!=NULL){
            delete next;
        }
    }

};
template<typename T>
class hashtable{
    node<T>**arr;
    int current_size;
    int table_size;

    int hashfunc(string name){

        int idx=0;
        int p=1;
        for(int i=0;i<name.length();i++){
            idx=idx+(name[i]*p)%table_size;
            idx=idx%table_size;
            p=(p*27)%table_size;
        }
        return idx;
    }

    void rehash(){
        node<T>** oldtable=arr;
        int oldtable_size=table_size;
        table_size=2*table_size;
        arr=new node<T>*[table_size];
        for(int i=0;i<table_size;i++){
            arr[i]=NULL;
        }
        current_size=0;

        for(int i=0;i<oldtable_size;i++){
            node<T>*temp=oldtable[i];
            while(temp!=NULL){
                insert(temp->name,temp->value);
                temp=temp->next;

            }
            if(oldtable[i]!=NULL){
                delete oldtable[i];
            }
        }
        delete [] oldtable;
    }
    public:
    hashtable(int size=7){
     table_size=7;
     arr=new node<T>*[table_size]; 
    
    int current_size=0;
        for(int i=0;i<table_size;i++){
            arr[i]=NULL;
        }
    }
    void insert(string name,T value){
        int idx=hashfunc(name);

        node<T> *n=new node<T>(name,value);
        n->next=arr[idx];
        arr[idx]=n;
        current_size++;
        float hashfactor=current_size/table_size;
        if(hashfactor>0.7){
            rehash();
        }
    }

    void print(){
        for(int i=0;i<table_size;i++){
            node<T> * temp=arr[i];
            cout<<"Bucket "<<i<<"->";
            while(temp!=NULL){
                cout<<temp->name<<"->";
                temp=temp->next;
            }
            cout<<endl;
        }
    }

   


};

int main(){

    hashtable<int> table;
    table.insert("Burger",120);
    table.insert("Pepsi",20);
    table.insert("BurgerPizza",150);
    table.insert("Noodles",25);
    table.insert("Coke",40);

    table.print();


    return 0;
}