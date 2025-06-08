// [BOJ16987] 계란으로 계란치기 / 골드5 / 백트래킹 / 64 ms / 2020 KB

/*
    1. eggs pair 배열에 입력 저장 
    2. 0 번 계란부터 손에 듬.
    3. 같은 계란, 깨져있는 계란 패스.
    4. 이미 깨져있는 계란은 패스하고 다음 계란으로 이동
    5. 깨트릴 계란이 없으면 패스
*/
#include<bits/stdc++.h>
using namespace std;
int n ;
int ans;
pair<int,int> eggs[9];
void solve(int cur){
    if(cur == n){
        int cur_cnt = 0;
        for(int i = 0 ; i < n ; i ++) if(eggs[i].first <= 0) cur_cnt++;
        ans = max(ans, cur_cnt);
        return;
    }

    if(eggs[cur].first <= 0){
        solve(cur+1);
        return;
    }


    bool hit = false;
    for(int i = 0; i < n ; i++){
        if(i == cur ) continue;
        if(eggs[i].first <= 0) continue;

        eggs[cur].first -= eggs[i].second;
        eggs[i].first -= eggs[cur].second;
        hit = true;
        solve(cur+1);

        eggs[cur].first += eggs[i].second;
        eggs[i].first += eggs[cur].second;


    }


    if(!hit){
        solve(cur+1);
    }
    





}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n ;

    for(int i = 0 ; i < n ; i ++){
        int s,w;
        cin >> s >> w;
        eggs[i] = {s,w};
    }
    solve(0);

    cout << ans ;
}