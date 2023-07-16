#include<iostream>
#include<queue>
using namespace std;

typedef pair<int, pair<int,int> > node;

vector<int> merge(vector<vector<int> > arr){
    vector<int> result;
    priority_queue<node,vector<node>,greater<node> > p;
    for(int i=0;i<arr.size();i++){
        p.push({arr[i][0],{i,0}});

    }

    while(!p.empty()){
        node current=p.top();
        p.pop();
        int element=current.first;
        int row=current.second.first;
        int col=current.second.second;
        result.push_back(element);
        if(col+1<arr[row].size()){
            p.push({arr[row][col+1],{row,col+1}});
        }

    }
    return result;
}

int main(){

    vector<vector<int> > arr{{2,6,12,15},
                                {1,3,14,20},
                                {3,5,8,10}};
                
    vector<int> output=merge(arr);
    for(auto x:output){
        cout<<x<<" ";
    }

    return 0;
}
