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

 void print(node*root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
 }

 int height(node*root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
 }
 int count(node*root){
    if(root==NULL){
        return 0;
    }
    return root->data+count(root->left)+count(root->right);
 }

 //sum of all nodes in a tree
 int sum(node*root){
    if(root==NULL){
        return 0;
    }
    return root->data+sum(root->left)+sum(root->right);
 }
 

 //print the tree in inorder

 void printinorder(node*root){
    if(root==NULL){
        return;
    }
    printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);
 }

 //print the tree in post order or bottom approack order

 void printpostorder(node*root){
    if(root==NULL){
        return ;
    }

    printpostorder(root->left);
    printpostorder(root->right);
    cout<<root->data<<" ";
 }

 void printatkth(node*root, int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return ;
    }
     printatkth(root->left,k-1);
     printatkth(root->right,k-1);
 }

 void printall(node*root){
    int h=height(root);
    for(int i=1;i<=h;i++){
        printatkth(root,i);
        cout<<endl;
    }
 }

 void bfs(node*root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node*f=q.front();
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

 
 void bfslevel(node*root){
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


 int diameter(node*root){
    if(root==NULL){
        return 0;
    }
    int h=height(root->left);
    int h1=height(root->right);
    int op1=h+h1;
    int op2=diameter(root->left);
    int op3=diameter(root->right);
    return max(op1,max(op2,op3));
 }
//optimsed way ot find the height and diameter of the tree bottom down approach time complexity of O(N)
 pair<int,int> fastdiameter(node*root){
    pair<int,int> p;
    if(root==NULL){
        p.first=p.second=0;
        return p;
    }
    pair<int,int> pl=fastdiameter(root->left);
    pair<int,int> pr=fastdiameter(root->right);

    p.first=max(pl.first,pr.first)+1;
    p.second=max((pl.first+pr.first),max(pl.second,pr.second));
    return p;
 }

 

 int main(){

    node*root=buildtree();
    print(root);
    cout<<endl;
    cout<<"height of the tree is "<<height(root)<<endl;
    cout<<"count of the tree is "<<count(root)<<endl;
    cout<<"sum of all the node in the tree is "<<sum(root)<<endl;
    cout<<"print the tree in in-order : "<<endl;
    printinorder(root);
    cout<<endl;
    cout<<"print the tree in post-order : "<<endl;
    printpostorder(root);
    cout<<endl;
    cout<<"elements at the kth level of the tree are : ";
    printatkth(root,3);
    cout<<endl;
    cout<<"print of all level of the tree are :"<<endl;
    printall(root);
    cout<<endl;
    cout<<"bfs of the tree is: "<<endl;
    bfs(root);
    cout<<endl;
    cout<<"bfs level of the tree is :"<<endl;
    bfslevel(root);
    cout<<endl;
    cout<<"diameter of the tree is : "<<diameter(root)<<endl;
    pair<int,int>p=fastdiameter(root);
    cout<<"height of the tree is : "<<p.first<<endl;
    cout<<"diamter of the tree is : "<<p.second<<endl;
    return 0;
 }