#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void insert(vector<int> &ans,int temp){
    if(ans.size()==0 or ans[ans.size()-1]<=temp)
    {
        ans.push_back(temp);
        return ;
    }
    int x=ans[ans.size()-1];
    ans.pop_back();
    insert(ans,temp);
    ans.push_back(x);
}

void sortarray(vector<int> &ans){
    if(ans.size()==1){
        return;
    }
    int temp=ans[ans.size()-1];
    ans.pop_back();
    sortarray(ans);
    insert(ans,temp);
}

int main()
{
    vector<int> test;
    test.push_back(2);
    test.push_back(7);
    test.push_back(1);
    test.push_back(5);
    test.push_back(0);

    for(auto c:test){
        cout<<c<<" ";
    }
    cout<<endl;

    sortarray(test);
    
    for(auto c:test){
        cout<<c<<" ";
    }

    return 0;
}