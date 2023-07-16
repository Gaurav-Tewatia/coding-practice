w#include<iostream>
#include<string>  //file to include in order to use string
using namespace std;
int main(){
    //intializing a string 
    string s1("hello world"); //or you can also use string s1="hello world"
    cout<<s1<<endl;

    string s0(s1); //initializing another string with the help of another string
    cout<<s0<<endl;

    char a[]= {'s','d','g','g','\0'};
    string s3(a); //initializing a string with a character array
    cout<<s3<<endl;
    
    cout<<"length of the string is "<<s3.length()<<endl; //to fing the legth of a string

    //to empty the string
    s3.clear();
    cout<<s3<<endl;
    //to check if the string is empty or not
    if(s3.empty())
    cout<<"string is empty baby"<<endl;
    cout<<"length of the string after clearing the string is "<<s3.length()<<endl;
    //to update the string
    s3.append("I am the best baby");
    cout<<s3<<endl;
    s3+="ooo lala re oo laala re baby";
    cout<<s3<<endl;
    s0="apple"; //reinitializing the strings    
    cout<<s0.compare(s1)<<endl; // comaparing the two strings
     cout<<s0[0]<<endl; //to print the a particular index of a string
     s0="I am the best person in the world";
     int index=s0.find("person");
     cout<<index<<endl;
     string word ="person";
     int len=word.length();
     s0.erase(index,len+1); //erasing a particular word from the string by mentioning the starting point as well as how much needs to be erased after that
     cout<<s0<<endl;
     s1="Mango";
     for(int i=0;i<s1.length();i++) //iterate over the entire string
        cout<<s1[i]<<'.';
        cout<<endl;
     for(string::iterator/*or auto*/ it=s1.begin();it!=s1.end();it++){  //using of the iterater s1.begin() points towards the start of the string and s1.end() towards the end of the string
        cout<<(*it)<<',';
     }
     cout<<endl;
     for(auto /* or char*/c:s1) //auto data type automatically detect which data type is to be used
        cout<<c<<':';
     return 0;
}
