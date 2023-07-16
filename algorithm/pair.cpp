#include<iostream>
#include<algorithm>
using namespace std;

int main(){

pair<int,int> p;     //created a pair which holds two value of type (int ,int)
p.first=10;
p.second=20;
cout<<p.first<<endl;
cout<<p.second<<endl;
pair<int,int>p1(p);                     //creates an pair which takes value from a similar type of pair
cout<<p1.first<<endl;
pair<int,char> name= make_pair(10,'A');         //creates a pair of type (int,char)
cout<<name.first<<endl;
cout<<name.second<<endl;
pair<int,string> swag=make_pair(12,"Gaurav");           //creates a pair of type (int , string)
cout<<swag.first<<endl;
cout<<swag.second<<endl;
int a,b;
cin>>a>>b;
pair<int,int> t=make_pair(a,b);
cout<<t.first<<endl;
cout<<t.second<<endl;
pair<pair<int,int>,string> car;                 //creates a pair inside a pair ((int, int),string)
car.first.first=10;
car.first.second=20;
car.second="audi";
cout<<car.first.first<<endl;
cout<<car.first.second<<endl;
cout<<car.second<<endl;
    return 0;
}