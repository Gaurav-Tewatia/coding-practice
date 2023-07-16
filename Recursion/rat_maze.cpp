#include<iostream>
using namespace std;

bool path(char maze[10][10], int sol[][10], int i, int j, int m, int n){
    if(i==m && j==n){
        sol[m][n]=1;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
            cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    
    if(i>m || j>n){
        return false;
    }
    if(maze[i][j]=='X'){
        return false;
    }

    sol[i][j]=1;
    bool right=path(maze,sol,i,j+1,m,n);
    bool down=path(maze,sol,i+1,j,m,n);
    //backtracking 
    sol[i][j]=0;

    if(right or down){
        return true;
    }
    return false;



}
int main(){
    char maze[10][10]={ "OOOO",
                        "OOXO",
                        "OOOX",
                        "0X00"};
    int sol[10][10]={0};
    int m,n;
    n=m=4;
    bool ans=path(maze,sol,0,0,m-1,n-1);
    if(ans==false){
        cout<<"path does nor exist ";
    }
        return 0;
}