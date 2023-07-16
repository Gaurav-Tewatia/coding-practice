#include<iostream>
using namespace std;

void remove_duplicate(char a[]){
    int s=strlen(a);
    int j=0;
    for(int i=1;i<s;i++){
        if(a[j]!=a[i]){
            j++;
            a[j]=a[i];

        }
        
    }
    a[j+1]='\0';
}
void display(char a[]){
    for(int i=0;i<strlen(a);i++){
        cout<<a[i];
    }
}

int main(){
    char a[100];
    cin.getline(a,100);
    remove_duplicate(a);
    display(a);
    return 0;
}
