#include<iostream>
using namespace std;
void string_generation(char *in, char *op,int i, int j){
    if(in[i]=='\0'){
        op[j]='\0';
        cout<<op<<endl;
        return;
    }
    int digit=in[i]-'0';
    char ch=digit+'A'-1;
    op[j]=ch;
    string_generation(in,op,i+1,j+1);
    if(in[i+1]!='\0'){
        int second_digit=in[i+1]-'0';
        int n=digit*10+second_digit;
        if(n<=26){
            ch=n+'A'-1;
        op[j]=ch;
        string_generation(in,op,i+2,j+1);
        }
    }
}
int main(){
    char in[100];
    char output[1000];
    cin>>in;
    string_generation(in,output,0,0);

    return 0;
}