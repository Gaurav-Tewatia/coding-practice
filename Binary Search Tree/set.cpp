#include<iostream>
#include<set>
using namespace std;

int main(){
    int a[]={1,2,6,4,8,2,6,4,9};
    set<int> s;
    int n=sizeof(a)/sizeof(int);
    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }
    for(set<int>::iterator it=s.begin();it!=s.end();it++){
        cout<<*(it)<<",";
    }

    s.erase(6);
    cout<<endl;
    cout<<"after erasing 6"<<endl;
    for(set<int>::iterator it=s.begin();it!=s.end();it++){
        cout<<*(it)<<",";
    }
    auto it=s.find(9);
    s.erase(it);
    cout<<endl<<"after erasing 9"<<endl;
    for(set<int>::iterator it=s.begin();it!=s.end();it++){
        cout<<*(it)<<",";
    }

    set<pair<int,int> > s2;
    s2.insert(make_pair(1,14));
    s2.insert(make_pair(13,6));
    s2.insert(make_pair(13,6));
    s2.insert(make_pair(11,34));
    s2.insert(make_pair(120,1));
    s2.insert(make_pair(10,2));
    s2.insert(make_pair(10,2));
    cout<<endl;
    for(auto p:s2){
        cout<<p.first<<" and "<<p.second<<endl;
    }
    cout<<"after erasing 10,2"<<endl;
    s2.erase(make_pair(10,2));
    for(auto p:s2){
        cout<<p.first<<" and "<<p.second<<endl;
    }

    cout<<"lower bound of 11,34 is "<<endl;
    auto t=s2.lower_bound(make_pair(11,34));
    cout<<t->first<<","<<t->second;
    cout<<endl;
    cout<<"upper bound of 11,34 is "<<endl;
    auto e=s2.upper_bound(make_pair(11,34));
    cout<<e->first<<","<<e->second;
    cout<<endl;
    cout<<"upper bound just according to first element of the pair "<<endl;
    auto u=s2.upper_bound(make_pair(11,INT_MAX));
    cout<<u->first<<","<<u->second;
    return 0;
}