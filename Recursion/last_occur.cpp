#include<iostream>
using namespace std;
int lastoccur(int a[],int k, int n){
    if(n==0)
    return -1;
    int i=lastoccur(a+1,k,n-1);
    if(i==-1){
        if(a[0]==k){
            return 0;
        }
        else{
            return -1;
        }
    }
    return i+1;
}
int main(){
int a[]={1,2,3,2,4,3,5,7,4,5,3,7,8};
int k;
cin>>k;
int n=sizeof(a)/sizeof(int);
cout<<lastoccur(a,k,n);
    return 0;
}