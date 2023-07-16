#include<iostream>
using namespace std;
void dnf_sort(int *a,int n){
    int l=0;
    int mid=0;
    int h=n-1;
    while(mid<=h){
        if(a[mid]==0){
            swap(a[l],a[mid]);
            l++;
            mid++;
        }
        if(a[mid==1]){
            mid++;
        }
        if(a[mid]==2){
            swap(a[mid],a[h]);
            h--;
        }
    }
    return;
}
int main(){
    int a[]={0,1,2,2,1,0,1,1,2,0,2,1,2,0,2,1,2,1};
    int n=sizeof(a)/sizeof(int);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    dnf_sort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
//please check it as the code is not working properly