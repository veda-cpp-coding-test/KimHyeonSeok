// [BOJ10844] 쉬운 계단 수 / 실버1 / DP / 0 ms / 2024 KB

/*
    1. 계단수 : 나 기준  옆의 숫자가 +-1 이 있다면 더 해준다. 
        이유는 그 전 옆의 숫자도 그 숫자까지의 계단 수의 개수를 가지고 있기 때문이다.
        d[x][y] :  10^x * y일때의 계단 수 총 개수
    2. 초기식 : d[1][1] ~ d[1][9] = 1 
    3. 점화식 : d[k][i] = d[k][i] +  d[k-1][i-1]      (i>0)
       점화식 : d[k][i] = d[k][i] +  d[k-1][i+1]      (i<9)

    4. 중간 중간 1'000'000'000 를 안 나눠주면 운 나쁘면 overflow
        4-1. (A + B) % C = (A % C + B % C) % C
        4-2. (A X B) % C = (A % C x B % C) % C
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD =  1'000'000'000;
int n ;
int d[101][10];
long long ans; 

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    
    d[1][1] = d[1][2] = d[1][3] = d[1][4] = d[1][5] =  d[1][6] =d[1][7] = d[1][8] = d[1][9] = 1;

    for(int digit = 2 ; digit <= n ; digit ++){
        for(int i = 0 ; i <=9 ; i ++){
            if(i != 0 ) d[digit][i] += d[digit-1][i - 1];
            if(i != 9 ) d[digit][i] += d[digit-1][i + 1];
            d[digit][i] %= MOD;
        }
    }

    for(int i = 0 ; i <= 9 ; i++) ans += d[n][i];
    ans %= MOD;

    cout << ans ;
}
