#include<iostream>

using namespace std;



 int largest(int b[],int a){
   int largest=b[0];
   
   for(int i=0; i<a; i++){
     if(b[i]>largest)
     largest=b[i];
     
   }
   return largest;

 }
  int smallest(int b[],int a){
   int smallest=b[0];
   
   for(int i=0; i<a; i++){
     if(b[i]<smallest)
     smallest=b[i];
     
   }
   return smallest;

 }
  int main(){
  
   int a;
   cin>>a;
   int b[a];
    for(int i=0;i<a;i++){
  cin>>b[i];
  }
  cout<<largest(b,a)<<endl;
  cout<<smallest(b,a);
   
   
  
    return 0;

}