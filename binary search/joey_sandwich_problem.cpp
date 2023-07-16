#include<iostream>
using namespace std;

bool speed(int a[],int n, int k,int eaten){
    int count=0;
    
    for(int i=0;i<n;i++){
        int sandwich_eaten=eaten;
        count++;
        if(sandwich_eaten>=a[i]){
            
            if(count>k){
                return false;
            }
        }
       while(sandwich_eaten<a[i]){
           
            sandwich_eaten+=eaten;
            count++;
            if(count>k){
                return false;
            }
       }
       
    }
    return true;

}

int main(){
int n=4;
int a[]={3,6,7,11};
int k=8;
int ans=0;

int s=0;
int e=a[n-1];
while(s<=e){
    int mid=(s+e)/2;
    if(speed(a,n,k,mid)){
        ans=mid;
        e=mid-1;
    }
    else{
        s=mid+1;
    }
}
cout<<ans;
    return 0;
}