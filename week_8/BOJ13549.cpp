// [BOJ13549] 숨바꼭질 3 / 골드5 / BFS / 0 ms / 2544 KB

/*  
    1. cur * 2 는 가중치가 없고, cur + 1 , cur -1 은 +1 만큼의 가중치가 있다.
    2. 따라서 bfs 알고리즘에서, cur * 2 부터 우선 적용하면, 자연스럽게 dist가 채워져서 먼저 가능하다.
    3. 이때, 주의할 점은 더 수가 작은 경로를 먼저 해야 최적의 경로라 cur -1 부터 해야됨.
    4. 따라서 cur * 2 -> cur -1 -> cur +1 순으로 해야됨.
    5. dist[k] 가 채워질 때 멈춘다.

    위의 방법은 고려할 것이 많아서
    가중치를 고려한 덱이나, 최단경로 다익스트라 같은 걸 쓰면 좋을듯 ?

*/
#include<bits/stdc++.h>
using namespace std;

const int MX = 100'010;
int n, k;
int dist[MX];

void solve(){

    fill(dist,dist+MX,-1);
    queue<int> q;
    q.push(n);
    dist[n] = 0;

    while(!q.empty() && dist[k] == -1){
        int cur = q.front(); q.pop();

        for(auto nxt : {cur * 2 , cur - 1, cur + 1}){
            
            if(nxt < 0 || nxt >= 100'001) continue; // 범위 확인
            if(dist[nxt] != -1 ) continue;      // 방문여부  

            if(nxt == cur * 2) dist[nxt] = dist[cur];
            else                dist[nxt] = dist[cur] + 1;
            
            q.push(nxt);
        }
    }

    cout << dist[k];

}


void solve2(){
    fill(dist,dist+MX,-1);

    // 다음에 풀때 해보자
}
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);




    cin >> n >> k;

    solve();

}