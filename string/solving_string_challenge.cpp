#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

string extractthekey(string s,int key){
    char *p =strtok((char *)s.c_str()," ");
    while(key>1){
        p=strtok(NULL," ");
        key--;
    }
    return (string)p;
}

int converttoint(string s){
    int sum=0;
    int p=1;
    for(int i=s.length()-1;i>=0;i--){
        sum+=((s[i]-'0')*p);
        p=p*10;
    }
    return sum;
}



bool numericcompare(pair<string,string> s1, pair<string,string> s2){
    string key1,key2;
    key1=s1.second;
    key2=s2.second;
    return converttoint(key1)<converttoint(key2);
}

bool lexiocompare(pair<string,string> s1,pair<string,string> s2){
    string key1,key2;
    key1=s1.second;
    key2=s2.second;
    return key1<key2;
}
int main(){
    int n;
    cin>>n;
    string s[n];
    cin.get();
    for(int i=0;i<n;i++){
        getline(cin,s[i]);
    }
    int key;
    string reversal, ordering;
    cin>>key>>reversal>>ordering;
    pair<string,string> str[n];
   for(int i=0;i<n;i++){
    str[i].first=s[i];
     str[i].second=extractthekey(s[i],key);
   }

   if(ordering=="numeric"){
    sort(str,str+n,numericcompare);
   }
   else{
    sort(str,str+n,lexiocompare);
   }

   if(reversal=="true"){
    for(int i=0;i<n/2;i++){
        swap(str[i],str[n-i-1]);
    }
   }

   for(int i=0;i<n;i++){
    cout<<str[i].first<<endl;
   }
    return 0;
}