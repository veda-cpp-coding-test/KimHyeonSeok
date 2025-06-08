// [BOJ2448] 별 찍기 - 11 / 골드4 / 재귀 / 416 ms / 20464 KB

/*  


*/
#include<bits/stdc++.h>
using namespace std;

const int MX = (3 << 10 ) + 1;
int n;

char board[MX][2 * MX];
const char star[3][6] ={
    "  *  ",
    " * * ",
    "*****"
};

void solve(int x, int y ,int n){
    if(n == 3){
        
        board[x][y] = '*';
        board[x+1][y-1] = board[x+1][y+1] = '*';
        board[x+2][y-2] = board[x+2][y-1] = board[x+2][y] = board[x+2][y+1] = board[x+2][y+2] = '*';
        return;
    }
    

    solve(x, y, n/2);
    solve(x+n/2, y -n/2 , n/2);
    solve(x+n/2, y + n/2 , n/2);
}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    solve(0,n-1,n);

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < 2 * n -1  ; j ++){
            if(board[i][j] == '*') cout << "*";
            else cout << " ";
        }cout << "\n";
    }
}