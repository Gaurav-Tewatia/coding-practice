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

node* merge(node*a,node*b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }

    node*c;
    if(a->data <= b->data){
        c=a;
        c->next=merge(a->next,b);
    }
    else{
        c=b;
        c->next=merge(a,b->next);
    }
    return c;
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

node* mergesort(node*head){
    if(head==NULL or head->next==NULL){
        return head;
    }

    node* mid=midpoint(head);
    node*a =head;
    node*b= mid->next;
    mid->next=NULL;

    a=mergesort(a);
    b=mergesort(b);

    node*c=merge(a,b);
    return c;

}

int main(){
    node* a;
    node* b;
    a=input();
    b=input();
    node*sorted = merge(a,b);
    print(sorted);

    cout<<endl;
    cout<<"enter the list that needs to be sorted using mergesort";
    node*head=input();

    head=mergesort(head);
    print(head);

    return 0;

}