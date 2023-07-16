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

 void printatlevelk(node*root,int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return ;
    }
    printatlevelk(root->left,k-1);
    printatlevelk(root->right,k-1);
 }

 int printatdistanceofk(node*root,node*target,int k){
    if(root==NULL){
        return -1;
    }
    if(root==target){
        printatlevelk(target,k);
        return 0;
    }

    int dl=printatdistanceofk(root->left,target,k);
    if(dl!=1){
        if(dl+1==k){
            cout<<root->data<<" ";
        }
        else{
            printatlevelk(root->right,k-2-dl);
        }
        return dl+1;

    }

    int dr=printatdistanceofk(root->right,target,k);
    if(dr!=1){
        if(dr+1==k){
            cout<<root->data<<" ";
        }
        else{
            printatlevelk(root->left,k-2-dr);
        }
        return dr+1;
    }

 }

 int main(){
    node*root=buildtree();
    node*target=root->left->left;
    printatdistanceofk(root,target,2);
    return 0;
 }