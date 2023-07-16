#include<iostream>
using namespace std;
void sub_mattrix(int a[][1000], int n){                         //brute force method uses O(n6) time complexity
    int sum=0;
    for(int li=0;li<n;li++){
        for(int lj=0;lj<n;lj++){
            for(int bi=li;bi<n;bi++){
                for(int bj=lj;bj<n;bj++){
                    for(int i=li;i<=bi;i++){
                        for(int j=lj;j<=bj;j++){
                            sum+=a[i][j];
                        }
                    }
                }
            }
        }
    }
    cout<<"total sum of all the sub mattrix is "<<sum;
}

void suffice_mattrix(int c[][1000], int n){             //using a different array to solve the problem
    int sum=0;
    for(int li=0;li<n;li++){
        for(int lj=0;lj<n;lj++){
            for(int bi=li;bi<n;bi++){
                for(int bj=lj;bj<n;bj++){
                   sum+=c[bi][bj]-c[li-1][bj]-c[bi][lj-1]+c[li-1][lj-1];
                }
            }
        }
     }
     cout<<"total sum of the all sub mattrix is "<<sum;
}
void contribution(int a[][1000],int n){                 //best method to find the sum of all the sub mattrix
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tl=(i+1)*(j+1);
            int br=(n-i)*(n-j);
            sum+=a[i][j]*tl*br;
        }
    }
     cout<<"total sum of all the sub mattrix is "<<sum;

}

int main(){
    int a[1000][1000]={0};
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    sub_mattrix(a,n);
    cout<<endl;
    /*
// second method

   int c[1000][1000]={0};
    c[0][0]=a[0][0];
    //colwise addition
    for(int j=1;j<n;j++){
        c[0][j]=a[0][j]+c[0][j-1];
    }
    for(int i=1;i<n;i++){
        c[i][0]=a[i][0]+c[i-1][0];
    }
    for( int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            c[i][j]=a[i][j]+c[i][j-1];
            }
    }
    cout<<c[1][1]<<endl;
    
    //row wise addition
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            c[j][i]=c[j][i]+c[j-1][i];
        }
    }
    cout<<c[1][1]<<endl;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
     suffice_mattrix(a,n);
     cout<<endl;*/
  contribution(a,n);

    return 0;
}