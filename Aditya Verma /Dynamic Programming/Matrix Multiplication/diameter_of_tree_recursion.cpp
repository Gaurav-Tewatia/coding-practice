#include<iostream>
#include<algorithm>
using namespace std;

int solve(node*root,int &res){
    if(root==NULL)
    return 0;
    
    int left=solve(root->left,res);
    int right=solve(root->right,res);

    int temp=1+max(left,right);
    int ans=max(temp,left+right+1);

    res=max(ans,res);

    return temp;
}

int main()
{
    int res=INT_MIN;

    cout<<solve(root,res);
    return 0;
}