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
    node*root;
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

 pair<node*,node*> linkedlist(node*root){
    pair<node*,node*> p;
    if(root==NULL){
        p.first=p.second=NULL;
        return p;
    }
    if(root->left==NULL and root->right==NULL){
        p.first=p.second=root;
        return p;
    }
    if(root->left!=NULL and root->right==NULL){
        pair<node*,node*> linkedleft=linkedlist(root->left);
        linkedleft.second->right=root;
        p.first=linkedleft.first;
        p.second=root;
        return p;
    }
    if(root->left==NULL and root->right!=NULL){
        pair<node*,node*> linkedright=linkedlist(root->right);
        root->right=linkedright.first;
        p.first=root;
        p.second=linkedright.second;
        return p;
    }
   
        pair<node*,node*> linkedleft=linkedlist(root->left);
        pair<node*,node*> linkedright=linkedlist(root->right);
        linkedleft.second->right=root;
        root->right=linkedright.first;
        p.first=linkedleft.first;
        p.second=linkedright.second;
        return p;
    
 }

 int main(){
    node*root=build();
    
    bfs(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
      pair<node*,node*> p=linkedlist(root);
      node*temp=p.first;
      while(temp!=NULL){
        cout<<temp->data<<",";
        temp=temp->right;
      }
    
    return 0;
}