#include<bits/stdc++.h>
using namespace std;

#define CNT 9
int height[CNT];

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    
    for(int i = 0 ; i < CNT ; i ++ ) cin >> height[i];

    sort(height,height+CNT);
    int sel[CNT] = {0,0,0,0,0,0,0,1,1};
    do{
        int sum = 0 ;
        for(int i = 0 ; i < CNT; i ++ ){
            if(sel[i] == 0){
                sum += height[i];
            }
        }
        if (sum == 100) break;
        
        
    }while(next_permutation(sel,sel+CNT));

    for(int i = 0 ; i < CNT; i ++){
        if (sel[i] == 1) continue;
        cout << height[i] << "\n";
    }
    
}