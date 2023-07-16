#include<iostream>
#include<stack>
using namespace std;

class queue{

    stack<int> s;
    stack<int> s1;
    public:
    void push(int data){
        s.push(data);
    }

    void pop(){
        if(s.empty()){
            return ;
        }
        while(s.size()>1){
            s1.push(s.top());
            s.pop();
        }
        s.pop();
        while(s1.size() > 0) {
            s.push(s1.top());
            s1.pop();
        }
    }

    int size(){
        return s.size()+s1.size();
    }
    bool empty(){
        return size()==0;
    }
    int front(){
        if(s.empty()){
            return 0;
        }
        while(s.size()>1){
            s1.push(s.top());
            s.pop();
        }
        int element=s.top();
        s1.push(element);
        s.pop();
        while(s1.size() > 0) {
            s.push(s1.top());
            s1.pop();
        }
        return element;
    }
};
int main(){
    queue q;
    for(int i=0;i<9;i++){
        q.push(i);
    }
    q.pop();
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}