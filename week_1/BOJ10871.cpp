#include<bits/stdc++.h>
using namespace std;

int n , x ;
int t;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> x;

    for(int i = 0 ; i < n ; i ++) {
        cin >> t ;
        if(t < x) cout << t << " ";
    }


}