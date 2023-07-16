#include<iostream>


using namespace std;


int setbit(int n){
    int count=0;
    
    while(n>0){
       n=n&(n-1);
       count++;
    }
    return count;
}

int main(){
int p[]={2,3,5,7,11,13,17,19};
int t;
cout<<"enter number of test cases"<<endl;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int subset=(1<<8)-1;
    int ans=0;
    for(int i=1;i<=subset;i++){
        int setbits=setbit(i);
        int denom=1;
        for(int j=0;j<=7;j++){
            if(i&(1<<j)){
                denom*=p[j];
            }
        }
        if(setbits&1){
            ans+=n/denom;
        }
        else{
            ans-=n/denom;
        }
    }
    cout<<ans<<endl;
}
    return 0;
}