#include<iostream>
using namespace std;
int fastpower(int a, int n){
    if(n==0){
        return 1;
    }
    int smallans=fastpower(a,n/2);
    smallans*=smallans;
    if(n&1){
        return smallans*a;
    }
    return smallans;
}
int main(){
    int a,n;
    cin>>a>>n;
    cout<<fastpower(a,n);
    return 0;
}