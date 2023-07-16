#include<iostream>
#include<unordered_map>
using namespace std;

int longestsubarraywithksum(int a[],int n,int k){
    unordered_map<int,int> s;
    int pre=0;
    int len=0;
    for(int i=0;i<n;i++){
        pre+=a[i];
        if(pre==k){
            len=max(len,i+1);
        }
        if(s.find(pre-k)!=s.end()){
            len=max(len,i-s[pre-k]);
        }
        else{
            s[pre]=i;
        }
    }
    return len;
}

int main(){
    int a[100];
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        a[i]=t;
    }
    cout<<longestsubarraywithksum(a,n,k);
    return 0;
}