#include<iostream>
#include<queue>
using namespace std;

int joinrope(int ropes[],int n){
    priority_queue<int,vector<int>,greater<int> > p(ropes,ropes+n);
    int cost=0;
    while(p.size()>1){
        int a=p.top();
        p.pop();
        int b=p.top();
        p.pop();
        int t=a+b;
        cost+=t;
        p.push(t);
    }
    return cost;
}

int main(){
    int ropes[]={4,3,2,6};
    int n=4;
    cout<<joinrope(ropes,n);
    return 0;
}