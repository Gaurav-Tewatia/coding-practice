#include<iostream>
#include<algorithm>
using namespace std;

int profit(int *weight,int *price,int n, int c){
    int dp[n+1][c+1];
for(int i=0;i<n+1;i++){
    for(int j=0;j<c+1;j++){
        if(i==0 or j==0){
            dp[i][j]=0;
        }
        else if(weight[i-1]<=j){
    dp[i][j]=max(price[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
    
     }
    else
     dp[i][j]=dp[i-1][j];
    }
    }



return dp[n][c];
}

int main()
{
int weight[]={1,2,3,5};
int price[]={40,20,30,100};
int n=4;
int c=7;


cout<<profit(weight,price,n,c);
    return 0;
}