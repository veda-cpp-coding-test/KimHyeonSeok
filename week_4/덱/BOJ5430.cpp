//AC 
#include<bits/stdc++.h>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t; 
    while(t--){
        string cmd , arr;
        deque<int> dq;
        bool isWrong = false;
        bool isReverse =false;
        int n ;
        cin >> cmd >> n  >> arr;

        int idx = 1; // arr[0] == '['
        for(int i = 0; i < n; ++i){
            int num = 0;
            while(isdigit(arr[idx])){
                num = num * 10 + (arr[idx] - '0');
                idx++;
            }
            dq.push_back(num);
            idx++; // skip ',' or ']'
        }
        
        //RD 연산
        for(int i = 0 ; i < cmd.size(); i ++){
            if(cmd[i] == 'R'){
                // reverse(dq.begin(),dq.end());
                isReverse = !isReverse;
            }else if (cmd[i] == 'D'){
                if(dq.empty()) {
                    isWrong = true;
                    break;
                }
                else {
                    if(isReverse) dq.pop_back();
                    else dq.pop_front();
                }
                
            }
        }
        if(isReverse)    reverse(dq.begin(),dq.end());

        //출력부
        if(isWrong) cout << "error" << '\n';
        else{
            cout << '[';
            for(int i = 0 ; i < dq.size(); i++) {
                cout << dq[i];
                if(i + 1 != dq.size())  cout << ',';
            }
            cout << ']' << '\n';
        }
        
    }
}



