//스택 수열
#include<bits/stdc++.h>
using namespace std;


int n ;
stack<int> st;
int num;
bool isnotValid ;
string ans ;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n ;
    
    int idx = 1; 
    for(int i = 1 ; i <= n; i++){
        cin >> num;

        while(num >= idx ){
            st.push(idx);
            idx +=1;
            ans+="+\n";
        }
        if(st.top() != num ) {
            isnotValid = true;
            break;
        }
        st.pop();
        ans+="-\n";
            
    }


    if(isnotValid)  cout << "NO";
    else cout << ans ;
}




// 1 2 3 4
// 1 2 3
// 1 2
// 1 2 5 6 
// 1 2 5
// 1 2 5 7
// 1 2 5 7 8 
// 1 2 5 7 
// 1 2 5 
// 1 2 
// 1
// 
