#include<iostream>
using namespace std;

bool possible(int books[],int n, int m, int pages){

  int studentused=1;
  int reading=0;
  for(int i=0;i<n;i++){
    if(reading+books[i]>pages){
        reading=books[i];
        studentused++;
        if(studentused>m){
            return false;
        }
    }
    else{
        reading+=books[i];
    }
  }
  return true;
}

int main(){

    int books[]={10,20,30,40};
    int n=4;
    int  m=2;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=books[i];
    }
    int s=books[n-1];
    int e=sum;
    int ans=0;
    while(s<=e){
        int mid=(s+e)>>1;
        bool a=possible(books,n,m,mid);
        if(a){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
            
        }
    }
    cout<<ans;
}