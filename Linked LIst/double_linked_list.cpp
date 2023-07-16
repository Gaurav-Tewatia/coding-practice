#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node*prev;
    node(int d){
        data=d;
        next=NULL;
        prev=NULL;
    }
};

void addathead(node*&head,int d){
    if(head==NULL){
        head=new node(d);
        return;
    }

    node*n=new node(d);
    n->next=head;
    n->prev=NULL;
    head->prev=n;
    head=n;
}

node* input(){
    node*temp=NULL;
    int n;
    cin>>n;
    while(n!=-1){
        addathead(temp,n);
        cin>>n;
    }
    return temp;
}

void addattail(node*&head,int d){
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new node(d);
}

void addatmiddle(node*&head,int d,int p){
    int jump=1;
    node*temp=head;
    while(jump<=p-1){
        temp=temp->next;
        jump++;
    }
    node*n=new node(d);
    n->next=temp->next;
    n->prev=temp;
    temp->next=n;
    n->next->prev=n;
}

void deleteattail(node*&head){
    node*temp=head;
    node*prev=NULL;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    delete temp;
    prev->next=NULL;
}

void deleteatmiddle(node*&head,int p){
    node*temp=head;
    node*pre=NULL;
    while(p>1){
        pre=temp;
        temp=temp->next;
        p--;
    }
    pre->next=temp->next;
    temp->next->prev=pre;
    delete temp;

}

void print(node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    
    }
    cout<<endl;
}

int main(){
    node*head=input();
    print(head);
    addattail(head,0);
    print(head);
    addatmiddle(head,0,3);
    print(head);
    deleteattail(head);
    print(head);
    deleteatmiddle(head,3);
    print(head);
    return 0;
}