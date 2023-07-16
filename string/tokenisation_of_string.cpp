#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char c[100]="Today is a rainy day";
    char *p=strtok(c," ");                  //first pass the  entire string as an argument so that the first token get stored in the fuction
    cout<<p<<endl;
    while(p!=NULL){                         //strtok will keep storing the value of next string till p has null or end of the string means at null character
    p=strtok(NULL," ");                     //Now when the fuction has already stored first token and do not have any string it will go for the next string till the delimeter
    cout<<p<<endl;
    }
                                    // Note:- strtok fuction stored the previous conditin or status of the string that's why when it is being called again and again inside the while loop it starts the tokenization from the end of previous tokenization
    return 0;
}