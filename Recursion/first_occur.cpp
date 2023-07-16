#include<iostream>
using namespace std;

int firstoccur(int a[],int k, int n){
    if(n==0){
        return -1;
    }
    if(a[0]==k){
        return 0;
    }
   
    int i = firstoccur(a+1,k,n-1);
    
   if(i==-1){
    return -1;
   }
   return i+1;
}
int main(){
    int a[]={1,2,4,3,5,7,3,4,7,5};
    int k;
    cin>>k;
    int n=sizeof(a)/sizeof(int);
    cout<<firstoccur(a,k,n);
    return 0;
}