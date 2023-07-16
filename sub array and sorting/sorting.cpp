#include<iostream>
#include<algorithm>
using namespace std;
bool compare(int a, int b){
    cout<<"comapare "<<a<<" and "<<b<<endl;
    return b>a;
}


void insertion_sort(int a[],int n){
    for(int i=1; i<=n-1;i++){
        int e=a[i];
        int j=i-1;
        while(j>=0 and a[j]>e){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=e;
    }
     for(int i=0;i<n;i++){
        cout<<a[i]<<"  ";
    }
}
void bubble_sort(int a[],int n){
    
    for(int i=1; i<=n-1;i++){
        for(int j=0;j<=n-1-i;j++){
            if(a[j]>a[j+1])
            swap(a[j],a[j+1]);
        }
        
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<"  ";
    }
}

void selection_sort(int a[],int n){
   
    for(int i=0;i<n-1;i++){
       int s=i;
       
        
        for(int j=i;j<n;j++){
            
            if(a[j]<a[s])
             s=j; 
        }
        swap(a[i],a[s]);
        
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<"  ";
    }
}

int binary(int n,int b,int a[]){
int s = 0;
int e = n-1;
while(s<=e){
    int mid = (s+e)/2;
    if(a[mid]==b){
        cout<<"elment found at the ith ";
    return mid;}
    

    else if(a[mid]>b)
    e=mid-1;
    else
    s=mid+1;
}return -1;
}


int main(){
int n,b;
char ch;
cout<<"enter number of elements you want in the array "<<endl;
cin>>n;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
cout<<endl;
cout<<"enter your choice "<<endl;
cin>>ch;
 switch(ch){
     case 'b' : cout<<"enter the element to be found ";
                cin>>b;
                cout<<binary(n,b,a);
                break;
    case  's' : selection_sort(a,n);  
                break;
    case  'u' : bubble_sort(a,n);  
                break;
    case  'i' : insertion_sort(a,n);
                break;
    case  't' : sort(a, a+n, compare);
                 for(int i=0;i<n;i++){
                  cout<<a[i]<<"  ";
                  }
                break;         
    default   : cout<<"wrong selection";        
 }
   return 0;
}