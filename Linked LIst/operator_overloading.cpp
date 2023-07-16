#include<iostream>
using namespace std;

class node{

    public:
    int data;
    node*next;

    node(int d){
        data=d;
        next=NULL;
    }
    
};
void insertathead(node*&head , int d){
    if(head==NULL){
        head=new node(d);
        head->next=NULL;
        return;
    }
    node* n=new node(d);
    n->next=head;
    head=n;

}

node* input(){
    int n;
    cin>>n;
    node*temp=NULL;
    while(n!=-1){
        insertathead(temp,n);
        cin>>n;
    }
    return temp;
}

void print(node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

ostream & operator <<(ostream&os, node*head){
    print(head);
    return os;
}

istream & operator >>(istream &is, node*&head){
    head=input();
    return is;
}

int main(){
    node*head;
    node*head2;
    cin>>head>>head2;
    cout<<endl;
    cout<<head<<head2;
    

    return 0;
}