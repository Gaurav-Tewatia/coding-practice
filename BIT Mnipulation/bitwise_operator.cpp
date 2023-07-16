#include<iostream>
using namespace std;

int main(){
int a=1;
int b=4;
cout<<(a&b)<<endl;  //and of 1(001) and 4(100) gives us 000(0)
cout<<(a|b)<<endl;  //or of 1 and 4 gives us 101(5)
cout<<(a^b)<<endl;  //xor of 1 and 4 gives us 101(5) , xor is also known as odd one detector
cout<<(~a)<<" "<<(~b)<<endl;    //not of 001 is 110(-2) and of 0100 is 1011;

int n;
cin>>n;
int no;
int ans=0;
for(int i=0;i<n;i++){
    cin>>no;
    ans=ans^no;
}
cout<<ans<<endl;      //to find the odd number of existence of a number in a sequence like 2,3,4,6,3,4,2  ans is 6
    cout<<(0^2);      //xor of any number with 0 gives the number itself
    return 0;
}