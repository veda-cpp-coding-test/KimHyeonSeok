#include<bits/stdc++.h>
using namespace std;

int l;


int ans;
int st, en;
int f_st,f_en;

int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};

int dist[302][302];
void bfs(){
    for(int i = 0 ; i < l ; i ++ )    fill(dist[i],dist[i]+l,-1);
    queue<pair<int,int>> q;

    q.push({st,en});

    dist[st][en] = 0;

    while(!q.empty()){
        int cur_x,cur_y ;
        cur_x = q.front().first;
        cur_y = q.front().second; 

        q.pop();
        if(dist[f_st][f_en] != -1) return;
        for(int i = 0 ; i < 8; i ++){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if(nx < 0 || ny < 0 || nx >= l || ny >= l) continue;

            if(dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[cur_x][cur_y] + 1;

            q.push({nx,ny});
        }
    }
    

}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;

    cin >> t;

    while(t--){
        cin >> l;
        cin >> st >> en >> f_st >> f_en ;

        bfs();

        cout << dist[f_st][f_en] << '\n' ;
        
    }
}