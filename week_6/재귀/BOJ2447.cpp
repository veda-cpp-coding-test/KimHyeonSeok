#include<bits/stdc++.h>
using namespace std;

char board[2300][2300];

void solve(int x, int y, int n){
    if(n==1){
        board[x][y] = '*';
        return;
    }

    
    solve(x,y,n/3);
    solve(x,y+n/3,n/3);
    solve(x,y+ 2*n/3,n/3);

    solve(x + n/3,y,n/3);
    // solve(x + n/3,y+n/3,n/3);
    solve(x + n/3,y+ 2*n/3,n/3);

    solve(x + 2 * n / 3,y,n/3);
    solve(x + 2 * n / 3,y+n/3,n/3);
    solve(x + 2 * n / 3,y+ 2*n/3,n/3);


    
}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    
    cin >>n;

    for(int i = 0 ; i < n ; i ++) fill(board[i],board[i]+n,' ');
    solve(0,0,n);

    


    for(int i = 0 ; i< n; i ++){
        for(int j = 0 ; j < n ; j ++){
            cout << board[i][j] ;
        }
        cout << '\n';
    }
}