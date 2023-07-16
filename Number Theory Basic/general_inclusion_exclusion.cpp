#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int primesieve(int *p,int r,vector<int> &a){
    for(int i=3;i<r;i+=2){
        p[i]=1;

    }
    for(int i=3;i*i<r;i+=2){
        if(p[i]==1){
            for(int j=i*i;j<r;j+=i){
                p[j]=0;
            }
        }
    }
    
    a.push_back(2);
    int cnt=1;
    for(int i=3;i<r;i+=2){
        if(p[i]==1){
            a.push_back(i);
            cnt++;
        }
    }
    return cnt;
}

int setbit(int n){
    int count=0;
    
    while(n>0){
       n=n&(n-1);
       count++;
    }
    return count;
}

int main(){
int r;
cout<<"prime number till "<<endl;
cin>>r;
int p[r];
memset(p,0,sizeof(p));
vector<int> a;
int s=primesieve(p,r,a);
cout<<"prime number are"<<endl;
for(int d:a){
    cout<<d<<" ";
}
cout<<endl;
cout<<"size of vector a ";
cout<<sizeof(a)<<endl;
int t;
cout<<"enter number of test cases"<<endl;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int subset=(1<<s)-1;
    int ans=0;
    for(int i=1;i<=subset;i++){
        int setbits=setbit(i);
        int denom=1;
        for(int j=0;j<=(s-1);j++){
            if(i&(1<<j)){
                denom*=a[j];
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