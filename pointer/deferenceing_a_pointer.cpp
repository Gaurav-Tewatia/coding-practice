#include<iostream>
using namespace std;
int main(){
int x=10;
int *ptr=&x;
cout<<&x<<endl;
cout<<ptr<<endl;
cout<<*ptr<<endl;   //called dereferencing shows the value present at ptr(and ptr represent the address of x) so shows the value present at the address of x which is x itself
cout<<*(&x)<<endl;  //same thing shows the value present at &x (which is nothing but the address of x)
cout<<&(*ptr)<<endl;  //first shows the value of x then shoes the address of x
cout<<*(&ptr)<<endl;  //first shoes the address of ptr then shoes the value present at that address which is the address of x

int * * xxptr=&ptr;    //int * is the data type second * is the syntax used in order to point towards a pointer which holds the address of an variable
cout<<xxptr<<endl;
    return 0;

}