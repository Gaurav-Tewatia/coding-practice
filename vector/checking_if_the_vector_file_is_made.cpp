#include<iostream>
#include"Vector.h"
using namespace std;
int main(){
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    cout<<v.size()<<endl;
    v.pop_back();
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<v.at(2);
    return 0;
}