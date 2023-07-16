#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a, int b){
    return a<b;
}

int main(){
int a[]={1,3,4,5,4,2};
int n= sizeof(a)/sizeof(int);
int key;
cout<<"enter the number to be find ";
cin>>key;
auto it=find(a,a+n,key);     //gives the address of the bucket at which the element is found
int index=it-a;

 
 if (index==n){
    cout<<"element not found";
 }
 else{
    cout<<"element found at the index "<<index;
 }

 sort(a,a+n,compare);                       //sort the function according to compare

bool p=binary_search(a,a+n,key);            //returns true or false value based on if the element is found or not uses nlogn time complexity
if(p){                                      //remember binary_search can only be used in a sorted array
    cout<<endl<<"element is presendt"<<endl;
}
else
cout<<"element is not found"<<endl;

auto lb= lower_bound(a,a+n,key);              //gives the address of the first occurence of the element >=4
cout<<"lower bound of the element is present at "<<lb-a<<endl;

auto up=upper_bound(a,a+n,key);                   //gives the address of the first occurence of the element >4 that is 5 in this case
cout<<"upper bound of the element is preset at "<<up-a<<endl;

cout<<"frequen of the element is "<<up-lb;    //gives the frequency that means how many times the element is present in the array


    return 0;
}