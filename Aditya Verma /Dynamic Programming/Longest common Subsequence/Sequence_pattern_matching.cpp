#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool lcs(string x,string y, int n, int m){

    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 or j==0)
            dp[i][j]=0;
            else if(x[i-1]==y[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);


        }
    }

    return (dp[n][m]==x.length());
}

int main()
{
    string x;
    string y;
    cout<<"enter both strings ";
    cin>>x>>y;
   
    int n=x.size();
    int m=y.size();

    if(lcs(x,y,n,m)){
        cout<<"present";
    }
    else
    cout<<"not present";
    return 0;
}