#include<iostream>

using namespace std;
int last_index(int *a,int number,int n,int i){
    if(i==n){
        return -1;
    }
    int ans=last_index(a,number,n,i+1);
    if(a[i]==number and ans==-1){
        return i;
    }
    return ans;
}

int main(){
    int a[]={1,4,2,3,5,2,4};
    int n=sizeof(a);
    int number=4;
    
    cout<<last_index(a,number,n,0);
    return 0;
}