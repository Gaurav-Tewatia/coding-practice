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

 node* createfromorder(int *in,int *pre,int s,int e){
    static int i=0;
    if(s>e){
        return NULL;
    }
    int index=-1;
    node*root=new node(pre[i]);
    for(int j=s;s<=e;j++){
        if(in[j]==pre[i]){
            index=j;
            break;
        }
    }
    i++;
    root->left=createfromorder(in,pre,s,index-1);
    root->right=createfromorder(in,pre,index+1,e);
    return root;
 }

 int main(){
    int in[]={3,2,8,4,1,6,7,5};
    int pre[]={1,2,3,4,8,5,6,7};
    int n=sizeof(in)/sizeof(int);
    node*root=(createfromorder(in,pre,0,n-1));
    bfs(root);
    return 0;
 }