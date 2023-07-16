#include<iostream>
#include<algorithm>
using namespace std;

int solve(int *arr,int n, int k){
    int i=0,j=0,sum=0,maxi=0;

    while(j<n){
        sum+=arr[j];
        
        if(sum<k)
        j++;
        else if(sum==k){
            maxi=max(maxi,j-i+1);
            j++;
        }
        else{
            while(sum>k){
                sum-=arr[i];
                i++;
            }
            j++;
        }
    }
    return maxi;
}

int main()
{
    int arr[]={4,1,1,1,2,3,5};
    int n=sizeof(arr)/sizeof(int);
    int k;
    cout<<"enter the sum to be found ";
    cin>>k;
    cout<<solve(arr,n,k);
    return 0;
}