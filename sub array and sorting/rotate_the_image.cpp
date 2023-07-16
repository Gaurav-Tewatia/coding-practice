#include<iostream>
using namespace std;

void rotate(int a[][1000],int n){
   
    for(int i=0;i<n;i++){
         int start=0;
    int end=n-1;
        while(start<end){
            swap(a[i][start],a[i][end]);
            start++;
            end--;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<j){
                swap(a[i][j],a[j][i]);
            }
        }
    }
}

void rotate_stl(int a[][1000], int n){
    for(int i=0;i<n;i++){
        reverse(a[i],a[i]+n);
    }
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<j){
                swap(a[i][j],a[j][i]);
            }
        }
    }
}
void display(int a[][1000],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}



int main(){
    int n;
    cin>>n;
    int val=1;
    int a[1000][1000]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=val;
            val+=1;
        }
    }
    display(a,n);
    int s;
    cout<<"enter how many times want to turn the image";
    cin>>s;
    for(int i=0;i<s;i++){
    //rotate(a,n);
    rotate_stl(a,n);
    }
    display(a,n);
    


    return 0;
}