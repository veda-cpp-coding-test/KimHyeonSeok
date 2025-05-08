// 색종이 만들기.cpp
#include<bits/stdc++.h>
using namespace std;

int ans[2];
int board[128][128];

void solve(int n, int x , int y){

    // ========================================= 여기서 board 하고 맞으면 재귀 탈출  안 맞으면 분할 
    bool chk =true;
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {    
            if(board[i][j] != board[x][y]) {
                chk = false;
                break;
            }
        }
        if(!chk) break; 
    }
    if(chk){
        ans[board[x][y]]++;
        return ;
    }  
    //=================================================


    solve(n/2,x,y);
    solve(n/2,x,y+n/2);
    solve(n/2,x+n/2,y);
    solve(n/2,x+n/2,y+n/2);
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n ;

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n; j++){
            cin >> board[i][j];
        }
    }

    solve(n,0,0);
    cout << ans[0] << '\n' << ans[1] ; 
}