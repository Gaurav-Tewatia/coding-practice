#include<iostream>
#include<queue>
#include<climits>
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

node* insertinnode(node*root,int data){
    if(root==NULL){
        return new node(data);
    }
    if(data<=root->data){
        root->left=insertinnode(root->left,data);
    }
    else{
        root->right=insertinnode(root->right,data);
    }
    return root;
}
node*build(){
    int n;
    cin>>n;
    node*root=NULL;
    while(n!=-1){
        root=insertinnode(root,n);
        cin>>n;
    }
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

 

 void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<",";
    inorder(root->right);
 }
  

  bool isbst(node*root,int minv=INT_MIN ,int maxv=INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data<=maxv and root->data>=minv and isbst(root->left,minv,root->data) and isbst(root->right,root->data,maxv)){
        return true;
    }
    return false;
  }

int main(){
    node*root=build();
    
    bfs(root);
    inorder(root);
     if(isbst(root)){
        cout<<"the tree is bst";
     }
     else{
        cout<<"not a bst";

     }
    
    return 0;
}