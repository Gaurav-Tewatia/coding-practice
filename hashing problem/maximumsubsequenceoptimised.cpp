#include<iostream>
#include<unordered_set>
using namespace std;

int findthelargestsubsequence(int a[],int n){
    unordered_set<int> s;
    
    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }

    int max_streak=1;
    for(int i=0;i<n;i++){

        if(s.find(a[i]-1)==s.end()){
            int nextno=a[i]+1;
            int streak_len=1;
            while(s.find(nextno)!=s.end()){
                nextno+=1;
                streak_len+=1;
            }
                max_streak=max(streak_len,max_streak);
        }
    }
    return max_streak;
        
}

int main(){
    int a[]={14,5,1,2,6,3,7,8,9,13,15,11,12,13,17};
    int n;
    n=sizeof(a)/sizeof(int);
    
    cout<<findthelargestsubsequence(a,n);
    return 0;
}