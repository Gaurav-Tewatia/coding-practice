#include<iostream>
#include<deque>
using namespace std;

int main(){
    int n;
    int a[1000]={0};
    int k;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>k;
     deque<int> q(k);
     int i;
    for(i=0;i<k;i++){
        while(!q.empty() and a[i]>a[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    for(;i<n;i++){
        cout<<a[q.front()]<<" ";
        while((!q.empty() and (q.front()<=i-k))){
            q.pop_front();
        }
        while(!q.empty() and a[i]>=a[q.back()]){
            q.pop_back();
        }

        q.push_back(i);


    }
    cout<<a[q.front()]<<endl;


    return 0;
}