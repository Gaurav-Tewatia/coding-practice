#include<iostream>

using namespace std;


bool possible(int stall[],int cows, int n, int separation){
    int cowslast=stall[0];
    int count=1;
    for(int i=1;i<n;i++){
        if(stall[i]-cowslast>=separation){
            cowslast=stall[i];
            count++;
            if(count==cows){
                return true;
            }
        }
    }
    return false;
}

int main(){
   int stall[]={1,2,4,8,9};
   int cows=3;
   int n=5;
   int s=0;
   int ans=0;
   int e=stall[n-1]-stall[0];
   while(s<=e){
    int mid=(s+e)>>1;
    bool a=possible(stall,cows,n,mid);
    if(a){
        ans=mid;
        s=mid+1;
    }
    else{
        e=mid-1;
    }
   }
   cout<<ans;

    return 0;
}