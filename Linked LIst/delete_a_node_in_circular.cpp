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

void insert(node*&head,int d){
    node*n=new node(d);
    n->next=head;
    node*temp=head;
    if(temp!=NULL){
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=n;

    }
    else{
        n->next=n;
    }
    head=n;
}

node* getnode(node*head,int d){
    node*temp=head;
    while(temp->next!=head){
        if(temp->data==d){
            return temp;
        }
    }
    if(temp->data==d){
        return temp;
    }
    return NULL;
}

void deletenode(node*&head,int d){
    node*del=getnode(head,d);
    if(del==NULL){
        return;
    }

    if(head==del){
        head=head->next;
    }
    node*temp=head;
    while(temp->next!=del){
        temp=temp->next;
    }
    temp->next=del->next;
    delete del;
}

void print(node*head){
    node*temp=head;
    while(temp->next!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
    cout<<endl;
}
int main(){
    node*head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    print(head);
    print(head);
    deletenode(head,3);
    print(head);
    print(head);
    return 0;
}