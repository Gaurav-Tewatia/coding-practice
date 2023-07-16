#include<iostream>
using namespace std;
int main(){
    char ch[10];
    for(int i=0;i<10;i++)
    cin>>ch[i];
    int s=1;
    int i=0;
    int j=10-1;
    while(i<j){
        if(ch[i]!=ch[j]){
            cout<<"not a palindrome string";
            s=0;
            break;
        }
    
         else{
        i++;
        j--;
         }
     } if(s==1)
    cout<<"a palindrome string ";
    return 0;
}