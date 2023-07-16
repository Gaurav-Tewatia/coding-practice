#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int solve(string &s, int n, unordered_map<char,int> &mp){
    int i=0,j=0,mini=INT_MAX;
    int count=mp.size();

    while(j<n){
        if(mp.find(s[j])!=mp.end()){
        mp[s[j]]--;
        if(mp[s[j]]==0)
        count--;
        }
        

        if(count>0)
        j++;
        else if(count==0){
            mini=min(mini,j-i+1);
            while(count==0){
                mini=min(mini,j-i+1);
                if(mp.find(s[i])!=mp.end())
                {
                    mp[s[i]]++;
                    if(mp[s[i]]==1)
                    count++;
                }
                i++;
            }
            j++;
            
        }
        
        
    }
    return mini;
}

int main()
{
    string s;
    cout<<"enter the string 1 ";
    cin>>s;
    string s2;
    cout<<"enter the string to be found ";
    cin>>s2;

    unordered_map<char,int> mp;
    for(auto c:s2)
    mp[c]++;

    int n=s.size();

    cout<<solve(s,n,mp);
    
    return 0;
}