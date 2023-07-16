#include<iostream>
#include<queue>
using namespace std;

typedef pair<int, pair<int,int> > node;

vector<int> kth_smallest(vector<vector<int> > arr,int k){
    vector<int> result;
    priority_queue<node,vector<node>,greater<node> > p;
    for(int i=0;i<arr.size();i++){
        p.push({arr[i][0],{i,0}});

    }

    while(result.size()<k){
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

    vector<vector<int> > arr{{10,20,30,40},
                                {15,25,35,45},
                                {24,29,37,48},
                                {32,33,39,50}};
                
    vector<int> output=kth_smallest(arr,3);
    cout<<output[output.size()-1];

    return 0;
}
