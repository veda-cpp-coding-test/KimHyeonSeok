#include<bits/stdc++.h>
using namespace std;

int n;

int board[65][65];

string ans ={};
void solve(int x, int y, int n){

    bool chk = true;
    for(int i = x; i < x+n; i++){
        for(int j= y ; j < y+n; j++){
            if(board[x][y] != board[i][j]){
                chk = false;
                break;
            }
        }
        if(!chk) break;
    }
    if(chk){
        ans += (board[x][y] + '0');
        // cout << board[x][y];
        return;
    }

    ans+='(';
    solve(x,y,n/2);
    solve(x,y+n/2,n/2);
    solve(x +n/2,y,n/2);
    solve(x +n/2,y+n/2,n/2);
    ans += ')';
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n ;

    for(int i = 0 ; i < n ; i ++){
        string oneline;
        cin >> oneline;
        for(int j = 0 ; j < n ; j++){
            board[i][j] = oneline[j] - '0';
        }
    }


    // for(int i = 0 ; i < n ; i ++){
    //     for(int j = 0 ; j < n ; j++){
    //         cout << board[i][j] <<' ';
    //     }
    //     cout << '\n';
    // }
    solve(0,0,n);


    cout << ans;
}