#include<iostream>
#include<unordered_set>
using namespace std;

bool check(int a[],int n){
    unordered_set<int> s;
    int pre=0;
    for(int i=0;i<n;i++){
        pre+=a[i];
        if(pre==0 or s.find(pre)!=s.end()){
            return true;
        }
        s.insert(pre);
    }
    return false;
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
    if(check(a,n)){
        cout<<"yes there is sub-array with the sum zero";
    }
    else{
        cout<<"no there is no sub-array with sum equal to zero";
    }
    return 0;
}