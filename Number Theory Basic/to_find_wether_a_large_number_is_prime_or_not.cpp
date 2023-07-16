#include<iostream>
#include<vector>

using namespace std;
vector<int> primesieve(int *p){
    for(int i=3;i<=1000000;i+=2){           //make all the 0dd number as prime
        p[i]=1;                             //or you can sumply write memset(p,1,sizeof(p))
    }
    for(int k=3;k*k<=1000000;k+=2){
        if(p[k]==1){                            //if the odd number is prime then mark all the multiple of it as non-prime
            for(int j=k*k;j<=1000000;j+=k){
                p[j]=0;
            }
        }
    }
    p[0]=p[1]=0;
    p[2]=1;
    vector<int> ans;
    ans.push_back(2);
    for(int i=3;i<1000000;i+=2){
        if(p[i]==1){
            ans.push_back(i);
        }
    }
    return ans;
    
}
bool isprime(int n,vector<int> &prime,int p[]){
    if(n<1000000){
        return p[n]==1?true:false;
    }
    for(long long int i=0;prime[i]*(long long)prime[i]<n;i++){
        if(n%prime[i]==0){
            return false;
        }
    }
    return true;
}
int main(){
    int p[1000005]={0};
    vector<int> primes=primesieve(p);
    long long int n;
    cin>>n;
    if(isprime(n,primes,p)){
        cout<<"is a prime number";
    }
    else{
        cout<<"is not a prime number";
    }
    return 0;
}