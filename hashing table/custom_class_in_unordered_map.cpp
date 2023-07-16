#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

class student{
    public:
    string firstname;
    string secondname;
    int roll;

    student(string f,string f1,int roll){
        firstname=f;
        secondname=f1;
        this->roll=roll;
    }

    bool operator==(const student &s)const{             //this is to tell the STL that the two key are equal only when the roll numbers are equal otherwise in STL it always check for equalness by its key which is usually the first argument in map
        return roll==s.roll;
    }
};


class hashfunc{                         //this is to tell the STL that what hashfunc needs to be used in ordre to allot the key in the dynamic array
    public:

    size_t operator()(const student&s)const{
        return s.firstname.length()+s.secondname.length();
    }
};

int main(){

    unordered_map<student,int,hashfunc> m;
    student s1("gaurav","tewatia",67);
    student s2("kartik","tewatia",47);
    student s3("kartik","kumar",68);
    student s4("gaurav","tewatia",37);

    m[s1]=100;
    m[s2]=120;
    m[s3]=10;
    m[s4]=140;
    cout<<m[s4]<<endl;
    for(auto f:m){
        cout<<f.first.firstname<<" and "<<f.second<<endl;
    }
   
    
    return 0;
}