#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<char> q;
    int frq[27]={0};
    char ch;
    cin>>ch;
    while(ch!='.'){
        frq[ch-'a']++;
        q.push(ch);
        while(!q.empty()){
            int idx=q.front()-'a';
            if(frq[idx]>1){
                q.pop();
            }
            else{
                cout<<q.front();
                cout<<endl;
                break;
            }
        }
        if(q.empty()){
            cout<<"-1";
            
            cout<<endl;
        }
        cin>>ch;
    }
    return 0;
}