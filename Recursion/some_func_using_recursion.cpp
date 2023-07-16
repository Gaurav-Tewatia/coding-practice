#include<iostream>
using namespace std;

int power(int n, int p){
    if(p==1){
        return n;
    }
    return n*power(n,p-1);
}

int multiply(int a, int b){
    if(a<b){
        return multiply(b,a);
    }

    if(b==0){
        return 0;
    }
    return (a+multiply(a,b-1));
}

int binary(int a[],int k,int s, int e){
    int mid=(s+e)/2;
    if(a[mid]==k){
        return mid;
    }
    if(k>a[mid]){
        return binary(a,k,mid+1,e);
    }
    else{
        return binary(a,k,s,mid-1);
    }
    return 0;
}

int main(){
    int s;
    cin>>s;
    switch(s){
        case 1: cout<<"enter the number whose power needs to be calculated"<<endl;
                int n;
                cin>>n;
                cout<<"enter the power"<<endl;
                int p;
                cin>>p;
                cout<<power(n,p);
                break;
        case 2: cout<<"enter the two number whoes multiplication is needed "<<endl;
                int a, b;
                cin>>a>>b;
                cout<<multiply(a,b);
                break;
        case 3: int arr[]={1,2,3,4,5,6,7,8,9};
                int k;
                cout<<"enter the key needs to be find "<<endl;
                cin>>k;
                int s=0;
                int e=8;
                cout<<binary(arr,k,s,e);
                break;

    }
        
    
 return 0;   
}