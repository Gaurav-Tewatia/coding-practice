#include<iostream>
#include<stack>
using namespace std;

void transfer(stack<int> &s, stack<int> &s2,int n){
    for(int i=0;i<n;i++){
        s2.push(s.top());
        s.pop();
    }
}

void reverse(stack<int> &s){
    stack<int>s2;
    int n=s.size();
    for(int i=0;i<n;i++){
        int x=s.top();
        s.pop();
        transfer(s,s2,n-1-i);
        s.push(x);
        transfer(s2,s,n-1-i);
    }
}
int main(){
    stack<int> s;
    for(int i=0;i<=5;i++){
        s.push(i);
    }
    reverse(s);
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }


    return 0;
}