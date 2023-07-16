#include<iostream>
using namespace std;
int main(){
int x=4;
int v=9;
cout<<&x;
float y=9.78;
cout<<endl;
cout<<&y;
cout<<endl;
char c='A';  //&c won't work because in cout<<(&ch) '<<' this doesn't work with the & char type instead of the address it returs the character itself
//converted to data type form char type to void type explicitly 
cout<<(void*)&c<<endl;

int *ptr=&x;           //pointer initialisation and declaration
cout<<&x<<endl;
cout<<ptr<<endl;       //both represent the same addresee
ptr=&v;                 //reassigning
cout<<&v<<endl;
cout<<ptr<<endl;

    return 0;
}