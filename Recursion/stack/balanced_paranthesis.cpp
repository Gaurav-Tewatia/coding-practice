#include<iostream>
#include<stack>
using namespace std;

bool check(char s[]){
    stack<char> stk;
    for(int i=0;i!='\0';i++){
        if(s[i]=='('){
            stk.push('(');
        }
        else if(s[i]==')'){
            if(stk.empty() or stk.top()!='('){
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}
int main(){
    char s[100]="(AB+(SK)+383)(())";
    if(check(s)){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
    return 0;
}