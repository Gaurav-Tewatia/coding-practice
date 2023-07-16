#include<iostream>
using namespace std;
void filterchar(int n, char a[]){
    int j=0;
    while(n>0){
        int last=(n&1);
        if(last){
            cout<<a[j];
        }
        j++;
        n=n>>1;
    }
    cout<<endl;

}

void subset(char a[],int n){
    for(int i=0;i<(1<<n);i++){
        filterchar(i,a);
    }
}

int main(){
    int n;
    cin>>n;
  char a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  subset(a,n);
    return 0;
}