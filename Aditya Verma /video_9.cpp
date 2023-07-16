#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

void insert(stack<int> &s, int temp){
    if(s.size()==0)
    {
        s.push(temp);
        return;
    }
    int x=s.top();
    s.pop();
    insert(s,temp);
    s.push(x);
}

void reverse(stack<int> &s){
    if(s.size()==1)
    return;

    int temp=s.top();
    s.pop();
    reverse(s);
    insert(s,temp);
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

    cout<<endl;

    reverse(s);

    for(stack<int> dump=s;!dump.empty();dump.pop()){
        cout<<dump.top()<<" ";
    }
    
    return 0;
}