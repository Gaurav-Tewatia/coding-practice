#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int profit(int *weight,int *price,int n,int c,vector<vector<int> >&dp){
    if(n==0 || c==0){
        return 0;
    }

    if(dp[n][c]!=-1)
    return dp[n][c];
    
    if(weight[n-1]<=c){
        return dp[n][c]=max(price[n-1]+profit(weight,price,n-1,c-weight[n-1],dp),profit(weight,price,n-1,c,dp));

    }
    else
    return dp[n][c]=profit(weight,price,n-1,c,dp);
}
int main(){
int weight[]={1,2,3,5};
int price[]={40,20,30,100};
int n=4;
int c=7;
vector<vector<int> > dp(n+1,vector<int>(c+1,-1));
cout<<profit(weight,price,n,c,dp);
    return 0;
}