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

 pair<int,bool> heighbalancedtree(node*root){
    pair<int,int> p;
    if(root==NULL){
        p.first=0;
        p.second=false;
        return p;
    }
    pair<int,bool> lf=heighbalancedtree(root->left);
    pair<int,bool> rt=heighbalancedtree(root->right);

    p.first=max(lf.first,rt.first)+1;
    p.second=bool((lf.second and rt.second )and (abs(lf.first-rt.first)<=1));
    return p;

 }

 int main(){
        node*root=buildtree();
        bfs(root);
        cout<<endl;
        pair<int,int> p=heighbalancedtree(root);
        cout<<p.first<<endl;
        if(p.second){
            cout<<"its balanced tree";
        }
        else{
            cout<<"its not a balanced tree";
        }
    return 0;
 }