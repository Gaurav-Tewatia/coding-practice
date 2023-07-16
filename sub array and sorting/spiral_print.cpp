
#include<iostream>
using namespace std;
  
   void spiralarray(int n, int a[1000][1000]){
    
    int sr=0;
    int sc=0;
    int er=n-1;
    int ec=n-1;

    while(sr<=er and sc<=ec){

        for(int i=sc;i<=ec;i++){
            cout<<a[sr][i]<<',';
            
        }
        sr++;
        for(int i=sr;i<=er;i++){
            cout<<a[i][ec]<<',';
            
        }
        ec--;
        
        for(int i=ec;i>=sc;i--){
            cout<<a[er][i]<<',';
        }
        er--;
        
        for(int i=er;i>=sr;i--){
            cout<<a[i][sc]<<',';
        }
        sc++;
        
    }
   }
 
 int main(){
    int n;
    cin>>n;
    int a[1000][1000]={0};
    int s=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            a[i][j]=s;
        s+=1;
        cout<<a[i][j]<<"      ";
         }
         cout<<endl;
     }
     
    spiralarray(n,a);
    
    
    return 0;
}