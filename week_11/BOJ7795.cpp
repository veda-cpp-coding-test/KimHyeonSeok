// [BOJ7795] 먹을 것인가 먹힐 것인가 / 실버3 / 정렬 II / 632 ms / 2332 KB
// [BOJ7795] 먹을 것인가 먹힐 것인가 / 실버3 / 정렬 II / 32 ms / 2756 KB

/*
    solve()
        1. arr1, arr2 배열에 A,B 입력 받기
        2. arr1, arr2 배열 정렬
        3. arr1 작은 것부터 arr2 와 비교하기
            3-1. arr1 가 작거나 같으면 다음 arr1 원소로 비교
            3-2. arr1이 크다면 개수 증가
    solve2()
        1. 동적 배열로 A+B 입력 받기 second로 0,1 구분
        2. 동적 배열 정렬
        3. 동적 배열 순회하면서 second 비교
            3-1. second로 A가 나오면 이전 cnt값을 개수에 추가
            3-2. second로 B가 나오면 cnt값 증가 
*/
#include <bits/stdc++.h>
using namespace std;

int t;
int n,m;
const int MX = 20'001;
long long arr1[MX];
long long arr2[MX];

void solve(){
    while(t--){
        cin >> n  >> m ;

        for(int i = 0 ; i < n ; i ++) cin >> arr1[i];
        for(int i = 0 ; i < m ; i ++)  cin >> arr2[i];
        sort(arr1,arr1+n);sort(arr2,arr2+m);

        int ans = 0 ;
        for(int i = 0 ; i < n; i ++){
            for(int j = 0 ; j < m ; j ++){
                if(arr1[i] <= arr2[j]) break;
                ans++;
            }
        }

        cout << ans << "\n";
    }
}

void solve2(){
    
    int num;
    for(int tc = 0; tc < t ; tc++){
        cin >> n >> m ;
        vector<pair<int,int>> vec(n+m);
        for(int i = 0 ; i < n + m ; i ++){
            cin >> num;
            if(i < n ) vec[i] = {num,0};
            else vec[i] = {num,1}; 
        }
        sort(vec.begin(),vec.end());
        int cnt = 0 ;
        int ans = 0 ;
        for(int i = 0 ; i < n + m ; i ++){
            if(vec[i].second == 0){
                ans += cnt;
            }else{
                cnt ++;
            }
        }
        cout << ans << "\n";
    }
}
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);



    cin >> t;


    // solve();
    solve2();


    
}
