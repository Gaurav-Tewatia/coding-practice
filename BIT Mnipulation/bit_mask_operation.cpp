#include<iostream>
#include<algorithm>

using namespace std;

int odd_even_checker(int n){
    return n&1;
}

int getbit(int n, int i){
    
    return (n&(1<<i))>0?1:0;
}
int setbit(int n, int i){
    return n|(1<<i);
}
int clearbit(int n, int i){
    //return n^(1<<i);
    int mask=~(1<<i);
    return n&mask;
}
void updatebit(int &n, int i,int v){
     clearbit(n,i);
     n=n|(v<<i);
}
int clearlastibits(int n, int i){
    int mask=(-1<<i);           //-1 =11111111 or (~0)
    return n&mask;
}
int clearrangeitoj(int n, int i, int j){
    int a=(~0)<<(j+1);
    int b=(1<<i)-1;
    int mask=a|b;
    return n&mask;
}
int replacebitsinNbyM(int n, int m, int i, int j){
   n  = clearrangeitoj(n,i,j);
   int mask=m<<i;
   return n|mask;
}
int countbits(int n){           //time complexity is number logN loop will run for all the bits of N
    int ans=0;
    while(n>0){
        
        ans+=n&1;
        n=n>>1;
        
    }
    return ans;

    /* or faster method                 //time complexity is less loop will run only for the set bits

    int ans=0;
    while(n>0){
        n=n&(n-1);
        ans++;
    }
    return ans;
    */


}
int decimaltobinary(int n){
    int ans=0;
    int p=1;
    while(n>0){
        int last_digit=(n&1);
        ans+=p*last_digit;
        p=p*10;
        n=n>>1;
        
    }
    return ans;
}
int main(){

    int n;
    cout<<"enter the number "<<endl;
    cin>>n;
    int k;
    cout<<"1) to check wether the number is odd or even"<<endl;
    cout<<"2) to get a bit at a index i"<<endl;
    cout<<"3) to set bit at a index"<<endl;
    cout<<"4) to clear a bit at a index"<<endl;
    cout<<"5) to update a bit at a index"<<endl;
    cout<<"6) to clear last i bits"<<endl;
    cout<<"7) to clear range i to j"<<endl;
    cout<<"8) to replace bits in n by m"<<endl;
    cout<<"9) to count the number of set bits present"<<endl;
    cout<<"10) decimal to binary"<<endl;
    cout<<"enter your choice"<<endl;
    cin>>k;
    int i;
    switch(k){
        case 1: if(odd_even_checker(n)){
                cout<<"number is odd";
            
                 }else{
                    cout<<"number is even";
                 }
                break;
        case 2: cout<<"tell the index number"<<endl;
                
                cin>>i;
                cout<<getbit(n,i);
                break;

        case 3: cout<<"tell the index to be set"<<endl;
                
                cin>>i;
                cout<<setbit(n,i);
                break;
        case 4: cout<<"tell the index to be cleared"<<endl;
                
                cin>>i;
                cout<<clearbit(n,i);
                break;
        case 5: cout<<"tell the index to be updated"<<endl;
                cin>>i;
                cout<<"tell to what the bit needs to be updated 0/1"<<endl;
                int v;
                cin>>v;
                updatebit(n,i,v);
                cout<<n;
                break;
        case 6: cout<<"enter the ith bit"<<endl;
                cin>>i;
                cout<<clearlastibits(n,i);
                break;
        case 7: cout<<"enter the range i and j"<<endl;
                cin>>i;
                int j;
                cin>>j;
                cout<<clearrangeitoj(n,i,j);
                break;
        case 8: cout<<"enter the number as well as the bits from which to which the number needds to inserted"<<endl;
                int m;
                cin>>m;
                cin>>i;
                cin>>j;
                cout<<replacebitsinNbyM(n,m,i,j);
                break;
        case 9: cout<<countbits(n);
                //__builtin_popcount(n);    inbuilt function 
                break;
        case 10:cout<<decimaltobinary(n);
                break;
        default:  cout<<"no matching choice";

    }

    return 0;
}