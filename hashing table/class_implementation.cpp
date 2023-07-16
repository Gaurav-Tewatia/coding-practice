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

    T *search(string name){
        int idx=hashfunc(name);
        node<T>*temp=arr[idx];
        while(temp!=NULL){
            if(temp->name==name){
                return &temp->value;
            }
            temp=temp->next;
            
        }
        return NULL;
    }
    
    void erase(string name){
        int idx=hashfunc(name);
        node<T>*temp=arr[idx];
        node<T>*prev=arr[idx];
        while(temp->next!=NULL){
            
            if(temp->next->name==name){
                break;
            }
            prev=prev->next;
            temp=temp->next;
        }
        temp=temp->next;
        prev->next=temp->next;
        temp->next=NULL;
        delete temp;

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

    int*price=table.search("Noodles");
    if(price!=NULL){
        cout<<"the price is "<<(*price);
    }
    else{
        cout<<"not found";
    }

    table.erase("Coke");
    
    table.print();
    
    

    return 0;
}