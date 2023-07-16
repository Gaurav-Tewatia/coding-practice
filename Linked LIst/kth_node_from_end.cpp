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

node* kthnode(node*head,int k){
    node*temp=head;
    while(k>0){
        temp=temp->next;
        k--;
    }
    node*slow=head;
    while(temp!=NULL){
        slow=slow->next;
        temp=temp->next;
    }
    return slow;
}

int main(){
    node*head;
    head=input();
    print(head);
    node*k=kthnode(head,3);
    cout<<endl;
    cout<<k->data;
    return 0;
}