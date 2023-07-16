#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


bool solve(string a, string b){
    if(a.compare(b)==0)
    return true;

    if(a.length()<=1)
    return false;

    int n=a.length();

    bool flag=false;
    for(int i=1;i<n;i++){
        bool cond1=(solve(a.substr(0,i),b.substr(0,i)) and solve(a.substr(i,n-i),b.substr(i,n-i)));
        bool cond2=(solve(a.substr(0,i),b.substr(n-i,i)) and solve(a.substr(i,n-i),b.substr(0,n-i)));

        if(cond1 or cond2)
        {
            flag=true;
            break;
        }
        
    }

    return flag;
}

int main()
{
    string a, b;
    cout<<"enter both the strings ";
    cin>>a>>b;
    
    if(a.length()!=b.length()){
        cout<<"not scrambled strings";
    }
    if(a.size()==0)
    cout<<"scrambled strings ";

    if(solve(a,b))
    cout<<"scrambled strings ";
    else
    cout<<"not scrambled strings ";
    
    return 0;
}