#include<iostream>
using namespace std;

int main(){
   int cnt[64]={0};
   int n;
   cin>>n;
   int k;
   cin>>k;
   int no;
   for(int i=0;i<n;i++){
    cin>>no;
    int j=0;
    while(no>0){
        int last_digit=no&1;
        cnt[j]+=last_digit;
        j++;
        no=no>>1;
    }
   }
   int ans=0;
   int p=1;
   for(int i=0;i<n;i++){
    cnt[i]%=3;
    ans+=cnt[i]*p;
    p=p<<1;
   }
   cout<<ans;
    return 0;
}