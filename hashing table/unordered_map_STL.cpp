#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){

    unordered_map<string,int> m;
    m.insert(make_pair("apple",20));
    pair<string,int> p;
    p.first="banana";
    p.second=40;
    m.insert(p);
    string fruit;
    cout<<"enter the name of the fruit that needs to be searched";
    cin>>fruit;
    auto it=m.find(fruit);          //returns a iterator if the key is found if not then the iterator pints towards the end of the container
    if(it!=m.end()){
        cout<<"price of "<<fruit<<" is "<<m[fruit]<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
    m["lichti"]=60;
    cout<<m["lichti"]<<endl;
    m["lichti"]+=20;
    for(auto f:m){
        cout<<f.first<<" and "<<f.second<<endl;
    }
    m.erase("lichti");
    if(m.count("lichti")){          //count function returns 0 or 1 depending on wether the key is found or not 
        cout<<"lichti price is "<<m["lichti"]<<endl;
    }else{
        cout<<"lichti is not found "<<endl;
    }

    for(auto it=m.begin();it!=m.end();it++){                     
        cout<<"price of "<<it->first<<" is "<<it->second<<endl;     //because it's a pair object
    }
    return 0;
}