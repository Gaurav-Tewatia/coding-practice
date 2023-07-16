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

 void reversed(node*&head){
    node*c=head;
    node*prev=NULL;
    node*n;
    while(c!=NULL){
        n=c->next;
        c->next=prev;
        prev=c;
        c=n;
    }
    head=prev;
 }

 node* recursive_reverse(node*&head){      // takes O(n) time and O(1) space better method to reverse a linked list
    if(head->next==NULL or head==NULL){
        return head;
    }
    

        node*shead=recursive_reverse(head->next);
       /* node*temp=shead;               not recommede cause of O(n2) time complexity
        while(temp->next!=NULL){
            temp=temp->next;
        }*/
        // or you can also right like this in the below line
        //node*temp=head->next;
        //or you can also right like this
         head->next->next=head;
        head->next=NULL;
        //temp->next=head;
        
        return shead;
 }

 int main(){
    node*head=input();
    print(head);
    cout<<endl;
   // reversed(head);
    //print(head);
    cout<<endl;
    head=recursive_reverse(head);
    print(head);
    return 0;
 }