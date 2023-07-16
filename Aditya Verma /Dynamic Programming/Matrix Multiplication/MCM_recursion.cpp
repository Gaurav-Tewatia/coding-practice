#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int solve(int *a,int i,int j){
    if(i>=j)
    return 0;
    
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int x=solve(a,i,k);
        int y=solve(a,k+1,j);
        int z=a[i-1]*a[k]*a[j];

        int temp=x+y+z;

        ans=min(ans,temp);

        
    }
    return ans;
}

int main()
{
    int a[]={40,20,30,10,30};
    int n=sizeof(a)/sizeof(int);
    
    cout<<solve(a,1,n-1);
    
    return 0;
}