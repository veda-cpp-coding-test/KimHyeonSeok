// 에디터
#include<bits/stdc++.h>
using namespace std;

list<char> l;
list<char>::iterator it = l.begin();
string s;
int n ;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);


   
    cin >> s >> n ;
    // 시작은 begin() == end() 임
    for(const char& c : s)   l.insert(it,c);
    // 추가하면 자동으로 it = l.end() 가 됨.


    for(int i = 0 ; i < n ; i ++){
        char cmd;
        cin >> cmd;
        if(cmd == 'P'){
            char cmd2;
            cin >> cmd2;
            l.insert(it,cmd2);
        }else if(cmd == 'L'){
            if(it != l.begin()) it--;
        }else if(cmd == 'D'){   
            if(it != l.end()) it++;
        }else if(cmd == 'B'){
            if(it != l.begin()) {
                it--;
                it = l.erase(it);
            }
        }
    }
    for(list<char>::iterator it = l.begin(); it != l.end(); it++){
        cout << *it;
    }
}