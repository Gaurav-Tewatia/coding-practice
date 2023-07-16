#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

class minmaxstack{
    
    vector<int> stack;
    vector<int> mi;
    vector<int> ma;
    public:
    void push(int data){
        stack.push_back(data);
        int low=data;
        int high=data;
        if(mi.size()==0){
            mi.push_back(data);
            ma.push_back(data);
        }
        else if(mi.size()){
        low=min(mi[mi.size()-1],data);
        high=max(ma[ma.size()-1],data);
        }
        mi.push_back(low);
        ma.push_back(high);

    }

    void pop(){
        stack.pop_back();
        mi.pop_back();
        ma.pop_back();
    }

    int getmin(){
        return mi[mi.size()-1];
    }
    int getmax(){
        return ma[ma.size()-1];
    }
    bool empty(){
        return stack.size()==0;
    }

    void print(){
        for(int i=0;i<stack.size();i++){
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    minmaxstack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    stk.print();
    cout<<stk.getmin()<<" "<<stk.getmax();
    stk.pop();
    cout<<endl;
    stk.print();
    cout<<stk.getmin()<<" "<<stk.getmax();
    return 0;
}