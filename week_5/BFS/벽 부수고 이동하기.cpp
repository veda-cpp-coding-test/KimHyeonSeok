#include<bits/stdc++.h>
using namespace std;

struct e{
    int x;
    int y;
    int broken;
};
string board[1'002];
int dist [1'002][1'002][2];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m;
    cin >> n >> m ;

    for(int i = 0 ; i < n ; i ++)   cin >> board[i];
    
    for(int i = 0 ; i < n ; i ++ ) {
        for(int j = 0 ; j < m; j ++){
            fill(dist[i][j],dist[i][j]+2,-1);
        }
    }


    queue<e> q;

    q.push({0,0,0});
    dist[0][0][0] = 1;

    while(!q.empty()){
        int cur_x = q.front().x;
        int cur_y = q.front().y;
        int broken = q.front().broken;
        q.pop();
        if(cur_x == n-1 && cur_y == m-1) {
            cout << dist[cur_x][cur_y][broken];
            break;
        }
        
        for(int dir = 0 ; dir < 4; dir ++ ){
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(broken && board[nx][ny] =='1' ) continue;
            if(!broken && board[nx][ny] =='1'  && dist[nx][ny][1] == -1 ){// 과거 broken x 현재 broken o
                dist[nx][ny][1] = dist[cur_x][cur_y][broken] + 1;
                q.push({nx,ny,1});
            }else if(broken && board[nx][ny] == '0'  && dist[nx][ny][1] == -1){
                dist[nx][ny][1] =  dist[cur_x][cur_y][broken] + 1;
                q.push({nx,ny,1});
            }else if(!broken && board[nx][ny] == '0'  && dist[nx][ny][0] == -1 ){
                dist[nx][ny][0] =  dist[cur_x][cur_y][broken] + 1;
                q.push({nx,ny,0});
            }
        }
    }


    if(dist[n-1][m-1][0] == -1 && dist[n-1][m-1][1] == -1 ) {
        cout << -1 ;
    }
}



// 이미 broken 했을때, 어떻게 알아 ?  그럼 [x][y][1] 로 계속가겠지?
// broken 안했을때, nx,ny가 1일때 ->broken = 1 로 다음 큐 넣어 
// broken 안했을때, nx,ny가 0일대 -> broken = 0 으로 다음 큐 넣어 