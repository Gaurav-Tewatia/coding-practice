#include<iostream>
using namespace std;
bool issorted(int a[],int n){
    if(n==0 or n==1){
        return true;
    }
    if(a[0]<a[1] and issorted(a+1,n-1)){
        return true;
    }
    return false;
}
int main(){
    int a[]={1,2,3,4,5};
    int n=sizeof(a) / sizeof(int);
    cout<<issorted(a,n);
}