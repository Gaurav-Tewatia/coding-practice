#include<iostream>
using namespace std;

int partition(int *a,int s, int e){
    int i=s-1;
    int j=s;
    for(;j<e;j++){
        if(a[j]<=a[e]){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[e]);
    return i+1;
}

void quicksort(int *a,int s, int e){
    if(s>=e){
        return ;
    }

    int p=partition(a,s,e);

    quicksort(a,s,p-1);
    quicksort(a,p+1,e);
}

int main(){
    int a[]={2,3,5,2,6,3,6,78,5};
    int n=sizeof(a)/sizeof(int);
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}