#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int lcs(string x,string y, int n, int m,int **dp){
    if(n==0 or m==0)
    return 0;

    if(dp[n][m]!=-1)
    return dp[n][m];

    if(x[n-1]==y[m-1])
    return dp[n][m]= 1+lcs(x,y,n-1,m-1,dp);
    else
    return dp[n][m]=max(lcs(x,y,n,m-1,dp),lcs(x,y,n-1,m,dp));
}

int main()
{
    string x;
    string y;
    cout<<"enter both strings ";
    cin>>x>>y;
   
    int n=x.size();
    int m=y.size();

     int **dp;
    dp=new int*[n+1];
    for(int i=0;i<n+1;i++){
        dp[i]=new int[m+1];
    }

    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            dp[i][j]=-1;
        }
    }

    cout<<lcs(x,y,n,m,dp);
    return 0;
}