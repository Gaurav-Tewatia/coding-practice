#include<iostream>
#include<queue>
using namespace std;

class person{
    public:
    int age;
    string name;

    person(int a,string n){
        age=a;
        name=n;
    }
};

class personcompare{
    public:
    bool operator()(person A , person B){
        return A.age>B.age;
    }
};

int main(){
    priority_queue<person,vector<person>,personcompare> p; //see here we have give our own class as person compare in order to let STL know how to compare between two person type variable 
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        string name;
        cin>>a>>name;
        person P(a,name);
        p.push(P);
    }
    int k=3;
    for(int i=0;i<k;i++){           //gives top 3 people according to their age
        person P=p.top();
        cout<<P.name<<" "<<P.age<<endl;
        p.pop();
    }
    return 0;
}