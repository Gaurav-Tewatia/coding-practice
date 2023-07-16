#include<iostream>
using namespace std;
int partition(int *a,int s,int e){
    int pivot=a[e];
    int i=s-1;
    int j=s;
    for( ;j<=e-1;j++){
        if(a[j]<=pivot){
            i++;
            swap(a[i],a[j]);
        }
        
    }
    swap(a[i+1],a[e]);
    return i+1;
}

void selection_sort(int *a,int s, int e){
    if(s>=e){
        return;
    }
    int p=partition(a,s,e);
    selection_sort(a,s,p-1);
    selection_sort(a,p+1,e);

    return;
}

int main(){
int a[]={1,3,2,6,4,7,9,4,6};
int n=sizeof(a)/sizeof(int);
int s=0;
int e=n-1;
selection_sort(a,s,e);
for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}
    return 0;
}