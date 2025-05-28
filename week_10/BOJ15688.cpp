// BOJ15688.cpp 수 정렬하기 5

/*  array's idx로 +1 처리하는 로직
    절댓값이므로 -1'000'000 을 고려하여 작성
    형 변환을 이용해 MX/2 가 1'000'000을 생각해.
    값이 있다면 --> for을 통해 여러번 출력
*/
#include<bits/stdc++.h>
using namespace std;


const int MX = 2'000'001;       
int arr[MX];
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n ;
    int tmp;
    for(int i = 0 ; i < n ; i ++){
        cin >> tmp;
        arr[tmp + MX/2] ++;
    }

    for(int i = 0 ; i < MX ; i ++){
        if(!arr[i]) continue;
        for(int j = 0 ; j < arr[i] ; j ++){
            cout << i - MX/2 << "\n";
        }
    }
    
}