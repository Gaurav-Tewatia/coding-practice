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

    void print(node* root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        print(root->left);
        print(root->right);
   
    }

    int total(node*root){
        if(root==NULL){
            return 0;
        }
        return 1+(total(root->left))+ (total(root->right));
    }

    int sum(node*root){
        if(root==NULL){
            return 0;
        }
        return root->data+ sum(root->left)+ sum(root->right);
    }

    int main(){
        node*root=buildtree();
        cout<<total(root)<<" "<<sum(root);
        
        return 0;
    }