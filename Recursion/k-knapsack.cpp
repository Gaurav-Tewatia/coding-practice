#include<iostream>
#include<algorithm>
using namespace std;
int profit(int *weight,int *price,int n,int c){
    if(n==0 || c==0){
        return 0;
    }
    int ans=0;
    int inc,exc;
    inc=exc=INT_MIN;
    if(weight[n-1]<=c){
        inc=price[n-1]+profit(weight,price,n-1,c-weight[n-1]);
    }
    exc=profit(weight,price,n-1,c);

    ans=max(inc,exc);
    return ans;
}
int main(){
int weight[]={1,2,3,5};
int price[]={40,20,30,100};
int n=4;
int c=7;
cout<<profit(weight,price,n,c);
    return 0;
}