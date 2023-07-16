#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int static dp[1001][1001];

bool ispalindrome(string s, int i, int j){
    while(i<j){
        if(s[i]!=s[j])
        return false;
        i++;
        j--;
    }
    return true;
}

int solve(string a,int i,int j){
    if(i>=j)
    return 0;
    
    if(ispalindrome(a,i,j))
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];

    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int x,y;
        if(dp[i][k]!=-1)
        x=dp[i][k];
        else{

         x=solve(a,i,k);
         dp[i][k]=x;
        }
        if(dp[k+1][j]!=-1)
        y=dp[k+1][j];
        else{
            y=solve(a,k+1,j);
            dp[k+1][j]=y;
        }
         
        int z=1;

        int temp=x+y+z;

        ans=min(ans,temp);

        
    }
    return dp[i][j]=ans;
}

int main()
{
    string s;
    cout<<"enter the string ";
    cin>>s;
    int n=s.size();

    memset(dp,-1,sizeof(dp));
    
    cout<<solve(s,0,n-1);
    
    return 0;
}