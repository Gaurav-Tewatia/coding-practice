#include<iostream>
#include<unordered_map>
using namespace std;

int findthelargestsubsequence(int a[],int n){
    unordered_map<int,int> m;
    
    for(int i=0;i<n;i++){
        int no=a[i];
        if(m.count(no-1)==0 and m.count(no+1)==0){
            m[no]=1;
        }
        else if(m.count(no-1) and m.count(no+1)){
            int len1=m[no-1];
            int len2=m[no+1];
            int currentlen=1+len1+len2;
            m[no-len1]=currentlen;
            m[no+len2]=currentlen;
        }
        else if(m.count(no-1) and !m.count(no+1)){
            int len=m[no-1];
            m[no-len]=len+1;
            m[no]=len+1;
        }
        else{
            int len3=m[no+1];
            m[no+len3]=len3+1;
            m[no]=len3+1;
        }
    }
    int largest=0;
    for(auto p:m){
        largest=max(largest,p.second);
    }
    return largest;
}

int main(){
    int a[]={14,5,1,2,6,3,7,8,9,13,15,11,12,13,17};
    int n;
    n=sizeof(a)/sizeof(int);
    
    cout<<findthelargestsubsequence(a,n);
    return 0;
}