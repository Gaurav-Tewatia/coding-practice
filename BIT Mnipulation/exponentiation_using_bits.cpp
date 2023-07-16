#include<iostream>
using namespace std;
int exponentiation(int a, int n){

    int ans=1;
    while(n>>0){
        int last=(n&1);
        if(last){
            ans*=a;
        }
        a*=a;
        n>>=1;

    }
    return ans;
}

int main(){
    int a,n;
    cin>>a>>n;
    cout<<exponentiation(a,n);

    return 0;

}