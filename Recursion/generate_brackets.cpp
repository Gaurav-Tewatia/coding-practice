#include<iostream>
using namespace std;
void brackets(char *out, int index,int n,int open, int close){
    if(index==2*n){
        out[index]='\0';
        cout<<out<<endl;
    }
    if(open<n){
        out[index]='(';
        brackets(out,index+1,n,open+1,close);

    }
    if(close<open){
        out[index]=')';
        brackets(out,index+1,n,open,close+1);
    }
}
int main(){
    int n;
    cin>>n;
    char output[1000];
    int index=0;

    brackets(output,index,n,0,0);
    return 0;
}