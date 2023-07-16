#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int lcs(string x,string y, int n, int m){

    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 or j==0)
            dp[i][j]=0;
            else if(x[i-1]==y[j-1] and i!=j)
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);


        }
    }

    return dp[n][m];
}

int main()
{
    string x;
    cout<<"enter both strings ";
    cin>>x;
   
    int n=x.size();
    int m=x.size();

    cout<<lcs(x,x,n,m);
    return 0;
}