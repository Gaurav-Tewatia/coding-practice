#include<iostream>
using namespace std;

int * fun(){
    int a[5]={1,2,3,4,5};     //locally created array in the function fun
    cout<<a<<endl;              //shows the address of the array a
    cout<<a[0]<<endl;           //shoes the first element of the array that is 1
    return a;                   //returns the address of the array a
}
int *func(){
    int *c =new int [5];
    c[0]=2;
    c[1]=3;
    c[2]=4;
    cout<<c<<endl;
    cout<<c[0]<<endl;
    return c;
}

int main(){

    int *b=fun();               //stores the address of the array a also the array has been deleted because the scope of array has been removed means there is no use of array now 
    cout<<b<<endl;              //shows the address of the array a
   // cout<<b[0]<<endl;            //doesn't show anything or shows some garbage valye or show sejment error beacause the array no longer exist
   b=func();                    //re-initialise the pointer b to show the array c;
   cout<<b<<endl;                  //show the address of array c
   cout<<b[0];                  //shows the first element of array c that is 2
    return 0;
}