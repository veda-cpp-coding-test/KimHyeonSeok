#include<bits/stdc++.h>
using namespace std;

#define CNT 5
int a[CNT];


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int sum = 0;
    for(int i = 0 ; i < CNT ; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a,a+CNT);
    cout << sum / CNT  << "\n" << a[CNT/2] ;
}