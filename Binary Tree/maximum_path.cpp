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

 pair<int,int> maxsum(node*root){
    pair<int,int> p;
    if(root==NULL){
        p.first=p.second=0;
        return p;
    }
    pair<int,int> left=maxsum(root->left);
    pair<int,int> right=maxsum(root->right);

    int op1=root->data;
    int op2=left.first+root->data;
    int op3=right.first+root->data;
    int op4=left.first+right.first+root->data;

    int current_sum=max(op1,max(op2,max(op3,op4)));

    p.first=max(left.first,max(right.first,0))+root->data;
    p.second=max(left.second,max(right.second,current_sum));
    return p;
 }

 int main(){
    node*root=buildtree();
    pair<int,int> p=maxsum(root);
    cout<<p.first<<" "<<p.second;
    return 0;
 }