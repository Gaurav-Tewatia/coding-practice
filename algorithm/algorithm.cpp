#include<iostream>
#include<algorithm>
#include<vector>
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

cout<<"frequen of the element is "<<up-lb<<endl;    //gives the frequency that means how many times the element is present in the array

  for(int i=0;i<n;i++){
    cout<<a[i]<<',';
  }
  cout<<endl;
  rotate(a,a+2,a+n);                //rotate the array parameters are givena as starting point, middle point, ending point
  for(int i=0;i<n;i++){
    cout<<a[i]<<',';
  }

  
  cout<<endl;
  vector<int> v;                        //creation of an vecoti array it is a dynamic array
  v.push_back(10);                      //inserting values in the vector array
  v.push_back(20);
  v.push_back(30);
  rotate(v.begin(),v.begin()+1,v.end());        //rotating the vector array
  for(int x:v){                             //for every element x present in the vecotr v 
    cout<<x<<",";                           
  }
  vector<int> c;
  c.push_back(1);
  c.push_back(2);
  c.push_back(3);
  cout<<endl;
  for(int x:c){
    cout<<x<<",";
  }
  cout<<endl;
next_permutation(c.begin(),c.end());            //gives the next big number lexiographically
for(int x:c){
    cout<<x<<",";
  }
 cout<<endl;
  int q=10;
  int w=7;
  swap(q,w);                //swap the elements 
  cout<<q<<" "<<w;
  cout<<endl;

  cout<<"maximum of the element "<<max(q,w)<<endl;          //find the maximum of the element

  cout<<"minimum of the element "<<min(q,w)<<endl;          //find the minimum of the element

  int r[]={1,2,3,4,5};
  int len=sizeof(r)/sizeof(int);
  for(int i=0;i<len;i++){
    cout<<r[i]<<" ";
  }
    cout<<endl;
    reverse(r,r+len);             //reverse the array

  for(int i=0;i<len;i++){
    cout<<r[i]<<" ";
  }
    return 0;
}