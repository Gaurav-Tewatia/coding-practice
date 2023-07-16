#include<iostream>
using namespace std;
void merge(int *a,int s, int e){
    int temp[1000]={0};
    int mid=(s+e)/2;
    int i=s;
    int j=s;
    int k=mid+1;
    while(i<=mid && k<=e){
    if(a[i]<a[k]){
        temp[j++]=a[i++];
    }
    else{
        temp[j++]=a[k++];
    }
    }
    while(i<=mid){                  //when all the elemtn of one side gets exhausted the elements of the other side will compied as it is
        temp[j++]=a[i++];
    }
    while(k<=e){
        temp[j++]=a[k++];
    }
    for(int i=s;i<e;i++){
        a[i]=temp[i];
    }
}

void mergesort(int *a, int s, int e){
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    mergesort(a,s,mid);             //first divide the entire array
    mergesort(a,mid+1,e);

    merge(a,s,e);                   //then keep merging them in order
}
int main(){
    int a[]={1,4,3,7,6,5,9,2,8};
    int s=0;
    int n=sizeof(a)/sizeof(int);
    int e=n-1;
    mergesort(a,s,e);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}