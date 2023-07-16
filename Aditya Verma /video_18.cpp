#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

void print(int n, string out,int open , int close){
    if(out.size()==n){
        cout<<out;
        cout<<endl;
        return;
    }

    
        string out1=out;
        out1.push_back('1');
        print(n,out1,open+1,close);
    
    
        if(close+1<open ){
        string out2=out;
        out2.push_back('0');
        print(n,out2,open,close+1);}
    
 
}

int main()
{
    int n;
    cin>>n;

    int open=0,close=0;
    string out="";
    print(n,out,open, close);
    
    return 0;
}