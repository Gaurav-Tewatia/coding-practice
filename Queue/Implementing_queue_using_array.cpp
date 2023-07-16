#include<iostream>
using namespace std;

class queue{

    int *arr;
    int cs;
    int ms;
    int fr,r;
    public:
    queue(int n){
        arr=new int[n];
        fr=0;
        r=n-1;
        cs=0;
        ms=n;
    }
    bool empty()const{
        return cs==0;
     }
     bool full()const{
        return cs==ms;
     }
     void push(const int data){
       if(!full()){
        r=(r+1)%ms;
        arr[r]=data;
        cs++;
       }
     }

     

    void pop(){
        if(!empty()){
            fr=(fr+1)%ms;
            cs--;
        }
    }
    int front()const{
        return arr[fr];
    }
    ~queue(){
        if(arr!=NULL){
            delete[]arr;
            arr=NULL;
        }
    }


};

int main(){
    queue q(10);
    
    for(int i=0;i<10;i++){
        q.push(i);
    }
    q.pop();
    q.pop();
    q.pop();
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    
    return 0;
}