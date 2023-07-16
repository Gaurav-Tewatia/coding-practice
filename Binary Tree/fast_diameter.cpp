#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;
    
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }

    
};

class Pair{
    public:
    int height;
    int diameter;
};

Pair fastdiameter(node*root){
    Pair p;
    if(root==NULL){
        p.height=p.diameter=0;
        return p;
    }

    Pair left=fastdiameter(root->left);
    Pair right=fastdiameter(root->right);


    p.height=max(left.height,right.height)+1;
    p.diameter=max(left.height+right.height,max(left.diameter,right.diameter));
    return p;

}

node* buildtree(){
        int n;
        cin>>n;
        if(n==-1){
            return NULL;
        }
        node* root=new node(n);
        root->left=buildtree();
        root->right=buildtree();
        return root;
    }

    int height(node*root){
        if(root==NULL){
            return 0;
        }
        int ls=height(root->left);
        int rs=height(root->right);
        return max(ls,rs)+1;
    }

    int main(){
        node*root=buildtree();
        Pair p=fastdiameter(root);
        cout<<p.diameter<<" ";
        cout<<p.height;
        return 0;
    }

    