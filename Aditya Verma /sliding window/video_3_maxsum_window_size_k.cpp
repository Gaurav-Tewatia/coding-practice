#include<iostream>
#include<algorithm>
using namespace std;

int maxsize(int *arr, int k,int n){

    int i=0,j=0,sum=0,maxi=INT_MIN;
    while(j<n){
        sum+=arr[j];
        if(j-i+1<k)
        j++;
        else if(j-i+1==k){
            maxi=max(maxi,sum);
            sum-=arr[i];
            i++;
            j++;
        }
    }
    return maxi;
}

int main()
{
    int arr[]={2,3,1,5};

    cout<<"enter the size of window ";
    int k;
    cin>>k;
    int n=sizeof(arr)/sizeof(int);

    cout<<maxsize(arr,k,n);
    
    return 0;
}