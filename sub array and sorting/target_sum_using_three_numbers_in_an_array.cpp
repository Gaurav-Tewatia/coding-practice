#include<iostream>
#include<algorithm>
using namespace std;

int main(){

int a[10]={1,4,6,3,8,2,5,0,9,7};
cout<<"enter the target sum";
int n;
cin>>n;
sort(a,a+10);
for(int i=0;i<9;i++){
    cout<<a[i]<<" ";
}
cout<<endl;
for(int i=0;i<=7;i++){
    int j=i+1;
    int k=9;
    while(j<k){
        if(n==(a[j]+a[k]+a[i])){
            cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
            j++;
            k--;
        }
        else if(n>(a[j]+a[k]+a[i])){
            k--;

        }
        else{
            j++;
        }

    }
    cout<<"no match found";
}
    return 0;
}
//problem in running the code
