#include<iostream>
using namespace std;

void counting_sort(int *a,int n){
    int largest=-1;
    for(int i=0;i<n;i++){
        largest=max(largest,a[i]);
    }

    int *freq= new int[largest+1];
    for(int i=0;i<n;i++){
        freq[a[i]]++;
    }
    int j=0;
    for(int i=0;i<=largest;i++){
        while(freq[i]>0){
            a[j]=i;
            freq[i]--;
            j++;
        }
    }
}
int main(){
    int a[]={2,3,4,7,7,2,3,88,44,5,33,5,5,2,6,77,88,9,22,88,4};
    int n=sizeof(a)/sizeof(int);
    counting_sort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}