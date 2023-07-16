#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>

using namespace std;
int main(){

    unordered_map<string,vector<string> > m;
    m["rahul"].push_back("9897");
    m["kajol"].push_back("9897");
    m["kajol"].push_back("9897");
    m["kajol"].push_back("9897");
    m["rahul"].push_back("927");
    m["rahul"].push_back("3437");
    m["rahul"].push_back("985");

    for(auto f:m){
        cout<<"name "<<f.first<<" and ";
        for(string s:f.second){
            cout<<s;
        }
        cout<<endl;
    }

    string name;
    cout<<"enter name to be find ";
    cin>>name;

    if(m.count(name)==0){
        cout<<"absent";
    }
    else{
        cout<<name<<" number is ";
        for(string s:m[name]){
            cout<<s;
        }
    }
    return 0;
}