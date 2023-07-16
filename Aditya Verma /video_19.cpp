#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int solve(vector<int> &arr,int index,int k, int &ans){
    if(arr.size()==1){
        return arr[0];

    }

    index=(index+k)%arr.size();
    arr.erase(arr.begin()+index);
   return solve(arr,index,k,ans);
   
}

int main()
{
    int n;
    int k;

    cin>>n>>k;
    k--;
    vector<int> arr;
    for(int i=0;i<n;i++){
        arr.push_back(i+1);
    }
    int index=0;
    int ans=-1;
    cout<<endl;
    cout<<solve(arr,index,k,ans);
    
    return 0;
}