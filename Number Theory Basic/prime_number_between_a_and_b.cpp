#include<iostream>
using namespace std;
void primesieve(int *p){
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
    p[0]=p[1]=0;
    p[2]=1;
}

int main(){
  int p[1000005]={0};
  primesieve(p);
  int cum[1000005]={0};
  for(int i=1;i<100005;i++){
    cum[i]=cum[i-1]+p[i];
  }
  int q;
  cin>>q;
  while(q--){
    int a,b;
    cin>>a>>b;
    cout<<cum[b]-cum[a-1];
    cout<<endl;
    
  }
    return 0;
}