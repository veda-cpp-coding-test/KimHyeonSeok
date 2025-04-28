#include<bits/stdc++.h>
using namespace std;

string s;
stack<char> st;
int ans;
bool isnotValid;
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);


    cin >> s ;
    int mul = 1;
    for(int i = 0 ; i < s.size(); i ++){
        if(s[i] == '('){
            st.push(s[i]);
            mul = mul*2;
        }else if(s[i] == '['){
            st.push(s[i]);
            mul = mul*3;
        } else if(s[i] == ')'){
            if(s[i-1] == '[' || st.empty()){
                isnotValid = true;
                break;
            }
            st.pop();
            if(s[i-1] == '(')  ans = ans + mul ;
            mul = mul / 2; 

        } else if(s[i] == ']'){
            if(s[i-1] == '(' || st.empty()){
                isnotValid = true;
                break;
            }
            st.pop();
            if(s[i-1] == '[')  ans = ans + mul ;
            mul = mul / 3; 
        }
        // cout << ans << ' ';
    }

    if(isnotValid) cout << 0 ;
    else cout << ans ;

}