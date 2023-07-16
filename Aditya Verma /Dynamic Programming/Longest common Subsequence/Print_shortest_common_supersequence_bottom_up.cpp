#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string lcs(string x,string y, int n, int m){

    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 or j==0)
            dp[i][j]=0;
            else if(x[i-1]==y[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);


        }
    }

    int i=n,j=m;
    string s="";
    while(i>0 and j>0){
        if(x[i-1]==y[j-1]){
            s.push_back(x[i-1]);
            i--;
            j--;

        }
        else if(dp[i-1][j]>=dp[i][j-1])
        {
            s.push_back(x[i-1]);
            
            i--;
        }
        else
        {
           
            s.push_back(y[j-1]);
            j--; 
        }
    }

    while(i>0){
        s.push_back(x[i-1]);
        i--;
    }
    while(j>0){
        s.push_back(y[j-1]);
        j--;
    }

    reverse(s.begin(),s.end());
    return s;
}

int main()
{
    string x;
    string y;
    cout<<"enter both strings ";
    cin>>x>>y;
   
    int n=x.size();
    int m=y.size();

    cout<<lcs(x,y,n,m);
    return 0;
}