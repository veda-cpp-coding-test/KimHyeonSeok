#include<bits/stdc++.h>
using namespace std;

int ans;
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    stack<char> st;
    cin >> s ;
    
    for(int i = 0 ; i < s.size() ; i ++){
        if(s[i] == '('){
            st.push('(');
        }
        else{
            if(s[i-1] == '('){
                st.pop();
                ans += st.size();
            }
            else{
                st.pop();
                ans ++ ;
            }
        }
    }


    cout << ans ;

}