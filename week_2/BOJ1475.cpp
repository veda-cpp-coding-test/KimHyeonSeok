#include<bits/stdc++.h>
using namespace std;

int n;
int arr[10];
int ans;
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    

    cin >> n ;

    while(n != 0 ){         // 각 자리 수를 배열에 저장함.
        arr[n%10] ++ ;       
        n /= 10 ;
    }

    for(int i = 0 ; i < 10 ; i ++){
        if(i == 6 || i == 9) continue;
        ans = max(ans,arr[i]);
    }

    ans = max(ans,(arr[6]+arr[9]+ 1) / 2);      // (6, 9 는 더하고 +1) / 2 하여 최소 세트 계산 

    cout << ans ;
}