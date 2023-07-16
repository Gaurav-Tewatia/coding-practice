#include<iostream>
using namespace std;

int solution(int arr[],int s,int n){
   
    int count=0;
    int f=0;
    int sum=0;
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
        
            count=0;
            sum=0;
            for(int k=i;k<=j;k++){
                count++;
                sum+=arr[k];
            }
            if(sum==count*s){
                f+=1;
            }
        }
    }
    return f;
}

int solution2(int a[],int s,int n){
    int cum[n];
    cum[0]=0;
    int sum=0;
    int count=0;
    int f=0;

    for(int i=1;i<n;i++){
        cum[i]=cum[i-1]+a[i];
    }

    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
            sum=0;
            count=0;
            sum=cum[j]-cum[i];
            if(sum==count*s){
                f++;
            }

        }
    }
    return f;
}

int main(){

    int a[]={2,1,3};
    int s=2;
    cout<<solution(a,s,3);

    return 0;
}