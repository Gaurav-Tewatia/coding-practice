#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char a[]="babdfghjbdj";
    int n=strlen(a);
    int cl=1;
    int ml=1;
    int visited[256]={-1};
     visited[a[0]]=0;
    for(int i=1;i<n;i++){
        int lastoccur=visited[a[i]];
        if(lastoccur==-1 or i-cl>lastoccur){
            cl++;
            ml=max(cl,ml);
        }
        else{
            if(cl>ml){
                ml=cl;
            }
            cl=i-lastoccur;
        }
        visited[a[i]]=i;
    }
    if(cl>ml){
                ml=cl;
            }
            cout<<ml<<endl;
    return 0;
}