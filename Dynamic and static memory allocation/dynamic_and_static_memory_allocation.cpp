#include<iostream>
using namespace std;
int main(){
 int a[10]={0};            //initialization in static memory done during the compilation time address is defined in the symbol table 
 
 cout<<sizeof(a)<<endl;     //tells the size of entire array stored in the static memory
 cout<<a<<endl;
  int n;
  cin>>n;
 int *p=new int[n];    //dynamic allocation, new int[ ]crates an array in heap memory and returns the address which is then stored in the pointer p
 cout<<sizeof(p)<<endl;     //the pointer p is stored in the static memory an have fixed memory in it
 cout<<p<<endl;             //gives you the address of the array stored in heap memory dynamically
 for(int i=0;i<n;i++){
    cin>>p[i];              //store the values in the heap memory in the array created dynamically
 }    
 for(int i=0;i<n;i++){
    cout<<p[i]<<" ";
 }    
 cout<<endl;
 cout<<*p<<endl;           //shows the value present at the first index of the array
  //cout<<*p[2];    this type of statement is invalid
  delete []p;          //deletes the dynamically created array
 
 p=new int[5];           //now pointer p points towards a different array in the heap memory and the previously created array is still there because we haven't deleted that yet this is called memory leak
 cout<<p;                   //shows the address of the new array in the heap memory
    return 0;
}
