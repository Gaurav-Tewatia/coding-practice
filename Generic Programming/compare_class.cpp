#include<iostream>
#include<list>
#include<string>

using namespace std;
//using Templates, Iterator, Comparator
template<class forwarditerator,class T,class compare>
forwarditerator search(forwarditerator start,forwarditerator end,T key,compare cmp){
    while(start!=end){
        if(cmp(*start,key)){
            return start;
        }
        start++;
    }
    return end;
}
class books{
    public:
    string name;
    int price;
    books(string n, int p){
        name=n;
        price=p;
    }
};

class bookcompare{

    public:

    bool operator()(books A,books B){
        if(A.name==B.name){
            return true;
        }
        return false;
    }

};

int main(){

    books b1("c++",100);
    books b2("science",200);
    books b3("maths",300);
    

    list<books> l;
    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);
    
    books booktofind("science",100);
    bookcompare cmp;
    /*if(cmp(b2,booktofind)){
        cout<<"book is found";
    }*/

    auto it=search(l.begin(),l.end(),booktofind,cmp);
    if(it!=l.end()){
        cout<<"book found in the library";
        
    
    }
    else{
        cout<<"book not found";
    }

    return 0;
}