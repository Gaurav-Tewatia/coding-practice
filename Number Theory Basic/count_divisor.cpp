#include<iostream>
#include<vector>
using namespace std;
vector<int> primesieve(int *p){

    p[0]=p[1]=0;
    for(int i=3;i<1000005;i+=2){
        p[i]=1;
    }
    for(int i=3;i*i<1000005;i+=2){
        if(p[i]==1){
            for(int j=i*i;j<1000005;j+=i){
                p[j]=0;
            }
        }
    }
    vector<int> prime;
    prime.push_back(2);
    for(int i=3;i<1000005;i+=2){
        if(p[i]==1){
            prime.push_back(i);
        }
    }
    return prime;
}
int divisors(int n,vector<int> &primes){
    int i=0;
    int cnt=0;
    int ans=1;
    while(primes[i]*primes[i]<=n){
        if(n%primes[i]==0){
            cnt=0;
            while(n%primes[i]==0){
            n=n/primes[i];
            cnt++;
            }
        }
        ans=ans*(cnt+1);
        i++;

    }
    if(n!=1){
        ans=ans*2;
    }
    return ans;
}
int main(){
    int p[1000005]={0};
    vector<int> primes=primesieve(p);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int divisor=divisors(n,primes);
        cout<<divisor<<endl;
    }
    return 0;
}