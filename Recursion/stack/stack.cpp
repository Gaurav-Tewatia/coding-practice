#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class stack{
    private:
    vector<T> v;
    
    public:
    void push(T d){
        v.push_back(d);
    }
    void pop(){
        if(!empty()){
        v.pop_back();
        } 
    }
    bool empty(){
        if(v.size()==0){
            return true;
        }
        return false;
    }
    T top(){
        return v[v.size()-1];
    }

};

int main(){
    stack<int> s;
    for(int i=0;i<5;i++){
        s.push(i*i);
    }
    while (!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    
    return 0;
}