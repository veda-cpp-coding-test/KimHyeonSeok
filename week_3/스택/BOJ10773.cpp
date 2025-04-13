//제로
#include<bits/stdc++.h>
using namespace std;

int k;
stack<int> st;
int num;
int ans;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> k;

    for(int i = 0 ; i < k ; i ++){
        cin >> num;
        if(num == 0) st.pop();
        else st.push(num);
    }
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    cout << ans ;
}