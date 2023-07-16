#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

void printsubset(string s, string out){
    if(s.size()==0){
        cout<<out;
        cout<<endl;
        return;
        
    }

    string out1=out;
    string out2=out;
    out2.push_back(s[0]);
    s.erase(s.begin());
    printsubset(s,out1);
    
    
    printsubset(s,out2);
}

int main()
{
    string s="ab";

    string out="";
    printsubset(s,out);
    return 0;
}