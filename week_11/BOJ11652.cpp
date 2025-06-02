// BOJ11652.cpp 
//  카드
/*
    solve()
        1. 정렬된 배열을 0부터 n 까지 순회한다.
        2. i가 0 이거나 현재 값과 과거 값이 같으면  cnt 증가
        3. i != 0 이고 현재 값과 과거 값이 다르면 
            3-1. mxcnt 값보다 cnt 값이 크면 mxcnt, mxval 갱신
            3-2. 정렬이 되었으므로 같을 경우 처리 안해주면 자동으로 작은 수가 mxval
            3-3. 현재 값이 시작이므로 cnt가 1
        4. 마지막으로 저장되어 있는 mxcnt 값과 cnt 값이  다를 수 있으므로 확인 후
            4-1. mxcnt 이 작으면 마지막값이 제일 많으므로 arr[n-1] return 
            4-2. mxcnt 이 크면 과거값이 제일 많으므로 mxval return;

    solve2()
        1. map 에 정렬 기능이 있고 입력을 받는다. 
        2. map은 sort() 쓸 수 없으므로 vec 변환 후
        3. 등장횟수 값의 내림차순, 같을 경우 작은 키 반환하도록 작성
        4. vec.front().first 로 맨 앞 retrun
    
    solve3()
        1. unordered_map 을 이용하여 입력 받는다. <입력 값, 등장 횟수>
        2. 입력 받자마자 cnt, max_cnt 비교 
            2-1. cnt 가 max_cnt 보다 클 경우 갱신이 일어나야 하므로 cnt, ans 갱신
            2-2.            "       같을 경우 + num과 ans 중 더 작은 값  ans에 갱신 
*/
#include <bits/stdc++.h>
using namespace std;

long long arr[100'001];
int n;

long long solve(){
    int cnt = 0 ;
    long long mxval = -(1ll << 62) - 1;
    int mxcnt = 0 ;

    for(int i = 0 ; i < n ; i ++){
        if(i == 0 || arr[i] == arr[i-1]) cnt ++;
        else{
            if(cnt > mxcnt) {
                mxcnt = cnt;
                mxval = arr[i-1];
            }
            cnt = 1 ;
            }
    }
    if(mxcnt < cnt ) return arr[n-1];
    else return  mxval;
}

long long solve2(){
    map<long long,int> mp ;
    for(int i = 0 ; i < n ;  i++ ){
        mp[arr[i]]++ ;
    }

    vector<pair<long long, int>> vec(mp.begin(), mp.end());
    sort(vec.begin(), vec.end(), [](const pair<long long, int>& a, const pair<long long, int>& b) {
        if (a.second != b.second) return a.second > b.second; // count 큰 순
        return a.first < b.first; // count 같으면 작은 수가 우선
    });

    return vec.front().first;
}
long long solve3(){
    unordered_map<long long,int> um;
    long long num,ans = 0 ;
    int max_cnt = 0 ;
    for(int i = 0 ; i < n ; i ++){
        // cin >> num ;     // 입력받는 대신 배열에서 가져오기
        num = arr[i];
        int& cnt = um[num];
        cnt ++ ;
        if(cnt > max_cnt) {
            ans = num;
            max_cnt = cnt;
        } else if(cnt == max_cnt){
            ans = min(num,ans);
        }
    }

    return ans;
}
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);


    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);


    // cout << solve() ; 
    // cout << solve2();
    cout << solve3();




    
}
