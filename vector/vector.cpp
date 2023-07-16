#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> a;
    vector<int> b(5,10);
    vector<int> c(b.begin(),b.end());
   vector<int> d;
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
    int no;
    cin>>no;
    d.push_back(no);

   }
    for(int i=0;i<b.size();i++){
        cout<<b[i]<<",";
    }
    cout<<endl;
    for(auto it=b.begin();it!=b.end();it++){
        cout<<(*it)<<",";
    }
    cout<<endl;
    for(int x:c){
        cout<<x<<",";
    }
    cout<<endl;
    vector<int> e;
    e.push_back(1);
    e.push_back(2);
    e.push_back(3);
    e.push_back(4);
    e.push_back(5);
    cout<<d.size()<<endl;
    cout<<e.size()<<endl;
    cout<<d.capacity()<<endl;
    cout<<e.capacity()<<endl;
    cout<<d.max_size()<<endl;
    cout<<e.max_size()<<endl;

    return 0;
}