#include<iostream>
using namespace std;
void permut(char *in,int i){
    if(in[i]=='\0'){
        cout<<in<<",";
    }
    for(int j=i;in[j]!='\0';j++){
        swap(in[i],in[j]);
        permut(in,i+1);
        //backtracking
        swap(in[i],in[j]);
    }
}
int main(){
        char in[10];
        cin>>in;
        permut(in,0);
    return 0;
}