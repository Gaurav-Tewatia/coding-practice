#include<iostream>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

int solve(string &s, int n, int k){
    int i=0,j=0,maxi=0;
    unordered_map<char,int> mp;

    while(j<n){
        mp[s[j]]++;
        
        if(mp.size()<k)
        j++;
        else if(mp.size()==k){
            maxi=max(maxi,j-i+1);
            j++;
        }
        else {
            while(mp.size()>k){
            mp[s[i]]--;
            if(mp[s[i]]==0)
            mp.erase(s[i]);
            i++;
            }
            
            j++;
        }
    }
    return maxi;
}

int main()
{
    string s;
    cout<<"enter the string ";
    cin>>s;
    cout<<"enter the no. of unique characters ";
    int k;
    cin>>k;
    int n=s.size();

    cout<<solve(s,n,k);
    
    return 0;
}