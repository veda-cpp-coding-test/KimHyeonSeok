// [BOJ15663] N과 M (9) / 실버2 / 백트래킹 / 12 ms / 2020 KB
// [BOJ15663] N과 M (9) / 실버2 / 백트래킹 / 28 ms / 4272 KB

/*  
    1. 배열을 입력 받아 정렬하기.
    2. tmp 변수를 이용해 같은 자리 중복 제거
    

    solve2()
        1. set을 이용하여 중복 제거 
*/
#include<bits/stdc++.h>
using namespace std;

int n,m;
bool isused[10];
int arr[10];
int sel[10];

set<vector<int>> sv;
void solve(int k){
    if(k ==m){
        for(int i = 0 ; i < m ; i ++) cout << sel[i] << ' ';
        cout << "\n";
        return ;
    }

    int tmp = -1;
    for(int i = 1 ; i <= n ; i ++){
        if(isused[i]  )continue;
        if(tmp == arr[i])   continue;
        isused[i] = 1;
        sel[k] = arr[i];
        tmp = sel[k];
        solve(k+1);
        isused[i] = 0;

    }
}

void solve2(int k){
    if(k ==m){
        vector<int> vec(sel,sel+m);
        sv.insert(vec);
        return ;
    }
    for(int i = 1 ; i <= n ; i ++){
        if(isused[i]  )continue;
        isused[i] = 1;
        sel[k] = arr[i];
        solve2(k+1);
        isused[i] = 0;

    }
}

void solve2_ans(){
    solve2(0);
    for(auto ans1 : sv){
        for(auto ans2 : ans1){
            cout << ans2 << ' ';
        }cout << "\n";
    }
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m ;

    for(int i = 1 ; i <= n ; i ++) cin >> arr[i];
    sort(arr+1,arr+n+1);

    // solve(0);


    solve2_ans();
}