#include<iostream>
#include<cstring>
using namespace std;


char *mystrtok(char *c,char delim){
    static char *input=NULL;


    if(c!=NULL){
        input=c;
    }


    if(input==NULL){
        return NULL;
    }

    
    
    char *output = new char[strlen(input)+1];
    int i=0;
    for(; input[i]!='\0';i++){
        if(input[i]!=delim){
            output[i]=input[i];
        }
        else{
            input=input+i+1;
            output[i]='\0';
            return output;
        }

    }
    input=NULL;
    output[i]='\0';
    return output;
}
int main(){
    char c[100]="Hello World my name is gaurav";
    char *p=mystrtok(c,' ');  
    cout<<p<<endl;
    while(p!=NULL){
        p=mystrtok(NULL,' ');
        cout<<p<<endl;
    }
    return 0;
}