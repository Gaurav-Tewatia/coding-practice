#include<iostream>

using namespace std;
void primesieve(int *p){
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
    
}

int main(){
  int p[1000005]={0};
  int n;
  cin>>n;
  primesieve(p);
  for(int i=0;i<n;i++){
    if(p[i]==1){
        cout<<i<<" ";
    }
  }
  

    return 0;
}