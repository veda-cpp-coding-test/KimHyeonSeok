// 키로거
#include<bits/stdc++.h>
using namespace std;

int t;
string s;


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> t;

    for(int i = 0 ; i <t ; i ++ ){
        cin >> s;
        
        list<char> l ;
        list<char>::iterator it = l.begin();
        for(const char& c : s)    {
            if(c == '<'){
                if(it != l.begin()) it--;
            }else if (c == '>'){ 
                if(it != l.end()) it++;
            }else if(c == '-'){
                if(it != l.begin()) {
                    it --;
                    it = l.erase(it);
                }
            }else {
                l.insert(it,c);
            }
        }
        
        for(auto it = l.begin(); it != l.end(); it++){
            cout << *it;
        }
        cout << '\n';
    }
}