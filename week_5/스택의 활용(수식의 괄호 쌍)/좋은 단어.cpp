#include <bits/stdc++.h>
using namespace std;

int ans;



int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n ;

    for(int i = 0; i <n ; i ++){
        string s;
        stack<char> st;
        cin >> s;

        for(int j = 0 ; j < s.size(); j++){
            if(st.empty()) st.push(s[j]);
            else{
                if(s[j] == st.top()){
                    st.pop();                            
                }else{
                    st.push(s[j]);
                }
            }
        }


        if(st.empty()) ans++;
        


        
    }

    cout << ans ;
}