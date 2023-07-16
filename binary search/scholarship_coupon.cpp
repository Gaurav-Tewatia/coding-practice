#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"total number of students are ";
    cin>>n;
    int m;
    cout<<"\n total number of coupons are ";
    cin>>m;
    cout<<"\n total coupons required to get 100 percent fee waiver ";
    int x;
    cin>>x;
    cout<<"\n total number of coupons taken from remaining students are ";
    int y;
    cin>>y;
    int s=0;
    int e=n;
    int ans=0;
    while(s<=e){

        int mid=(s+e)/2;
        if(mid*x<=(m+((n-mid)*y))){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    cout<<"\ntotal students who got 100 percent fee waiver are "<<ans;
    return 0;

}