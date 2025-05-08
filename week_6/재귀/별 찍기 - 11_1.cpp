#include<bits/stdc++.h>
using namespace std;

const int MX = (3 << 10 ) + 1;
const char star[3][6]={
    "  *  ",
    " * * ",
    "*****",
};

vector<pair<int,int>> ans ;

char board[MX][MX*2];

void solve(int x, int y,int n){

    if(n==1){
        // ans.push_back({x,y});
        for(int i = 0; i < 3; i++){
            for(int j = 0 ; j < 5; j ++){
                board[x+i][y+j] = star[i][j]; 
            }
        }
        return;
    }


    solve(x         ,y+3*n/2        ,n/2);
    solve(x+3*n/2  ,y               ,n/2);
    solve(x+3*n/2   ,y+3*n          , n/2);
}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i ++) fill(board[i],board[i] + 2*n -1, ' ');
    solve(0,0,n/3);

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < 2*n -1 ; j ++){

            cout << board[i][j];
        }
        cout << '\n';
    }


    // for(auto& i : ans){
    //     cout << i.first << ' ' << i.second << '\n';
    // }
}



// 6
//      *     
//     * *
//    *****
//   *     *
//  * *   * *
// ***** *****
// 0 3
// 3 0
// 3 6