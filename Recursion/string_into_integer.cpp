#include<iostream>
using namespace std;
int conversion(char s[],int n){
    if(n==0){
        return 0;
    }
    int digit=s[n-1]-'0';
     int smallans=conversion(s,n-1);
    
    return smallans*10+digit;
}
int main(){
    char s[1000];
    cin>>s;
    int n=strlen(s);
    int x=conversion(s,n);
    cout<<x<<endl;
    cout<<x+1;
    
    return 0;
}