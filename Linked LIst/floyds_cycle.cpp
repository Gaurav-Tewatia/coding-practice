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

void addathead(node*&head,int d){
    if(head==NULL){
        head=new node(d);
        return;
    }
    node*n=new node(d);
    n->next=head;
    head=n;
    return;
}
 bool floyddetection(node*head){
    node*slow=head;
    node*fast=head;
    while(fast!=NULL and fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){ //this condition will come true at some point if the linked list is cyclic in nature
            return true;
        }
    }
    return false;
 }

 void deletion_of_floydcycle(node*&head){
    node*slow=head;
    node*fast=head;
    while(fast!=NULL and fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){         
            slow=head;
            break;
        }
    }
    while(fast==slow){          //through this the fast and slow pointer both arrives at the node from which the cyclation starts
        fast=fast->next;
        slow=slow->next;

    }
    while(slow->next!=fast){            //with this if are trying to make the slow pointer at the previous node of the starting node of the cycle
        slow=slow->next;
    }
    slow->next=NULL;                //and then break the cycle
 }

 void join(node*&head){
    node*temp=head;
    int i=2;
    while(i>0){
        temp=temp->next;
        i--;
    }
    node*c=head;
    while(c->next!=NULL){
        c=c->next;
    }
    c->next=temp;

 }
 int main(){
    node*head;
    addathead(head,1);
    addathead(head,2);
    addathead(head,3);
    addathead(head,4);
    addathead(head,5);
    join(head);
    if(floyddetection(head)){
        cout<<"a floud circle has been detected";
    }
    else{
        cout<<"not found";
    }
    cout<<endl;
    deletion_of_floydcycle(head);
    if(floyddetection(head)){
        cout<<"a floud circle has been detected";
    }
    else{
        cout<<"not found";
    }

    
    
    return 0;
 }
