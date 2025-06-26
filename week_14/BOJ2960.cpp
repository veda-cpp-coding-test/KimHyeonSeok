// [BOJ2960] 에라토스테네스의 체 / 실버4 / 수학 / 0 ms / 2024 KB
/*  
    1.  2 부터 n 까지 순회
    2. 소수이면 지우고 그 소수의 배수들은 지운다.
    3. n 까지 2번 반복
*/
#include<bits/stdc++.h>
using namespace std;


int n,k; 

int cnt;
int ans;

int arr[1'010];
bool state[1'010];

void solve(){
    state[1]= false;
    for(int i = 2 ; i <= n ; i ++  ){
        if(!state[i]) continue;
        arr[++cnt] =  i;
        state[i] = false;
        for(int j =  i*i ; j <=n ; j += i){
            if(!state[j]) continue;
            state[j] = false;
            arr[++cnt] =  j;

        }
    }

}



int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> k;
    fill(state,state+n+1, true);

    solve();
    cout << arr[k];
}