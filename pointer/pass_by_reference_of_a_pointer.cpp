#include<iostream>
using namespace std;
void increment_reference(int *a){   //pass by reference argument is the address of the variabel any changes made are being made in the value present at that address and will reflect even outside the function
    *a+=1;
    cout<<"after the increment value of x is "<<*a<<endl;
}
void increment_value( int a){      //pass by value creates a copy of x any changes made are only reflected in this function an not outside it
    a+=1;
    cout<<"after increment value is "<<a<<endl;
}
int main(){
int x=10;
increment_value(x);   //passes the normal variable
cout<<"after the increment by pass by  value the value of x is "<<x<<endl;
increment_reference(&x);   //passes the address of the variable
cout<<"after the increment by reference the value of of x is "<<x;

    return 0;
}