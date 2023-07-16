#include<iostream>
using namespace std;

bool possible(int cook[],int n, int p, int time){
   int count=0;
    for(int i=0;i<n;i++){
        int number=1;
        int t=0;
        while(t<=time){
            t+=number*cook[i];
            if(t<=time)
             count++;
            
            number++;
            if(count>=p){
                return true;
            }
        }
    }
    return false;
}

int main(){
  
  int p;
  cout<<"enter number of paratha ";
  cin>>p;
  int n;
  cout<<"\n enter number of cooks ";
  cin>>n;
  int cook[n];
  cout<<endl;
  cout<<"enter there rank ";
  for(int i=0;i<n;i++){
    cin>>cook[i];
  }
  int s=0;
  int ans=0;
  int e=0;
  for(int i=1;i<=p;i++){
    e+=i*(*min_element(cook,cook+n));
  }
  while(s<=e){
     int mid=(s+e)/2;
     if(possible(cook,n,p,mid)){
        ans=mid;
        e=mid-1;
     }
     else{
        s=mid+1;
     }
  }
  cout<<"minimum time is "<<ans;

    return 0;
}