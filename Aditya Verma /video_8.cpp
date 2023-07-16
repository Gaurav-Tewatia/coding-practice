#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;


void deletemiddle(stack<int> &s, int middle){
    if(middle==0){
        s.pop();
        return;
    }

    int temp=s.top();
    s.pop();
    deletemiddle(s,middle-1);
    s.push(temp);
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
    
    int middle=s.size()/2;

    deletemiddle(s,middle);


    for(stack<int> dump=s;!dump.empty();dump.pop()){
        cout<<dump.top()<<" ";
    }

    
    return 0;
}