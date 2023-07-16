#include<iostream>
using namespace std;
char keypad[][10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUv","WXYZ"};
void generate_names(char *input, char *output, int i, int j){
    if(input[i]=='\0'){
        output[j]='\0';
        cout<<output<<endl;
        return;
    }
    int digit=input[i]-'0';
    if(digit==0 or digit==1){
        generate_names(input,output,i+1,j);
    }
    for(int k=0;keypad[digit][k]!='\0';k++){
        output[j]=keypad[digit][k];
        generate_names(input,output,i+1,j+1);
    }
    return;
}
int main(){
    char input[10];
    cin>>input;
    char output[100];
    generate_names(input,output,0,0);

    return 0;
}