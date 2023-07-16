#include<iostream>
using namespace std;

template<typename T> //now it works for all type of data types;
int search(T a[],int n, T key){
    for(int i=0;i<n;i++){
        if(a[i]==key){
            return i;
        }
    }
    return 0;
}

int main(){
    int a[]={1,2,3,4,5,6,7};
    int n=sizeof(a)/sizeof(int);
    int key;
    cin>>key;
    cout<<search(a,n,key);

    char c[]={'a','v','f','\0'};
    char k;
    cin>>k;
    cout<<search(c,4,k);
    return 0;
}