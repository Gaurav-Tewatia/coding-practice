#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

map<string,int> mp;

int solve(string s,int i,int j,bool istrue){
    if(i>j)
    return 0;

    if(i==j){
        if(istrue)
        return s[i]=='T';
        else
        return s[i]=='F';
    }

    string temp=to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(istrue));
    if(mp.find(temp)!=mp.end())
    return mp[temp];
    
    int ans=0;
    for(int k=i+1;k<j;k+=2){
        int lt=solve(s,i,k-1,true);
        int lf=solve(s,i,k-1,false);
        int rt=solve(s,k+1,j,true);
        int rf=solve(s,k+1,j,false);

        if(s[k]=='&'){
            if(istrue)
            ans+=(lt*rt);
            else
            ans+=(lf*rt)+(lt*rf)+(lf*rf);
        }
        else if(s[k]=='|'){
            if(istrue)
            ans+=(lf*rt)+(rf*lt)+(rt*lt);
            else
            ans+=(lf*rf);
        }
        else if(s[k]=='^'){
            if(istrue)
            ans+=(lf*rt)+(lt*rf);
            else
            ans+=(lf*rf)+(rt*lt);
        }

        
    }
    return mp[temp]=ans;
}

int main()
{
    string s;
    cout<<"enter string ";
    cin>>s;
    int n=s.size();
    
    cout<<solve(s,0,n-1,true);
    
    return 0;
}