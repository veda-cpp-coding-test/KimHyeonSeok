//덱
#include<bits/stdc++.h>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    deque<int> dq ;

    int n ;
    cin >> n ;

    for(int i = 0 ; i < n ;  i++ ){
        string cmd;
        int x;
        cin >> cmd ;
        if(cmd == "push_front"){
            cin >> x;
            dq.push_front(x);
        }else if(cmd == "push_back"){
            cin >> x;
            dq.push_back(x);
        }else if(cmd == "pop_front"){
            if(dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }else if(cmd == "pop_back"){
            if(dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }else if(cmd == "size"){
            cout << dq.size() << '\n';
        }else if(cmd == "empty"){
            cout << dq.empty() << '\n';
        }else if(cmd == "front"){
            if(dq.empty()) cout << -1 << '\n';
            else    cout << dq.front() << '\n';
        }else if(cmd == "back"){
            if(dq.empty()) cout << -1 << '\n';
            else    cout << dq.back() << '\n';
        }
    }
}



