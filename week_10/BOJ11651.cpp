// BOJ11651.cpp 
//좌표 정렬하기 2

/*
    1. 1순위 y 오름차순, 2순위 x 오름차순
    2. 변태적인 테크니션으로 y,x 를 바꿔서 처리하면 sort함수 바로 적용하면된다.
    3. sort는 1순위 오름차순이고 1순위가 같다면 자동 2순위 오름차순인걸 이용 
    4. 직접 cmp 람다함수를 이용해서 해도 된다.
*/
#include<bits/stdc++.h>
using namespace std;

const int MX = 100'000;
pair<int,int> a[MX];
int n; 
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    
    cin >> n ;
    for(int i = 0 ; i < n ; i ++){
        int x, y;
        cin >> x >> y;
        a[i] = {y,x};
    }

    sort(a,a+n,[&](const pair<int,int> aa , const pair<int,int>bb){
        if(aa.first == bb.first) return aa.second < bb.second;
        return aa.first < bb.first;
    });

    // sort(a,a+n);
    for(int i = 0 ; i < n ; i ++){
        cout << a[i].second << ' ' << a[i].first  << "\n";
    }
}