//회전하는 큐
#include<bits/stdc++.h>
using namespace std;

int n,m;
deque<int> dq;
int ans ;


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);


    cin >> n >> m ;

    for(int i = 1 ; i <= n ; i ++) dq.push_back(i);


    for(int i = 0 ; i < m ; i++){
        int query;
        cin >> query;

        deque<int>::iterator it =  find(dq.begin(),dq.end(),query);
        int idx = it - dq.begin();
        
        // cout << idx << ' ';
        while(dq.front() != query){
            if(dq.size() - idx   >  idx ){
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else{
                dq.push_front(dq.back());
                dq.pop_back();
            }

            ans++;
        }

        dq.pop_front();
    }

    cout << ans ;

}



// 0 1 2 3 4 5 6 7 8 9 
// ex) 4 일때, 10 - 4 > 4 
