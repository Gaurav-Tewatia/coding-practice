#include<iostream>
#include<set>
#include<vector>
using namespace std;

class points{
    public:
    int x,y;
    points(){

    }
    points(int x,int y){
        this->x=x;
        this->y=y;
    }
};

class compare{
    public:
    bool operator()(points p1, points p2){
        if(p1.x==p2.x){
            return p1.y<p2.y;
        }
        return p1.x<p2.x;
    }
};

int count_rects(vector<points> coords){
    int n=coords.size();
    set<points,compare> s;
    for(auto p:coords){
        s.insert(p);
    }
    
    int ans=0;
    for(auto it=s.begin();it!=prev(s.end());it++){
        for(auto jt=next(it);jt!=s.end();jt++){
            points p1=*it;
            points p2=*jt;

            if(p2.x==p1.x or p2.y==p1.y){
                continue;
            }
            points p3(p2.x,p1.y);
            points p4(p1.x,p2.y);

            if(s.find(p3)!=s.end() and s.find(p4)!=s.end()){
                ans++;
            }
        }
    }
    return ans/2;
}
int main(){
    int m;
    cin>>m;
    vector<points> coords;
    while(m--){
        int x,y;
        cin>>x>>y;
        points p(x,y);
        coords.push_back(p);
    }
    cout<<count_rects(coords);
    return 0;
}