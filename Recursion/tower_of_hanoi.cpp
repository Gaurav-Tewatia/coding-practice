#include<iostream>
using namespace std;
void hanoi(int n, char s,char m, char e){
    if(n==0){
        return;
    }
    hanoi(n-1,s,e,m);
    cout<<" shift "<<n<<" from "<<s<<" to "<<e<<endl;
    hanoi(n-1,m,s,e);

}
int main(){
    int n;
    cin>>n;
    hanoi(n,'A','B','C');
    return 0;
}