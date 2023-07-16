#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void remove(char *s){
    int i=0;
    int len=strlen(s);
    for(int j=1;j<len;j++){
        if(s[i]!=s[j]){
            i++;
            s[i]=s[j];
        }
        
    }
    s[i+1]='\0';
}
int main(){
    char a[1000];
    cin.getline(a,1000);
    remove(a);
    cout<<a;
    return 0;
}