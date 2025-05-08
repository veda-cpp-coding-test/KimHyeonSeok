#include<bits/stdc++.h>
using namespace std;

const int MX =  (3 << 10) + 1;

char board[MX][2 * MX + 1];

void solve(int x,int y, int n){

    if(n==3){
        // for(int i = 0 ; i < 3; i++){
        //     for(int j = 0 ; j < 5 ; j++){
        //         if(i == 0 && j == 2 ) board[x+i][y+j] = '*';
        //         else if(i == 1 && (j == 1 || j == 3)) board[i+x][j+y] = '*';
        //         else if (i == 2 )  board[x+i][y+j] = '*';
        //     }
        // }
        board[x][y] = '*';
        board[x + 1][y - 1] = board[x + 1][y + 1] = '*';
        for (int i = -2; i <= 2; ++i) board[x + 2][y + i] = '*';

        return;
    }

    
    solve(x, y, n/2);
    solve(x+n/2, y -n/2 , n/2);
    solve(x+n/2, y + n/2 , n/2);

}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n ;


    solve(0,n-1,n);


    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j <2*n - 1 ; j ++){
            if(board[i][j] == '*') cout << '*';
            else cout << " ";
        }
        cout << '\n';
    }
    
}


