#include<bits/stdc++.h>
using namespace std;


void func(int a, int b, int n) {
    if (n == 0) return; // 0개를 옮길 일은 없다. 그냥 리턴.

    func(a, 6 - a - b, n - 1); // n-1개를 a → 중간 기둥으로
    cout << a << " " << b << '\n'; // 가장 큰 원판을 a → b로 이동
    func(6 - a - b, b, n - 1); // n-1개를 중간 기둥 → b로 이동
}



int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    
    cout << (1<<n) - 1 <<'\n';
    func(1,3,n);

}


// n == 2 
// 1 3 2
    // 1 2 1  
        // 1 3 0 
        //-> 1 2
        
        // 3 2 0
    // 1 3
        //  2 3 1
        //-> 2 3
    



// 수박 잣 같네 
