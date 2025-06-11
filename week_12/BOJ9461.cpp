// [BOJ9461] 파도반 수열 / 실버3 / DP / 0 ms / 2020 KB

/*  
    0. 잘 생각해보면, 두 배보다 작게 커지는 것을 알 수 있다. 따라서 백번만 해도 2^100 승이므로
        2^100 ~= (10^3)^10 이므로 10^30이다. int에 담을 수 있나 ? x
        따라서 long long 은 최대 2^64 = 10^19 에 담아야 한다.
    1. dp 는 p(1) ~ p(10) 의 정삼각형의 변의 길이 
    2. 점화식을 세워보면 dp[i] = dp[i-3] + dp[i-2]
    */

#include<bits/stdc++.h>
using namespace std;

long long  dp[110] = {1, 1, 1, 2, 2, 3, 4, 5, 7, 9,};
int t ;
int n;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> t;

    dp[1] = 1; dp[2] = 1 ; dp[3] = 1;

    for(int i = 4; i <= 100; i ++){
        dp[i] = dp[i-3] + dp[i-2] ;
    }

    
    while(t--){
        cin >> n ;
        cout << dp[n] << "\n";
    }



}

// cout << dp[100];
// 8'888'550'648'971

// for(int i = 10; i<=30; i++){
//     cout << dp[i] << " ";
// }
