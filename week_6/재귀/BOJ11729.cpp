#include<bits/stdc++.h>
using namespace std;


void func(int a, int b, int n) {
    if (n == 0) return; // 0���� �ű� ���� ����. �׳� ����.

    func(a, 6 - a - b, n - 1); // n-1���� a �� �߰� �������
    cout << a << " " << b << '\n'; // ���� ū ������ a �� b�� �̵�
    func(6 - a - b, b, n - 1); // n-1���� �߰� ��� �� b�� �̵�
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
    



// ���� �� ���� 
