#include<iostream>
using namespace std;
int factorial(int n){
    if(n==1){
        return 1;
    }
      
        return n*factorial(n-1);
}
int combination(int n, int r){
    int ans=factorial(n)/(factorial(r)*factorial(n-r));
    return ans;
}
int ways(int n){
    if(n==0 or n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    int ans=0;
     ans+=ways(n-1)+combination(n-1,1)*ways(n-2);
     return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<ways(n);
    return 0;
}