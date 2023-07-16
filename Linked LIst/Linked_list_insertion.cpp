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

int length(node*head){
    int cnt=0;
    while(head->next!=NULL){
        head=head->next;
        cnt++;
    }
    return cnt;
}

void insertattail(node*&head,int d){
    if(head==NULL){
        insertathead(head,d);
        return;
    }
    else{
        node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
       temp->next=new node(d);
        
    }
}

void insertatmiddle(node*&head,int d,int p){
    if(head==NULL or p==0){
        insertathead(head,d);
        return;
    }
    if(p>length(head)){
        insertattail(head,d);
    }
    else{
        node*temp=head;
        int jump=1;
        while(jump<=p-1){
            temp=temp->next;
            jump++;
        }
        node*n=new node(d);
        n->next=temp->next;
        temp->next=n;
    }
}

void deleteathead(node*&head){
    if(head==NULL){
        return;
    }
    node*temp=head->next;
    delete head;
    head=temp;
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
    if(p>length(head)){
        deleteattail(head);
        return;
    }
    else if(p==0){
        deleteathead(head);
        return;
    }
    else{
        int jump=1;
        node*temp=head;
        node*prev=head;
        while(jump<=p-2){
            prev=prev->next;
            temp=temp->next;
            jump++;
        }
        temp=temp->next;
        prev->next=temp->next;
        delete temp;
    }
}

void print(node*head){
    while(head!=NULL){
    cout<<head->data<<" ";
    cout<<endl;
    head=head->next;
    }
    return ;
}

bool search(node*head,int key){
    node*temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

bool recursivesearch(node*&head,int key){
    if(head==NULL){
        return false;
    }
     if(head->data==key){
        return true;
     }
     else{
        return recursivesearch(head->next,key);
     }
}

node* input(){
    int n;
    
    node*head=NULL;
    while(cin>>n){
        insertathead(head,n);
        
    }
    return head;
}

int main(){
    
    node*head=NULL;
    insertathead(head,5);
    insertathead(head,2);
    insertathead(head,1);
    insertathead(head,0);
    cout<<"at normal"<<endl;
    print(head);
    cout<<endl;
    cout<<"after inserting at middle"<<endl;
    insertatmiddle(head,4,3);

    print(head);
    cout<<endl;
    insertattail(head,7);
    cout<<"after inserting at tail"<<endl;
    print(head);
    deleteathead(head);
    cout<<"after deleting at head"<<endl;
    cout<<endl;
    print(head);
    cout<<endl;
    cout<<"after deleting at tail"<<endl;
    deleteattail(head);
    cout<<endl;
    print(head);
    cout<<endl;
    cout<<"after deleteing at middle"<<endl;
    deleteatmiddle(head,3);
    print(head);
    cout<<endl;
    int key;
    cin>>key;
    if(search(head,key)){
        cout<<"element found";
    }
    else{
        cout<<"element not found";
    }

    cout<<endl;
    if(recursivesearch(head,key)){
        cout<<"element found";
    }
    else{
        cout<<"element not found";
    }
    cout<<endl;
    node*oyo=input();
    print(oyo);

    return 0;

}