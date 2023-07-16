#include<iostream>
using namespace std;

bool issafe(int board[][10],int i,int j,int n){
    for(int k=0;k<i;k++){
        if(board[k][j]==1){
            return false;
        }
    }

    int x=i;
    int y=j;
    while(x>=0 and y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }

    x=i;
    y=j;
    while(x>=0 and y<n){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y++;
    }
    return true;
}

bool queen(int board[][10], int i,int n){
    if(i==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    cout<<"Q";
                }
                else{
                    cout<<"_";
                }
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        //use this if you want to find the first configuration of N-Queen problem
       // return true;    
       // use this to print all the possible configuration to N-Queen problem
       return false;
    }

    for(int j=0;j<n;j++){
        if(issafe(board,i,j,n)){
            board[i][j]=1;
            bool possible=queen(board,i+1,n);
            if(possible){
                return true;
            }
            
        }
        board[i][j]=0;
        
    }

    return false;
}
int main(){
    int n;
    cin>>n;
    int board[10][10]={0};
    queen(board,0,n);
    return 0;
}