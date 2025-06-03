// [BOJ1759] 암호 만들기 / 골드5 / 백트래킹 / 0 ms / 2024 KB
// [BOJ1759] 암호 만들기 / 골드5 / 백트래킹 / 0 ms / 2024 KB

/*
    문제 조건 : 중복 없음 & 오름차순 & 최소 한 개 의 모음, 두 개의 자음 
    
    solve()
        1. 재귀적으로 k 값을 증가시켜 L 개 만들어 출력함.
        2. 오름차순으로 탐색하여 출력하려면 inputed 배열 정렬 
        3. 사전순을 고려하여 selected 전 값과 비교
        4. 자음과 모음 분리하여 cnt값으로 활용
        5. 최소 한 개 의 모음, 두 개의 자음을 만족하는 것만 출력

    solve2()
        1. 재귀적으로 k값과 idx값을 넘겨서 L 개 만들어 출력함.
        2. 오름차순으로 탐색하여 출력하려면 char_inputed 배열 정렬
        3. idx값을 증가시키면서 solve2에 넘기면 중복을 제거할 수 있음.
        4. base condition에 도달하면 aeiou 와 아닌것을 찾아서 조건에 맞으면 출력.
*/

#include<bits/stdc++.h>
using namespace std;    

const int A_BASE = 97;
int l,c;
int inputed[16];        //solve
char char_inputed[16];  //solve2
int selected[16];
bool isused[16];
int isaeiou;
int isnotaeiou;
char ch;

void solve(int k){
   if(l == k){
    if(isaeiou >= 1 && isnotaeiou >= 2){
        for(int i = 0 ; i < l; i ++){
            cout << (char)(selected[i] + A_BASE);
        }cout <<"\n";
    }
        return;
   } 

   for(int i = 1 ; i <= c ; i ++){
        if(k != 0 &&selected[k-1] >= inputed[i] ) continue;
        if(inputed[i] + A_BASE == (int)'a') isaeiou++;
        else if(inputed[i] + A_BASE == (int)'e') isaeiou++;
        else if(inputed[i] + A_BASE == (int)'i') isaeiou++;
        else if(inputed[i] + A_BASE == (int)'o') isaeiou++;
        else if(inputed[i] + A_BASE == (int)'u') isaeiou++;
        else isnotaeiou++;
        selected[k] = inputed[i];
        solve(k+1);
        if(inputed[i] + A_BASE == (int)'a')     isaeiou--;
        else if(inputed[i] + A_BASE == (int)'e') isaeiou--;
        else if(inputed[i] + A_BASE == (int)'i') isaeiou--;
        else if(inputed[i] + A_BASE == (int)'o') isaeiou--;
        else if(inputed[i] + A_BASE == (int)'u') isaeiou--;
        else isnotaeiou--;
   }
}

void  solve2(int k, int idx){
   if(l == k){
        int isaeiou = 0;
        int isnotaeiou = 0;
        for(int i = 0 ; i < l ; i ++){
            if(char_inputed[selected[i]]       ==    'a') isaeiou++;
            else if(char_inputed[selected[i]]  ==   'e') isaeiou++;
            else if(char_inputed[selected[i]]  ==     'i') isaeiou++;
            else if(char_inputed[selected[i]]  ==    'o') isaeiou++;
            else if(char_inputed[selected[i]]  ==    'u') isaeiou++;
            else isnotaeiou++;
        }
        if(isaeiou >= 1 && isnotaeiou >= 2){
            for(int i =0 ; i < l ; i ++){
                cout << char_inputed[selected[i]] ;
            }cout << "\n";
        }


        return;
   } 

   for(int i = idx; i < c; i++){
        selected[k] = i;
        solve2(k+1,i+1);
   }
}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> l >> c;

    for(int i = 1 ; i <= c ; i ++){
        cin >> ch;
        inputed[i] = ch - A_BASE ;
        char_inputed[i-1] = ch;
        
    }

    // solve
    sort(inputed+1,inputed+c+1);
    solve(0);

    // solve2
    sort(char_inputed,char_inputed+c);
    // solve2(0,0);

}