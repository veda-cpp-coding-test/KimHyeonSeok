#include <bits/stdc++.h>
using namespace std;

int n, x;
int a[100'001];

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    cin >> x;

    sort(a, a + n);

    int en = n - 1;                                 //end pointer
    int ans = 0;

    for(int st = 0; st < en; st++) {                //start pointer
        while(st < en && a[st] + a[en] > x) en--;   // 유효 포인터 확인 && 두 수의 합이 x보다 큰지 확인 
        if(st >= en) break;                         //  while문에 의해서 유효 포인터가 아닐 경우 더 이상 볼 필요가 없으므로 for문 멈춤.
        if(a[st] + a[en] == x) ans++;               // 두 수의 합과 대상 x  확인.
    }

    cout << ans << '\n';
    return 0;
}

