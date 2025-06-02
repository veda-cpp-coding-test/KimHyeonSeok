// [BOJ5648] 역원소 정렬 / 실버5 / 정렬 II / 0 ms / 9832 KB
// [BOJ5648] 역원소 정렬 / 실버5 / 정렬 II / 0 ms / 10108 KB

/*
    0. 10^12 이므로 int 형 x 
    solve()
        1. arr 배열로 입력 받기
        2. 나머지 연산을 통해 arr[i]의 뒤집기
        3. arr[i] 에 뒤집은 값 넣기
        4. 정렬하여 출력
    solve2()
        1. string으로 입력받기
        2. string 객체의 메소드인 reverse를 이용해 뒤집기
        3. string to long long == stoll 으로 타입 변환
        4. 정렬하여 출력
*/
#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[1'000'000];
vector<long long> vec;
void solve(){
    for(int i = 0 ; i < n ; i ++) cin >> arr[i];

    for(int i = 0 ; i < n ; i ++){  
        long long ori = arr[i];
        long long rev = 0;
        while(ori != 0){
            rev = rev * 10 ;
            rev +=(ori % 10) ; 
            ori /= 10;
        }
        arr[i] = rev;
    }
    sort(arr,arr+n);
    for(int i = 0 ; i < n ; i ++ ) cout << arr[i] << '\n';
    
}

void solve2(){
    for(int i = 0 ; i < n ; i ++){
        string s;
        cin >> s;
        reverse(s.begin(),s.end());
        vec.push_back(stoll(s));

    }
    sort(vec.begin(),vec.end());

    for(auto& a : vec ) cout << a << "\n";
}
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n ; 
    // solve();
    solve2();


    
}
