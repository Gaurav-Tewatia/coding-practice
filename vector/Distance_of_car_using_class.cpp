#include<iostream>
#include<vector>
#include<string>
using namespace std;
class car{
    public:
    string name;
    int x,y;

    car(string n,int x,int y){
        name=n;
        this->x=x;
        this->y=y;

    }
    int dis(){
        return x*x+y*y;
    }
};
bool compare(car a, car b){
    int d1=a.dis();
    int d2=b.dis();
    if(d1==d2){
        return a.name.length()<b.name.length();
    }
    return d1<d2;

}
int main(){
    vector<car> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        string t;
        cin>>t>>x>>y;
        car c(t,x,y);
        v.push_back(c);
    }
    sort(v.begin(),v.end(),compare);
    for(auto i:v){
        cout<<"car "<<i.name<<" distance "<<i.dis()<<" "<<i.x<<" "<<i.y<<endl;
    }

    return 0;
}