#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int a[1000005]={0};
    int pre[1000005];
    
    pre[0]=1;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(pre,0,sizeof(pre));
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
            
            sum=(sum+n)%n;
            pre[sum]++;


        }
        long long int ans=1;
        for(int i=0;i<n;i++){
            
            long long int p=pre[i];
            ans+=p*(p-1)/2;
        }
         cout<<ans;
        
    }
   
    return 0;
}