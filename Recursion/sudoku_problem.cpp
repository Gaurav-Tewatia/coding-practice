#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

bool canplace(int mat[][100],int number,int i,int j,int n){
    for(int k=0;k<n;k++){
        if(mat[k][j]==number or mat[i][k]==number){
            return false;
        }
    }
    int sq = sqrt(n);
    int sr=(i/sq)*sq;
    int sc=(j/sq)*sq;
    for(int x=sr;x<(sr+sq);x++){
        for(int y=sc;y<(sc+sq);y++){
            if(mat[x][y]==number){
                return false;
            }
        }
    }
    return true;
}

bool sudoku(int mat[][100], int i,int j,int n){
    if(i==n){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                cout<<mat[j][k]<<", ";
            }
            cout<<endl;
        }
        return true;
    }

    if(j==n){
        return sudoku(mat,i+1,0,n);
    }
    if(mat[i][j]!=0){
        return sudoku(mat,i,j+1,n);
    }
    for(int number=0;number<=9;number++){
        if(canplace(mat,number,i,j,n)){
            mat[i][j]=number;
            bool possible=sudoku(mat,i,j+1,n);
            if(possible){
                return true;
            }
        }
        //backtracking
        mat[i][j]=0;
    }
    
    return false;
}

int main(){
    int mat[100][100]={ {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                        {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                        {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                        {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                        {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                        {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                        {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                        {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                        {0, 0, 5, 2, 0, 6, 3, 0, 0} };
        int n;
        cin>>n;
        sudoku(mat,0,0,n);
        
    return 0;
}