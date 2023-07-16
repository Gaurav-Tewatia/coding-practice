#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> p; //by default it is a max heap in order to make a min heap just write priority_queue<int,vecotor<int>,greater<int> p;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        p.push(t);
    }
    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }
    return 0;
}