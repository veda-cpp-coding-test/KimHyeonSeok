// [BOJ1941] 소문난 칠공주 / 골드3 / 백트래킹 / 60 ms / 2024 KB

/*
    1. solve 함수에서 7명을 뽑는다. 25C7 
        - base condition : k == 7
    2. is_valid 함수에서 조건 확인
        2-1 7명 연결 
        2-2 이다솜파 4명 포함 
    

    gpt가 말하길, path 보다 bit mask킹 이용하면 더 최적화 가능할 듯?
    
*/
#include<bits/stdc++.h>
using namespace std;

const int MX_LENGTH = 5; 
int ans;
char board[MX_LENGTH][MX_LENGTH];
bool vis[26];
vector<int> path;
bool is_valid(){
    queue<int> q;
    int cnt = 0;
    int scount = 0;
    bool isvis[MX_LENGTH][MX_LENGTH] = {};

    q.push(path[0]);
    cnt ++;
    isvis[path[0] / 5][path[0] % 5] = 1;
    if(board[path[0] / 5][path[0] % 5] == 'S') scount ++;


    while(!q.empty()){
        int cur = q.front(); q.pop();
        int x = cur / 5;
        int y = cur % 5 ;

        for(int dir = 0 ; dir < 4 ; dir ++){
            int nx = x + "2011"[dir] - '1';     // 1 -1 0 0
            int ny = y + "1120"[dir] - '1';     // 0  0 1 -1
            if(nx < 0 || ny < 0 || nx >= MX_LENGTH || ny >= MX_LENGTH) continue;
            
            int nxt = nx * 5 + ny ;
            if(isvis[nx][ny]) continue;
            if(find(path.begin(),path.end(),nxt) == path.end()) continue;

            isvis[nx][ny] = 1;
            cnt ++;
            q.push(nxt);
            if(board[nx][ny] == 'S') scount ++;
        }
    }
    return scount >=4 &&  cnt == 7 ;
}

void solve(int st, int k ){
    if(k == 7){
        if(is_valid()) ans ++ ;
        return;
    }

    for(int i =st; i <25; i ++){
        if(vis[i]) continue;

        vis[i] = 1;
        path.push_back(i);
        solve(i+1, k+1);
        path.pop_back();
        vis[i] = 0;

    }
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);


    for(int i = 0 ; i < MX_LENGTH; i ++)
        for(int j = 0 ; j < MX_LENGTH ; j ++)
            cin >> board[i][j];
    

    solve(0,0);

    cout << ans ;
}