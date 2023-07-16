#include<iostream>
using namespace std;

int gcd(int a, int b){
    return b==0?a:gcd(b,a%b);
}
int lcm(int a, int b){
    return gcd(a,b)*(a*b);
}
int main(){
int a,b;
cin>>a>>b;
cout<<gcd(a,b);
cout<<endl;
cout<<lcm(a,b);
    return 0;
}