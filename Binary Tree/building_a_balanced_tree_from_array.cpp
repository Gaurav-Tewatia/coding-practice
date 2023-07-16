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

 node * buildbalancedtree(int a[], int s, int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    node*root=new node(a[mid]);
    root->left=buildbalancedtree(a,s,mid-1);
    root->right=buildbalancedtree(a,mid+1,e);
    return root;
 }

 int main(){
    int a[]={1,2,3,4,5,6,7};
    int n=7;
    node*root=buildbalancedtree(a,0,n-1);
    bfs(root);
    return 0;
 }