#include<iostream>
#include<algorithm>
using namespace std;

int countsubset(int *coin,int c,int n){
    int dp[n+1][c+1];
for(int i=0;i<n+1;i++){
    for(int j=0;j<c+1;j++){
        if(i==0){
            dp[i][j]=0;
        }
        if(j==0)
        dp[i][j]=1;
    }
}

for(int i=1;i<n+1;i++){
    for(int j=1;j<c+1;j++){
        if(coin[i-1]<=j){
    dp[i][j]=(dp[i][j-coin[i-1]] + dp[i-1][j]);
    
     }
    else
     dp[i][j]=dp[i-1][j];
    }
}



return dp[n][c];
}

int main()
{
int coin[]={1,2,5};

int n=sizeof(coin)/sizeof(int);
int sum=5;


cout<<countsubset(coin,sum,n);

    return 0;
}