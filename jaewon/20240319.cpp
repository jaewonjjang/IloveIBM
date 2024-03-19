/**
 * 로봇 청소기와 방의 상태가 주어졌을 때, 청소하는 영역의 개수를 구하는 프로그램을 작성하시오.

로봇 청소기가 있는 방은 
$N \times M$ 크기의 직사각형으로 나타낼 수 있으며, 
$1 \times 1$ 크기의 정사각형 칸으로 나누어져 있다. 각각의 칸은 벽 또는 빈 칸이다. 청소기는 바라보는 방향이 있으며, 이 방향은 동, 서, 남, 북 중 하나이다. 방의 각 칸은 좌표 
$(r, c)$로 나타낼 수 있고, 가장 북쪽 줄의 가장 서쪽 칸의 좌표가 
$(0, 0)$, 가장 남쪽 줄의 가장 동쪽 칸의 좌표가 
$(N-1, M-1)$이다. 즉, 좌표 
$(r, c)$는 북쪽에서 
$(r+1)$번째에 있는 줄의 서쪽에서 
$(c+1)$번째 칸을 가리킨다. 처음에 빈 칸은 전부 청소되지 않은 상태이다.

로봇 청소기는 다음과 같이 작동한다.

현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
현재 칸의 주변 
$4$칸 중 청소되지 않은 빈 칸이 없는 경우,
바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
현재 칸의 주변 
$4$칸 중 청소되지 않은 빈 칸이 있는 경우,
반시계 방향으로 
$90^\circ$ 회전한다.
바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
1번으로 돌아간다.
*/

#include <iostream>

using namespace std;

int R, C;
int map[51][51];
int start_r, start_c;
int dir;
int move_r[4] = {-1, 0, 1, 0};
int move_c[4] = {0, 1, 0, -1};


int temp;


int main() {

//input
    cin >> R >> C;
    cin >> start_r >> start_c >> dir;

    for (int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            cin >> temp;
            if(temp==1){
                //wall=1, cleaned=2, uncleaned=0
                map[i][j] = 1;
            }
            //false=not cleaned
            else map[i][j] = 0;
        }
    }

    bool cango=true;
    int cur_r = start_r;
    int cur_c = start_c;
    int cur_dir = dir;
    int res=0;
    while(cango) {
        if(map[cur_r][cur_c]==0) {
            map[cur_r][cur_c] = 2;
            res++;
        }

        //index 유효하고 청소안된 부분 있으면 90도 회전, 앞쪽이 청소되지 않았으면 이동
        if((cur_r+move_r[0] >= 0 && cur_r+move_r[0]<R && cur_c+move_c[0] >= 0 && cur_c+move_c[0]<C && map[cur_r+move_r[0]][cur_c+move_c[0]]==0)
        || (cur_r+move_r[1] >= 0 && cur_r+move_r[1]<R && cur_c+move_c[1] >= 0 && cur_c+move_c[1]<C && map[cur_r+move_r[1]][cur_c+move_c[1]]==0)
        || (cur_r+move_r[2] >= 0 && cur_r+move_r[2]<R && cur_c+move_c[2] >= 0 && cur_c+move_c[2]<C && map[cur_r+move_r[2]][cur_c+move_c[2]]==0)
        || (cur_r+move_r[3] >= 0 && cur_r+move_r[3]<R && cur_c+move_c[3] >= 0 && cur_c+move_c[3]<C && map[cur_r+move_r[3]][cur_c+move_c[3]]==0)) {
            //90도 회전
            dir = (dir+3)%4;
            //이동할 수 있으면 이동
            if(cur_r+move_r[dir] >= 0 && cur_r+move_r[dir]<R && cur_c+move_c[dir] >= 0 && cur_c+move_c[dir]<C && map[cur_r+move_r[dir]][cur_c+move_c[dir]]==0) {
                cur_r = cur_r+move_r[dir];
                cur_c = cur_c+move_c[dir];
            }
        }
        else {
            int back_dir = (dir+2)%4;
            //뒤로 이동가능하면
            if(cur_r+move_r[back_dir] >= 0 && cur_r+move_r[back_dir]<R && cur_c+move_c[back_dir] >= 0 && cur_c+move_c[back_dir]<C && map[cur_r+move_r[back_dir]][cur_c+move_c[back_dir]]!=1) {
                cur_r = cur_r+move_r[back_dir];
                cur_c = cur_c+move_c[back_dir];
            }
            else {
                cango = false;
            }
        }
    }

    cout << res;
}

