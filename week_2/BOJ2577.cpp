#include<bits/stdc++.h>
using namespace std;

int a,b,c,mul;
int arr[11];    
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> a >> b >> c ;
    mul = a * b * c ;
    
    while(mul != 0){         // 각 자리 수를 배열에 저장함.
        arr[mul % 10] ++ ;
        mul /= 10 ;
    }

    for(int i = 0 ; i < 10 ; i ++) cout << arr[i] << "\n";
}