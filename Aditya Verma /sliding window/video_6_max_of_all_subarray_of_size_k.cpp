#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
using namespace std;

vector<int>solve(int *arr,int n, int k){
    int i=0,j=0;
    list<int> li;
    vector<int> ans;
    while(j<n){
        while(!li.empty() and li.back()<arr[j])
        li.pop_back();
        li.push_back(arr[j]);
        if(j-i+1<k)
        j++;
        else if(j-i+1==k){
            ans.push_back(li.front());
            if(li.front()==arr[i])
            li.pop_front();
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    int arr[]={1,2,5,-2,4,-3,-5,-2,7};
    int n=sizeof(arr)/sizeof(int);
    int k;
    cout<<"enter the size of window ";
    cin>>k;
    vector<int> ans=solve(arr,n,k);
    for(auto c: ans)
    cout<<c<<",";
    
    return 0;
}