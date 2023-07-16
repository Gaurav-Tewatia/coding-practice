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

 void rightview(node*root,int level,int &maxlevel){
    if(root==NULL){
        return;
    }
    if(maxlevel<level){
        cout<<root->data<<" ";
        maxlevel=level;
        
    }
    rightview(root->right,level+1,maxlevel);
    rightview(root->left,level+1,maxlevel);
 }

 int main(){
    int maxlevel=-1;
    node*root=buildtree();
    rightview(root,0,maxlevel);
    return 0;
 }