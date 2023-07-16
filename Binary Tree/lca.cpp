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

 void bfs(node*root){
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
            cout<<f->data<<",";
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

 node* lca(node*root,int a ,int b){
    if(root==NULL){
        return NULL;
    }
    if(root->data==a or root->data==b){
        return root;
    }
    node* left=lca(root->left,a,b);
    node* right =lca(root->right,a,b);
    if(left!=NULL and right!=NULL){
        return root;
    }
    if(left!=NULL){
        return left;
    }
    return right;
 }

 int main(){
    node*root=buildtree();
    cout<<lca(root,6,9)->data;
    return 0;
 }