#include<iostream>
#include<stack>
using namespace std;

void insertatbottom(stack<int> &s,int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int data=s.top();
    s.pop();
    insertatbottom(s,x);
    s.push(data);
}
void reverse(stack<int> &s){
    if(s.empty()){
        return;
    }
    int x=s.top();
    s.pop();
    reverse(s);
    insertatbottom(s,x);
}
int main(){
    stack<int> s;
    for(int i=0;i<=5;i++){
        s.push(i);
    }
    
    reverse(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}