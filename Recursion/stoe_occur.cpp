#include<iostream>
using namespace std;
int storeoccur(int *a,int i, int k, int n,int j,int *s){
    if(i==n){
        return j;
    }
    if(a[i]==k){
        s[j]=i;
        return storeoccur(a,i+1,k,n,j+1,s);
    }
    return storeoccur(a,i+1,k,n,j,s);
    
}
void alloccur(int a[],int i,int k, int n){
    if(i==n){
        return;
    }
    if(a[i]==k)
    cout<<i<<" ";
    alloccur(a,i+1,k,n);
}
int main(){
    int a[]={1,2,4,2,5,7,4,5,8,7,9,5,4};
    int k;
    cin>>k;
    int n=sizeof(a)/sizeof(int);
    alloccur(a,0,k,n);
    cout<<endl;
    int store[1000]={0};
    cout<<storeoccur(a,0,k,n,0,store);
    return 0;
}