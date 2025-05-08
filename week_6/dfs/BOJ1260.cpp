#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1'001];
bool vis[1'001];

void bfs(int root){
    queue<int> q;
    q.push(root);
    vis[root]=1;
    cout << root << ' ';
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]){
            if(vis[nxt]) continue;
            vis[nxt] = 1;
            cout << nxt << ' ';
            q.push(nxt);
        }
    }
}

void dfs(int cur){
    if(vis[cur]) return;
    vis[cur] = 1;
    cout << cur << ' ';
    for(int nxt : adj[cur]){
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m,v;

    cin >> n >> m >> v;

    for(int i = 0 ; i < m ; i ++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <=n ; i ++){
        sort(adj[i].begin(),adj[i].end());
    }
    dfs(v);

    fill(vis,vis+n+1,0);
    cout << '\n';
    bfs(v);

}