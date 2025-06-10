// [BOJ11559] Puyo Puyo / 골드4 / 시뮬레이션 / 0 ms / 2028 KB

/*  
    1. 연쇄가 있었는지 확인한다. isPang으로 시작은 true로 하고 while   
        문 안에서는 false로 초기화
        방문 배열도 초기화 
    2. down_1(),down_2() 중력 받아서  내리기
        물론 첫번째때는 내린 진 상태라 필요없다. 하지만 그냥 해도 무방하다.
    3. 12 x 6 에서 한 놈만 걸려라식으로 bfs로 찾는다.
        3-1 찾았다면, 연쇄가 있었으므로 다음 while문 반복 가능
        3-2 찾지못했다면, == 다 찾았으므로, while 탈출한다.
    4. 연쇄 횟수 출력
*/
#include<bits/stdc++.h>
using namespace std;

bool isPang = true;
bool vis[12][6];
string board[12];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int ans;

void bfs(int x,int y){
    vis[x][y] = 1;
    char color = board[x][y];
    queue<pair<int,int>> q;
    vector<pair<int,int>> p;
    q.push({x,y}); p.push_back({x,y});
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir = 0 ; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            
            if(nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
            if(vis[nx][ny]) continue;
            if(board[nx][ny] == '.') continue;
            if(board[nx][ny] != color) continue;
            vis[nx][ny] =true;
            q.push({nx,ny});
            p.push_back({nx,ny});
        }
    }

    if(p.size() >= 4) {
        isPang = true;
        for(auto cur : p)
            board[cur.first][cur.second] = '.';
    }
    
}

void down_1(){
        for(int j = 0 ; j <6 ; j ++){
            queue<char> st;
            for(int i = 11 ; i >= 0 ; i --){
                if(board[i][j] != '.') st.push(board[i][j]);
            }
            for(int i = 11; i >= 0 ; i--){
                if(!st.empty()) {
                    board[i][j] = st.front(); st.pop();
                } 
                else board[i][j] = '.';
            }
        }
}

void down_2(){
        for(int j = 0 ; j <6 ; j ++){
            int idx = 11;
            for(int i = 11 ; i >= 0 ; i--){
                if(board[i][j] != '.')
                    board[idx--][j] = board[i][j];
            }
            for(int i = idx ; i >=0 ; i--){
                board[i][j] ='.';
            }
        }
}



int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    for(int i = 0 ; i < 12 ;  i++)
        cin >> board[i];
    
    
    while(isPang){
        isPang = false;
        for(int i = 0; i <12 ; i ++)fill(vis[i],vis[i]+6,false);


        // down_1();
        down_2();
        // cout << "After chain #" << ans << ":\n";
        // for (int i = 0; i < 12; i++)
        //     cout << board[i] << "\n";
        // cout << "\n";

        // 뿌요 연쇄  탐색 
        for(int i = 0 ; i < 12 ; i ++){
            for(int j = 0 ; j < 6; j ++){
                if(vis[i][j]) continue;
                if(board[i][j] == '.') continue;
                bfs(i,j);
            }
        }


        
        if(isPang) ans ++;
    }
 
    
    cout << ans ;
}