#include<iostream>
using namespace std;
int ways(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 2;
    }
    if(n==2){
        return 2;
    }
    int ans=0;
    return ans+=ways(n-1)+ways(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<<ways(n);
    return 0;
}

// needs to be solved again because the program is not correct