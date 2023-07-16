#include<iostream>
#include<algorithm>
using namespace std;

int solve(node*root,int &res){
    if(root==NULL)
    return 0;
    
    int left=solve(root->left,res);
    int right=solve(root->right,res);

    int temp=max(root->value+max(left,right),root->value);
    int ans=max(temp,left+right+root->value);

    res=max(ans,res);

    return temp;
}

int main()
{
    int res=INT_MIN;

    cout<<solve(root,res);
    return 0;
}