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

    node*left=lca(root->left,a,b);
    node*right=lca(root->right,a,b);
    if(left!=NULL and right!=NULL){
        return root;
    }
    if(left!=NULL){
        return left;
    }
    return right;
 }

 int search(node*root,int key,int level){
    if(root==NULL){
        return -1;
    }
    if(root->data==key){
        return level;
    }
    int left=search(root->left,key,level+1);
    
    if(left!=-1){
        return left;
    }
    return search(root->right,key,level+1);
 }

 int finddistance(node*root,int a,int b){
    node*lc=lca(root,a,b);
    int l1=search(lc,a,0);
    int l2=search(lc,b,0);
    return l1+l2;

 }

 int main(){
    node*root=buildtree();
    cout<<finddistance(root,6,9);
    return 0;
 }