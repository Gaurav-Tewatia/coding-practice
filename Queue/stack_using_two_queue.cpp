#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class stack{
 queue<T> q1;
 queue<T> q2;

 public:

    
    void push(T data){
        q1.push(data);
        
    }
    int size(){
        return q1.size() + q2.size();
    }
    bool empty(){
        return size()==0;
    }
    void pop(){
        if(q1.empty()){
            return ;
        }
        while(q1.size()>1){
            
            q2.push(q1.front());
            q1.pop();
           
        }
        q1.pop();
        swap(q1,q2);
    }

    T top(){
        while(q1.size()>1){
            T element=q1.front();
            q2.push(element);
            q1.pop();
            
        }
       
        T element =q1.front();
        
        q2.push(element);
        q1.pop();
        swap(q1,q2);
        return element;
    }

};

int main(){
    stack<int> s;
    for(int i=0;i<9;i++){
        s.push(i);
    }
    s.pop();
    s.pop();
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}