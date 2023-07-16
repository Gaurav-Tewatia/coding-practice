#include<iostream>
#include<algorithm>
using namespace std;

int countsubset(int *coin,int c,int n){
    int dp[n+1][c+1];
for(int i=0;i<n+1;i++){
    for(int j=0;j<c+1;j++){
        if(i==0){
            dp[i][j]=INT_MAX-1;    //because in line 26 we are adding 1 to the result and if we do INT_MAX then adding 1 to it will overflow the limit
        }
        if(i==1){
            if(j%coin[0]==0)
            dp[i][j]=j/coin[0];
            else
            dp[i][j]=INT_MAX-1;
        }
        if(j==0)
        dp[i][j]=0;
    }
}

for(int i=2;i<n+1;i++){
    for(int j=1;j<c+1;j++){
        if(coin[i-1]<=j){
    dp[i][j]=min((1+dp[i][j-coin[i-1]]) , dp[i-1][j]);
    
     }
    else
     dp[i][j]=dp[i-1][j];
    }
}



return dp[n][c]==INT_MAX-1?-1:dp[n][c];
}

int main()
{
int coin[]={2};

int n=sizeof(coin)/sizeof(int);
int sum=3;


cout<<countsubset(coin,sum,n);

    return 0;
}