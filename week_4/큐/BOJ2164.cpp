//카드2 
#include<bits/stdc++.h>
using namespace std;

int n ;
queue<int> q;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n ;
    for(int i = 1 ; i <= n ; i ++) q.push(i);

    while(q.size() != 1 ){
        q.pop();
        q.push(q.front());
        q.pop();
    }

    cout << q.front();
}



