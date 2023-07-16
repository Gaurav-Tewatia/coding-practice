#include<iostream>
using namespace std;
int main(){
    int a[]={2,4,3,6,4,5,7,2,3,8};
    int n=sizeof(a)/sizeof(int);
    for(int i=0;i<n;i+=2){
        if(i!=0 and a[i]<a[i-1]){
            swap(a[i],a[i-1]);
        }
        if(i!=(n-1) and a[i]<a[i+1]){
            swap(a[i],a[i+1]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}