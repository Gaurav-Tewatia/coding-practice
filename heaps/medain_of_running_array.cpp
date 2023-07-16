#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> leftheap;
    priority_queue<int,vector<int>,greater<int> > rightheap;
    int d;
    cin>>d;
    float median=d;
    cout<<"meidan is "<<median<<endl;
    leftheap.push(d);
    cin>>d;
    while(d!=-1){
        if(leftheap.size()>rightheap.size()){
            if(d<median){
                rightheap.push(leftheap.top());
                leftheap.pop();
                leftheap.push(d);
                
            }
            else{
                rightheap.push(d);

            }
            median =(leftheap.top()+rightheap.top())/2.0;
        }
        else if(leftheap.size()==rightheap.size()){
            if(d<median){
                leftheap.push(d);
                median=leftheap.top();
            }
            else{
                rightheap.push(d);
                median=rightheap.top();
            }
        }
        else{
            if(d>median){
                leftheap.push(rightheap.top());
                rightheap.pop();
                rightheap.push(d);
            }
            else{
                leftheap.push(d);
            }
            median=(leftheap.top()+rightheap.top())/2.0;
        }



        cout<<"median is "<<median<<endl;
        cin>>d;
    }

    return 0;
}