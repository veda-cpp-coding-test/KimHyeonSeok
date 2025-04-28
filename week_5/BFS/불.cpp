#include<bits/stdc++.h>
using namespace std;

struct e{
    int x;
    int y;
};
int t;

int w,h;
string board[1'001];


int dist_e[1'001][1'001];
int dist_f[1'001][1'001];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> t;

    while(t--){
        bool isPos = false ; 
        queue<e> fq;
        queue<e> eq;
        cin >> w >> h ;
        
        for(int i = 0 ; i < h; i ++) {
            fill(dist_e[i],dist_e[i]+w,-1);
            fill(dist_f[i],dist_f[i]+w,-1);
            
        }

        
        for(int i = 0 ; i < h ; i ++) {            
            cin >> board[i];
            for(int j = 0 ; j < w; j ++){
                if(board[i][j] == '@'){
                    eq.push({i,j});
                    dist_e[i][j] = 0;
                } else if(board[i][j] == '*'){
                    fq.push({i,j});
                    dist_f[i][j] = 0;
                }
            }
        }

        // for(int i = 0 ; i < h ; i ++ ){
        //     for(int j = 0 ; j < w ; j ++){
        //         cout << board[i][j] << ' ';
        //     }
        //     cout <<'\n';
        // }


        while(!fq.empty()){
            e cur = fq.front(); fq.pop();
            
            for(int dir = 0 ; dir < 4 ; dir++){
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];

                if(nx<0 || ny < 0 || nx>= h || ny >= w) continue;
                if(dist_f[nx][ny] != -1 || board[nx][ny] == '#' ) continue;
                
                dist_f[nx][ny] = dist_f[cur.x][cur.y] + 1;
                fq.push({nx,ny});

            }
        }





        while(!eq.empty() && (!isPos)){
            e cur = eq.front(); eq.pop();
            

            for(int dir = 0 ; dir <4 ; dir++){
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(nx < 0 || nx >= h || ny <  0 || ny >= w){
                    cout << dist_e[cur.x][cur.y] + 1 <<'\n' ;
                    isPos = true;
                    break; 
                }

                if(dist_e[nx][ny] != -1 ||  board[nx][ny] == '#'){
                    // cout << nx << ' ' << ny << '\n';
                    continue;
                } 
                if(dist_f[nx][ny] != -1 && dist_f[nx][ny] <= dist_e[cur.x][cur.y] + 1) continue;
                dist_e[nx][ny] = dist_e[cur.x][cur.y] + 1;
                eq.push({nx,ny});   
            }
        }

        // for(int i = 0 ; i < h ; i ++){
        //     for(int j = 0 ; j < w ; j ++){
        //         cout << dist_f[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        // for(int i = 0 ; i < h ; i ++){
        //     for(int j = 0 ; j < w ; j ++){
        //         cout << dist_e[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        if(!isPos) cout << "IMPOSSIBLE\n";


    }
}