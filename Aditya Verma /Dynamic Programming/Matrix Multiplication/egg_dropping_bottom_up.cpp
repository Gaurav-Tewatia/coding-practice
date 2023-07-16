#include<iostream>

#include<algorithm>

using namespace std;

int static dp[1001][1001];
int solve(int e, int f){
    if(f==0 or f==1)
    return f;

    if(e==0 or e==1)
    return f;

    if(dp[e][f]!=-1)
    return dp[e][f];

    int mini=INT_MAX;
    
    int left,right;
    for(int i=1;i<=f;i++){
        if(dp[e-1][i-1]!=-1)
        left=dp[e-1][i-1];
        else{
            left=solve(e-1,i-1);
            dp[e-1][i-1]=left;
        }
        

        if(dp[e][f-i]!=-1)
        right=dp[e][f-i];
        else{
            right=solve(e,f-i);
            dp[e][f-i]=right;
        }
        

        int temp=1+ max(left,right);

        mini=min(mini,temp);
    }
    return dp[e][f]= mini;
}

int main()
{
    int e,f;
    cout<<"enter the amount of eggs and floors ";
    cin>>e>>f;
    memset(dp,-1,sizeof(dp));
    cout<<solve(e,f);
    return 0;
}