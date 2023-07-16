#include<iostream>
using namespace std;

int main(){

int **arr;      //creates a pointer which points towards other pointer
int r,c;
cin>>r>>c;
arr=new int*[r];          //initialise the pointer arr to a array of r size which holds the pointer elements
for(int i=0;i<r;i++){
    arr[i]=new int [c];     //now initialse the each element off the arr as a pointer to a array of c size
}
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        cin>>arr[i][j];      //giving the value to each element of the 2-d array
    }
}
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
       cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
cout<<*arr<<endl;         //shows the first elemet of the arr which is nothing but the address of the first element of 2-d array
cout<<arr<<endl;          //shows the address of arr
cout<<arr[0]<<endl;
cout<<**arr<<endl;        // shoes the first elemt of the 2-d array
    return 0;
}