#include<iostream>
using namespace std;
int last_occurence(int a[],int n, int key){
     int s=0;
    int e=n-1;
    int ans;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]==key){
            ans=mid;
            s=mid+1;
        
        }
        else if(a[mid]>key){
            e=mid-1;
            
        }
        else 
        s=mid+1;
    }
    return ans;
}
int first_occurence(int a[],int n,int key){
    int s=0;
    int e=n-1;
    int ans;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]==key){
            ans=mid;
            e=mid-1;
        
        }
        else if(a[mid]>key){
            e=mid-1;
            
        }
        else 
        s=mid+1;
    }
    return ans;
}

int main(){
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
cout<<"enter the element ";
int key;
cin>>key;
cout<<first_occurence(a,n,key);
cout<<endl<<last_occurence(a,n,key);
    return 0;
}