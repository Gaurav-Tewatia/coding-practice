#include<iostream>
#include<string>

using namespace std;

string find_window(string s,string p){
    int sl=s.length();
    int pl=p.length();
    if(pl>sl){
        return "None";
    }
    int fs[256]={0};
    int fp[256]={0};
    for(int i=0;i<pl;i++){
        char ch=p[i];
        fp[ch]++;
    }

    int cnt=0;
    int start=0;
    int min_len=INT_MAX;
    int start_idx=-1;
    for(int i=0;i<sl;i++){
        char ch=s[i];
        fs[ch]++;
        if(fp[ch]!=0 and fs[ch]<=fp[ch]){
            cnt++;
        }
        if(cnt==pl){
            char temp=s[start];
            while(fp[temp]==0 or fs[temp]>fp[temp]){
                fs[temp]--;
                start++;
                temp=s[start];
            }
            int window_len=i-start+1;
            if(window_len<min_len){
                min_len=window_len;
                start_idx=start;
            }
        }
    }
    if(start_idx==-1){
        return "None";
    }
    string ans=s.substr(start_idx,min_len);
    return ans;
}

int main(){

    string s="hllloeaeo world";
    string p="eelo";
    cout<<find_window(s,p)<<endl;

    return 0;
}