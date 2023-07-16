#include<iostream>
#include<algorithm>
using namespace std;

bool possible(int painting[],int k,int n, int mid){
    int sum=0,count=1;
    for(int i=0;i<n;i++){
        sum+=painting[i];
        if(sum>mid){
            sum=painting[i];
            count++;
            if(count>k){
                return false;
            }
        }
    }
    return true;
}

int main(){

int k,n;
cout<<"enter number of painters and paintings to draw ";
cin>>k>>n;
int painting[n];
for(int i=0;i<n;i++){
    cin>>painting[i];
}
int sum=0;
int ans=0;
for(int i=0;i<n;i++){
    sum+=painting[i];
}
int s=*max_element(painting,painting+n);
int e=sum;
while(s<=e){
    int mid=(s+e)/2;
    if(possible(painting,k,n,mid)){
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