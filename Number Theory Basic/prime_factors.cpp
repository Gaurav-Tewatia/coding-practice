#include<iostream>
#include<vector>
using namespace std;
vector<int> primesieve(int *p){

    p[0]=p[1]=0;
    for(int i=3;i<1000005;i+=2){
        p[i]=1;
    }
    for(int k=3;k*k<1000005;k+=2){
        if(p[k]==1){
            for(int j=k*k;j<1000005;j+=k){
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
vector<int> primefactors(int n,vector<int> &primes){
    int i=0;
    vector<int> factors;
    factors.clear();
    while(primes[i]*primes[i]<=n){
        if(n%primes[i]==0)
        factors.push_back(primes[i]);
        while(n%primes[i]==0){
            n=n/primes[i];
        }
        i++;

    }
    if(n!=1){
        factors.push_back(n);
    }
    return factors;
}
int main(){
    int p[1000005]={0};
    vector<int> primes=primesieve(p);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> factors=primefactors(n,primes);
        int t=factors.size();
        for(int i=0;i<t;i++){
            cout<<factors[i]<<endl;
        }
    }
    return 0;
}