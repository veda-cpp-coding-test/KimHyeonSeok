// DFS 스페셜 저지.cpp
#include<bits/stdc++.h>
using namespace std;

const int MX = 100'001;
vector<int> adj[MX];
int vis_order[MX];
int cmp[MX];

bool isValid = true;
int idx = 1;

void dfs(int cur,int par ){
    for(int nxt : adj[cur]){
        if(nxt == par) continue;
        if (cmp[idx+1] != nxt){
            isValid =false;
            return;
        }
        idx++;
        dfs(nxt,cur);
    }
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n ;
    for(int i = 0 ; i < n - 1 ; i ++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1 ; i <= n ; i ++) cin >> cmp[i];

    for(int i = 1 ; i <= n ; i++ ){
        vis_order[cmp[i]] = i;              // ��� -> ������ ����
    }

    for(int i = 1 ; i <=n ; i++ ) 
        sort(adj[i].begin(),adj[i].end(),[](int a,int b){
        return vis_order[a] < vis_order[b];
    });

    // for(int i = 1; i <= n ; i++){
    //     for(int j = 0 ; j < adj[i].size() ;  j++){
    //         cout << adj[i][j] << ' ';

    //     }
    //     cout << '\n';
    // }

    dfs(1, 0);
    cout << isValid ;

    
}