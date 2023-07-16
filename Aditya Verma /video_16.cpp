#include<iostream>
#include<algorithm>
#include<string>
#include<ctype.h>
using namespace std;

void print(string in , string out){
    if(in.size()==0){
        cout<<out;
        cout<<endl;
        return;
    }

    if(isalpha(in[0])){
        string out1=out;
        string out2=out;
        out1.push_back(toupper(in[0]));
        out2.push_back(tolower(in[0]));
        in.erase(in.begin());
        print(in,out1);
        print(in,out2);
    }
    else{
        string out1=out;
        out1.push_back(in[0]);
        in.erase(in.begin()+0);
        print(in,out1);
    }
}

int main()
{
    string in;
    cin>>in;
    string out="";
    
    print(in ,out);
    
    return 0;
}