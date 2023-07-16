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

node* midpoint(node*head){
    if(head==NULL or head->next==NULL){
        return head;
    }
    node*slow=head;
    node*fast=head->next;
    while(fast!=NULL and fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

int main(){
    node*head=input();
    node*mid=midpoint(head);
    print(head);
    cout<<endl;
    cout<<mid->data;
    return 0;
}