#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

vector<int> solve(int *arr, int n, int k){
    int i=0,j=0;
    queue<int> q;
    vector<int> ans;
    
    while(j<n){
        if(arr[j]<0)
        q.push(arr[j]);
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            if(q.empty())
            ans.push_back(0);
            else{
                ans.push_back(q.front());
                if(q.front()==arr[i])
                q.pop();
            }
            i++;
            j++;

        }
    }
    return ans;
}

int main()
{   
    int arr[]={1,2,-1,-3,4,-2,5,4,3,-5,4};
    int n=sizeof(arr)/sizeof(int);
    int k;
    cout<<"enter the size of the window ";
    cin>>k;

    vector<int> ans=solve(arr,n,k);

    for(auto c:ans)
    cout<<c<<",";
    
    return 0;
}