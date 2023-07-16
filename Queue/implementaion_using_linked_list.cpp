#include<iostream>
#include<list>

using namespace std;

class queue{
    list<int> l;
    int cs;

    public:

    void push(int data){
        l.push_back(data);
        cs++;
    }
    
    bool empty(){
        return cs==0;
    }
    void pop(){
        if(!empty()){
            l.pop_front();
        cs--;
        }
    }

    int front(){
        return l.front();
    }
};

int main(){
    queue q;
    for(int i=0;i<10;i++){
        q.push(i);
    }
    q.pop();
    q.pop();
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}