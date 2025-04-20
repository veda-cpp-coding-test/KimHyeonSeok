//큐
#include<bits/stdc++.h>
using namespace std;

int n ;
queue<int> q;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);


    cin >> n ;

    for(int i = 0 ; i < n ; i ++ ){
        string cmd;
        cin >> cmd;
        if(cmd == "push"){
            int x;
            cin >> x;
            q.push(x);
        }else if(cmd == "pop"){
            if(q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }else if(cmd == "size"){
            cout << q.size() << '\n';
        }else if(cmd == "empty"){
            cout << q.empty() << '\n';
        }else if(cmd == "front"){
            if(q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
            }
        }else if(cmd == "back"){
            if(q.empty()) cout << -1 << '\n';
            else {
                cout << q.back() << '\n';
            }
        }
    }
}



