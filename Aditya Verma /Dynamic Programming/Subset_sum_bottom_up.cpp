#include<iostream>
#include<algorithm>
using namespace std;

bool subset(int *weight,int c,int n){
    bool dp[n+1][c+1];
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
        
   



return dp[n][c];
}

int main()
{
int weight[]={1,2,3,5};

int n=4;
int sum=7;

if(subset(weight,sum,n)){
    cout<<"possible";
}
else
cout<<"not possible";
    return 0;
}