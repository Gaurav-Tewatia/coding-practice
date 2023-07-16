#include<iostream>
#include<set>
using namespace std;

class compare{
    public:
    bool operator()(pair<string,int> p1,pair<string,int> p2){
        return p1.second<p2.second;
    }
};
int main(){
    pair<string,int> p1=make_pair("A",40);
    pair<string,int> p2=make_pair("B",100);
    pair<string,int> p3=make_pair("B",20);
    pair<string,int> p4=make_pair("D",50);

    multiset<pair<string,int> > m;  //in the multiset pair is automatically sort according to the first element of the array
    m.insert(p1);
    m.insert(p2);
    m.insert(p3);
    m.insert(p4);

    for(auto it:m){
        cout<<it.first<<","<<it.second<<endl;
    }

    multiset<pair<string,int>,compare > m2;

    m2.insert(p1);
    m2.insert(p2);
    m2.insert(p3);
    m2.insert(p4);

    cout<<"display after sorting according to second element of the pair "<<endl;
    for(auto it:m){
        cout<<it.first<<","<<it.second<<endl;
    }

    return 0;
}