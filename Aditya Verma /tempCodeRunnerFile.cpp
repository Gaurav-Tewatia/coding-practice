#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    string s="A";
    for(auto c:s){
        cout<<(int)c<<endl;
        cout<<c-'a'<<endl;
    }
    cout<<(int)'a'<<endl;
    cout<<(int)'A'<<endl;
    cout<<endl;
    
    return 0;
}