#include<iostream>
using namespace std;
void subsequence(char *a,char *o, int i, int j){
    if(a[i]=='\0'){
        o[j]='\0';
        cout<<o<<endl;
        return;
    }
    o[i]=a[i];
    subsequence(a,o,i+1,j+1);
    subsequence(a,o,i+1,j);

}
int main(){
        char a[]="abc";
        char o[10];
        subsequence(a,o,0,0);
    return 0;
}