#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
class fun{
    public:
    void operator()(string s){
        cout<<"having fun with "<<s;
    }
};

int main(){
   fun f;
   f("c++");
    return 0;
}