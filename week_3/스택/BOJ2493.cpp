//탑
#include<bits/stdc++.h>
using namespace std;

int n,h;
stack<pair<int,int>> st;        //idx,h

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    
    for(int i = 1 ; i <= n ; i++){
        cin >> h;
        while(!st.empty() && st.top().second < h)st.pop();
        if(st.empty()) cout << 0 << ' ' ;
        else cout << st.top().first << ' ';
        st.push({i,h});
    }

}