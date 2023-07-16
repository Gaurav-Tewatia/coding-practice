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
        return ;
    }
    inorder(root->left);
    cout<<root->data<<",";
    inorder(root->right);
 }

int main(){
    node*root=build();
    inorder(root);
    cout<<endl;
    bfs(root);
    return 0;
}