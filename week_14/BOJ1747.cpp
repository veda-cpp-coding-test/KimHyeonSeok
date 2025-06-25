// [BOJ1747] 소수&팰린드롬 / 실버1 / 수학 / 180 ms / 2152 KB
/*  
    1. 소수인지 확인
        1-1. 아니라면 k+1 
    2. 팰린드롬인지 확인
        2-1. 아니라면 k+1 
*/

#include<bits/stdc++.h>
using namespace std;

const int MX = 1'000'000;
vector<bool> state(MX + 1,true);
int ans;
void sieve(int n){
    state[1] = false;
    for(int i = 2 ; i*i <= n ; i++){
        if(!state[i]) continue;     
        for(int j = i * i ; j <= MX; j +=i){
            state[j] = false;
        }
    }
}

int is_prime(int n){
    if(n==1 ) return 0;
    for(int i =2 ; i *i <=n ; i ++)
        if(n % i == 0) return 0;
    return 1;
}

void solve(int k){
    k-=1;
    while(++k)
    {
        // cout << k;
        // if(k == 100) return;
        bool is_valid = is_prime(k);
        if(!is_valid)  continue;
        // if(!state[k]) continue;
        string s1 = to_string(k);
        string s2(s1.rbegin(),s1.rend());
        // reverse(s1.begin(),s1.end());
        // cout << s1<< "\n";
        // cout << s2<< "\n";

        if(s1 == s2) {
            ans = k;
            break;
        }

        
    }    
    return;
}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);


    int n;
    cin >> n ;

    // sieve();
    solve(n);
    cout << ans;
    
}