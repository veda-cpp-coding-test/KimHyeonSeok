// [BOJ14891] 톱니바퀴/ 골드5 / 시뮬레이션 / 0 ms / 2024 KB

/*
    1. string으로 입력받아 int로 만들기
    2. 회전 시킬 때, 도미노 처럼 전에 영향을 받는게 아니라 회전 하려고 할때, 한번에 결정된다. 
        따라서 4개의 톱니바퀴의 회전 방향을 결정
    3. ptr 배열을 활용하여 만나는 지점의 idx를 활용한다
        ex ) ptr[2][3] --> 2번,3번 톱니바퀴에 맞닿는 2번 톱니바퀴 idx
        3-1. 1,4번의 톱니바퀴는 한쪽씩 없다. 배열을 크게하여 예외처리
    
    4. int 배열에 N극이 0이고 S극이 1임을 활용하여 
        각 톱니바퀴에 1,2,4,8를 곱하여 출력
    
*/

#include<bits/stdc++.h>
using namespace std;

// #define test(i) baqui_##i

string inputed[5];
int n;
int baqui[5][8];
int ptr[6][6];
int ans;

void rotation(int x, int dir ){      // x 기준 dir

    if(dir == 1 )                   // 시계
    {
        ptr[x][x-1] =   (ptr[x][x-1] - 1 + 8) % 8;
        ptr[x][x+1] =   (ptr[x][x+1] - 1 + 8) % 8;

    } else if (dir == -1){          // 반시계

        ptr[x][x-1] =   (ptr[x][x-1] + 1) % 8;
        ptr[x][x+1] =   (ptr[x][x+1] + 1) % 8;

    }

}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    ptr[1][2] = ptr[2][3] = ptr[3][4] = 2;
    ptr[2][1] = ptr[3][2] = ptr[4][3] = 6;

    for(int i = 1; i <= 4 ; i ++)
        cin >> inputed[i] ;

    cin >> n;

    for(int i = 1 ; i <= 4;  i ++){
        for(int j = 0 ; j < 8; j ++){
            baqui[i][j] = inputed[i][j] - '0';
        }
    }



    for(int i = 0 ; i < n ; i ++){
        int num,dir;
        cin >> num >> dir ;

        int rev_dir = dir;

        int dirs[5] = {};
        
        int num_idx = num;
        dirs[num_idx] = dir;
        // + 방향으로 전파 
        while(num_idx < 4 && baqui[num_idx][ptr[num_idx][num_idx+1]] != baqui[num_idx+1][ptr[num_idx+1][num_idx]] ){
            dirs[num_idx + 1] = -1 * dirs[num_idx] ;
            num_idx ++;
        }

        // - 방향으로 전파 
        num_idx = num;
        while(num_idx > 1 && baqui[num_idx-1][ptr[num_idx-1][num_idx]] != baqui[num_idx][ptr[num_idx][num_idx-1]]){
            dirs[num_idx - 1] =  -1 * dirs[num_idx];
            num_idx --;
        }


        for(int i = 1 ; i <= 4; i ++){
            rotation(i,dirs[i]);
        }
    }



    ans += (baqui[1][(ptr[1][2] -2 + 8) % 8] * 1) ;
    ans += (baqui[2][(ptr[2][3] -2 + 8) % 8] * 2) ; 
    ans += (baqui[3][(ptr[3][4] -2 + 8) % 8] * 4) ; 
    ans += (baqui[4][(ptr[4][3] + 2) % 8] * 8) ; 



    cout << ans;

}