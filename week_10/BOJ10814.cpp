// BOJ10814.cpp 
//나이순 정렬

/*
    1. 나이와 이름 입력 받는다.
    2. 1순위 : 나이는 오름차순, 2순위 : 들어온 순서
    3. 그냥 sort 하게 되면 이름도 오름차순이 된다.
    4. 따라서 stable_sort 하면 먼저 입력된 것 부터 오게된다.
*/
#include<bits/stdc++.h>
using namespace std;

pair<int,string> arr[100'000];

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n; 
    cin >> n ;

    int age; string name;
    for(int i = 0 ; i < n ; i ++){
        cin >> age >> name;

        arr[i] = {age,name};
    }

    stable_sort(arr,arr+n,[](const pair<int,string>& a,const pair<int,string>& b ){
        return a.first < b.first;
    });

    for(int i = 0 ; i < n ; i ++){
        cout << arr[i].first << ' ' << arr[i].second <<"\n";
    }
}