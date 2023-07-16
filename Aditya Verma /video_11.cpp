#include<iostream>
#include<algorithm>
using namespace std;

void hanoi(int n,char s, char d, char h){
    if(n==0){
        return;
    }

    hanoi(n-1,s,h,d);
    cout<<"move "<<n<<" from "<<s<<" to "<<d<<endl;
    hanoi(n-1,h,d,s);
}

int main()
{
    char a, b, c;
    int n;
    cin>>n;
    hanoi(n,'s','d','h');
    return 0;
}