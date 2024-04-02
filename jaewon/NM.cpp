#include <iostream>
#include <cstring>

using namespace std;


int N, M;
char map[31][31];
bool check[31][31];
int totalcnt;
int mincnt;

int dx[5] = {1, 0, -1, 0, 1000};
int dy[5] = {0, -1, 0, 1, 1000};


void input() {
    memset(check, false, sizeof(check));
    memset(map, ' ', sizeof(map));
    mincnt = 123456789;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> map[i][j];
            if(map[i][j] == '.') {
                totalcnt++;
            }
        }
    }
}

bool cango(int x, int y, int d) {
    return (x+dx[d] >= 0 && y+dy[d] >= 0 && x+dx[d] < N && y+dy[d] < M && map[x+dx[d]][y+dy[d]] == '.' && check[x+dx[d]][y+dy[d]] == false);
}

void DFS(int x, int y, int dir, int cnt, int stepcnt) {
    int curx = x;
    int cury = y;
    check[curx][cury] = true;
    //종료조건
    if(cnt == totalcnt) {
        //cout << "jaewon";
        mincnt = mincnt > stepcnt ? stepcnt : mincnt;
        return;
    }
    else {
        if(cango(x, y, dir)) {
            DFS(x + dx[dir], y+dy[dir], dir, cnt+1, stepcnt);
        }
        //현재방향으로 걀수있는만큼 전진
        else {
            for(int i=0;i<4;i++) {
                if(cango(curx, cury, i)) {
                    DFS(curx+dx[i], cury+dy[i], i, cnt+1, stepcnt+1);
                }
            }
        }
        // while(1) {
        //     if(cango(curx, cury, dir)) {
        //         check[curx][cury] = true;
        //         curx += dx[dir];
        //         cury += dy[dir];
        //         cnt++;
        //     }
        //     else {
        //         break;
        //     }
        // }
        // for(int i=0;i<4;i++) {
        //     if(cango(curx, cury, i)) {
        //         check[curx][cury] = true;
        //         DFS(curx, cury, i, cnt, stepcnt+1);
        //         check[curx][cury] = false;
        //     }
        // }
        // while(1) {
        //     if(curx == x && cury == y) {
        //         cout << "1";
        //         break;
        //     }
        //     curx -= dx[dir];
        //     cury -= dy[dir];
        //     check[curx][cury] = false;
        // }
    }
    check[curx][cury] = false;
}

int main() {
    int idx=1;

    while(scanf("%d%d",&N,&M)!=-1) {
        memset(check, false, sizeof(check));
        memset(map, ' ', sizeof(map));
        mincnt = 123456789;
        totalcnt = 0;
        
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                cin >> map[i][j];
                if(map[i][j] == '.') {
                    totalcnt++;
                }
            }
        }

        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(map[i][j] == '.') {
                    memset(check, false, sizeof(check));
                    DFS(i, j, 4, 1, 0);
                }
            }
        }

        if(mincnt==123456789) mincnt=-1;
        printf("Case %d: %d\n",idx++,mincnt);
    }

    return 0;
}