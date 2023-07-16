#include<iostream>
#include<unordered_map>
using namespace std;

int check(int a[],int n){
    unordered_map<int,int> s;
    int pre=0;
    int len=0;
    for(int i=0;i<n;i++){
        pre+=a[i];
        if(pre==0){
            len=max(len,i+1);
        }
        if(s.find(pre)!=s.end()){
            len=max(len,i-s[pre]);
        }
        else{
            s[pre]=i;
        }
    }
    return len;
}

int main(){
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        a[i]=t;
    }
    cout<<check(a,n);
    return 0;
}