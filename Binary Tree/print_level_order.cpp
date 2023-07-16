#include<iostream>
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
        node* root=new node(n);
        root->left=buildtree();
        root->right=buildtree();
        return root;
    }

    void print(node* root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        print(root->left);
        print(root->right);
   
    }

    int height(node*root){
        if(root==NULL){
            return 0;
        }
        int ls=height(root->left);
        int rs=height(root->right);
        return max(ls,rs)+1;
    }

    void printkth(node*root,int k){
        if(root==NULL){
            return;
        }
        if(k==1){
            cout<<root->data<<" ";
            return;
            
        }
        printkth(root->left,k-1);
        printkth(root->right,k-1);
    }
    void printalllevel(node*root){
       
        int h=height(root);
        for(int i=1;i<=h;i++){
            printkth(root,i);
            cout<<endl;
        }
    }
   




int main(){
    node*root=buildtree();
    print(root);
    cout<<endl;

    cout<<height(root);
    cout<<endl;
    printkth(root,3);
    cout<<endl;
    printalllevel(root);
    
    return 0;
}