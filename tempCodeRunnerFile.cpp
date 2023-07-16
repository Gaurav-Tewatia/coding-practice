#include<iostream>
using namespace std;

int main(){
int n,m;
cin>>n>>m;
int a[100][100];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        a[i][j]=1;
    }
}
for(int i=0;i<n;i++){
    int sum=0;
    for(int j=0;j<m;j++){
        sum+=a[i][j];
        a[i][j]=sum;
    }
}
for(int i=0;i<m;i++){
    int sum=0;
     for(int j=0;j<n;j++){
        sum+=a[j][i];
        a[j][i]=sum;
    }
   
}

cout<<"matrix after the prerix is ";
cout<<endl;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cout<<a[i][j]<<" ";
    }
    cout<<endl;
}
int sum=0;
for(int tl=0;tl<n;tl++){
    for(int tl2=0;tl2<m;tl2++){
        for(int br1=tl;br1<n;br1++){
            for(int br2=tl2;br2<m;br2++){
                sum+=(a[br1][br2]-a[tl-1][br2]-a[br1][tl2-1]+a[tl-1][tl2-1]);
            }
        }
    }
}
cout<<"total sum of all the submatrix is "<<sum<<endl;
return 0;
}