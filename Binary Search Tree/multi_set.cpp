#include<iostream>
#include<set>
using namespace std;
typedef multiset<int>::iterator IT;
int main(){
 int a[]={10,20,30,10,10,40,55,40,30,10};
    
    int n=sizeof(a)/sizeof(int);
    multiset<int> m(a,a+n);
    
    for(auto it:m){
        cout<<it<<",";
    }
    cout<<endl;
    m.insert(1);
    for(auto it:m){
        cout<<it<<",";
    }
    m.erase(20);
    cout<<endl;
    for(auto it:m){
        cout<<it<<",";
    }

    cout<<endl<<"count "<<m.count(10);
    cout<<endl;
    auto it=m.find(30);  //gives the first element that is 30
    cout<<(*it)<<endl;

    pair<IT,IT> range=m.equal_range(10);

    //gives all the occurence of 10
for(auto it=range.first;it!=range.second;it++){
    cout<<(*it)<<",";
}
cout<<endl;

for(auto it=m.lower_bound(10);it!=m.upper_bound(77);it++){
    cout<<(*it)<<",";
}
    return 0;

}