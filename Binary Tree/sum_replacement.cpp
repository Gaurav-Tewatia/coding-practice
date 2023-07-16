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
        node*root=new node(n);
        root->left=buildtree();
        root->right=buildtree();
    return root;

 }
 
 int sum(node*&root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL and root->right==NULL){
        return root->data;
    }
    int temp=root->data;
    int left=sum(root->left);
    int right=sum(root->right);
    root->data=left+right;
    return temp+root->data;
 }

 void print(node*root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*f=q.front();
        if(q.front()==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<" ";
            q.pop();
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
 }

 int main(){

    node*root=buildtree();
    print(root);
    sum(root);
    print(root);
 }