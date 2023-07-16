#include<iostream>
#include<algorithm>
using namespace std;

int countsubset(int *weight,int c,int n){
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
        if(weight[i-1]<=j){
    dp[i][j]=(dp[i-1][j-weight[i-1]] + dp[i-1][j]);
    
     }
    else
     dp[i][j]=dp[i-1][j];
    }
}



return dp[n][c];
}

int main()
{
int weight[]={9,7,0,3,9,8,6,5,7,6};

int n=10;
int sum=31;


cout<<countsubset(weight,sum,n);

    return 0;
}