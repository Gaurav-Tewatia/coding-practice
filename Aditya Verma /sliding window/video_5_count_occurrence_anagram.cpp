#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int solve(string &s,unordered_map<char,int>&mp,int n,int k){
    int i=0,j=0,count=mp.size(),ans=0;

    while(j<n){
        if(mp.find(s[j])!=mp.end())
        {
            mp[s[j]]--;
            if(mp[s[j]]==0)
            count--;
        }
        if(j-i+1<k)
        j++;
        else if(j-i+1==k){
            if(count==0)
            ans++;
            if(mp.find(s[i])!=mp.end()){
                mp[s[i]]++;
                if(mp[s[i]]==1)
                count++;
            }
            i++;
            j++;
            

        }
    }
    return ans;
}

int main()
{
    string s;
    cout<<"enter the string ";
    cin>>s;
    cout<<endl;
    unordered_map<char,int> mp;
    
    

    cout<<"what is the word ";
    string s2;
    cin>>s2;

    for(auto c:s2)
    mp[c]++;

    int k=s2.size();

    int n=s.size();

    cout<<solve(s,mp,n,k);
    
    return 0;
}