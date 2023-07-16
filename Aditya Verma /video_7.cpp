#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

void pushele(stack<int> &s, int temp){
    if(s.size()==0 or s.top()>=temp){
        s.push(temp);
        return;
    }
    int x=s.top();
    s.pop();
    pushele(s,temp);
    s.push(x);
}


void sortstack(stack<int> &s){
    if(s.size()==1)
    return;

    int temp=s.top();
    s.pop();
    sortstack(s);
    pushele(s,temp);
}

int main()
{
    stack<int> s;
    s.push(3);
    s.push(6);
    s.push(1);
    s.push(0);
    s.push(5);
    
    for(stack<int> dump=s;!dump.empty();dump.pop()){
        cout<<dump.top()<<" ";
    }

    sortstack(s);
    cout<<endl;


    for(stack<int> dump=s;!dump.empty();dump.pop()){
        cout<<dump.top()<<" ";
    }
    return 0;
}