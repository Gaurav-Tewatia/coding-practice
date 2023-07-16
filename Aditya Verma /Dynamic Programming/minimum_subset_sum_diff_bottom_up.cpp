#include<iostream>
#include<algorithm>
using namespace std;

void subset(int *weight,int c,int n,bool **dp){
    
for(int i=0;i<n+1;i++){
    for(int j=0;j<c+1;j++){
        if(i==0){
            dp[i][j]=false;
        }
        if(j==0)
        dp[i][j]=true;
    }
}

for(int i=1;i<n+1;i++){
    for(int j=1;j<c+1;j++){
        if(weight[i-1]<=j){
    dp[i][j]=(dp[i-1][j-weight[i-1]] or dp[i-1][j]);
    
     }
    else
     dp[i][j]=dp[i-1][j];
    }
}
        
  
}

int main()
{
int weight[]={1,8,5};



int n=3;
int sum=0;
for(int i=0;i<n;i++){
    sum+=weight[i];
}

bool **dp;
dp=new bool*[n+1];

for(int i=0;i<n+1;i++){
    dp[i]=new bool[sum+1];
}

subset(weight,sum,n,dp);

vector<int> res;

for(int i=0;i<=sum/2;i++){
    if(dp[n][i])
    res.push_back(i);
}
int result=INT_MAX;
for(int i=0;i<res.size();i++){
    result=min(result,sum-(2*res[i]));
}
cout<<result;
    return 0;
}