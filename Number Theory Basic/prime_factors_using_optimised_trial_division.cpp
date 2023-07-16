#include<iostream>
#include<vector>
using namespace std;
void factors(int n){
    int cnt;
    vector<pair<int,int> > factors;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            cnt=0;
            while(n%i==0){
                n=n/i;
                cnt++;
            }
            factors.push_back(make_pair(i,cnt));
        }
    }
    if(n!=1){
        factors.push_back(make_pair(n,1));
    }
    for(auto f:factors){
        cout<<f.first<<" "<<f.second<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    factors(n);
    return 0;
}