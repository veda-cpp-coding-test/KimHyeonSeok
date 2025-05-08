// 알고리즘 수업 - 깊이 우선 탐색 1.cpp
#include<bits/stdc++.h>
using namespace std;

const int MX = 100'001;
int vis[MX];
vector<int> adj[MX];

int idx;
void dfs(int cur){
    if(vis[cur]) return ;
    vis[cur] = (++idx);
    for(int nxt : adj[cur]){
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m,r;
    cin >> n >> m >> r;

    for(int i = 0 ; i < m ; i ++){
        int u,v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n ; i++ ) sort(adj[i].begin(),adj[i].end());

    dfs(r);

    for(int i = 1; i <= n; i++) {
        cout << vis[i] << '\n';
    }
}