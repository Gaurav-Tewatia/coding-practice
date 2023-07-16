#include<iostream>
using namespace std;
int main(){

    int a[1000];
    int n;
    cin>>n;
    int sum=0;
    int max=0;
    int left, right;

   /* for(int i=0;i<n;i++){                     //uses three loops time complexity is O(n3)
        cin>>a[i];
    }
   for(int i=0;i<n-1;i++){
        for(int j=1;j<n;j++){
            sum=0;
            for(int k=i;k<=j;k++){
                cout<<a[k]<<',';
                sum+=a[i];
            }if(max<sum)
            max=sum;
            cout<<endl;
        }
        
    }
    cout<<max;*/
  /*  int cum[1000];                            //uses two loops time complexity is O(n2)
    a[0]=0;
    cum[0]=a[0];
    
    for(int i=1;i<n;i++){
        cin>>a[i];
       cum[i]=cum[i-1]+a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sum=0;
            sum=cum[j]-cum[i-1];
            if(sum>max){
                max=sum;
                left=i;
                right=j;
            }

        }
    }
    cout<<"maximum sum of the sub arrayy is "<<max<<endl;
    for(int i=left;i<=right;i++){
        cout<<a[i]<<',';
    }*/
    for(int i=0;i<n;i++){                       //kaden's algorithm uses only one for loop time complexity is O(n) the lowest of all the cases
        cin>>a[i];
    }
     for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum<0)
        sum=0;
        if(sum>max)
        max=sum;
    }
    cout<<"maximum of the sub array is "<<max<<endl;
    return 0;
}