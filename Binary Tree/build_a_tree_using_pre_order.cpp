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
    void printin(node*root){
        if(root==NULL){
            return;
        }
        printin(root->left);
        cout<<root->data<<" ";
        printin(root->right);
    }

    void printpo(node*root){
        if(root==NULL){
            return ;
        }
        printpo(root->left);
        printpo(root->right);
        cout<<root->data<<" ";

    }




int main(){
    node*root=buildtree();
    print(root);
    cout<<endl;
    printin(root);
    cout<<endl;
    printpo(root);
    return 0;
}