#include<iostream>
#include<algorithm>
using namespace std;

int profit(int *length,int *price,int n, int c){
    int dp[n+1][c+1];
for(int i=0;i<n+1;i++){
    for(int j=0;j<c+1;j++){
        if(i==0 or j==0){
            dp[i][j]=0;
        }
        else if(length[i-1]<=j){
    dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
    
     }
    else
     dp[i][j]=dp[i-1][j];
    }
    }



return dp[n][c];
}

int main()
{
int length[]={1,2,3,4,5,6,7,8};
int price[]={1, 5, 8, 9, 10, 17, 17, 20};
int n=8;
int c=8;


cout<<profit(length,price,n,c);
    return 0;
}