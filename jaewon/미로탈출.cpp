#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;


int N, M;
int Hx, Hy;
int Ex, Ey;
int minstep;
bool map[1005][1005];
bool check_wall[1005][1005];
bool check[1005][1005];

int movex[4] = {0, -1, 0, 1};
int movey[4] = {1, 0, -1, 0};

queue<pair<pair<int, int>, pair<int, bool>>> q;

void input() {
    memset(check, false, sizeof(bool)*1005*1005);
    memset(check_wall, false, sizeof(bool)*1005*1005);
    // minstep = 100000000;
    cin >> N >> M;
    cin >> Hx >> Hy;
    cin >> Ex >> Ey;

    int temp;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin >> temp;
            map[i][j] = temp == 0 ? true : false;
        }
    }
}

int BFS() {
    int curx=Hx;
    int cury=Hy;
    int curstep=0;
    int status = 0;
    
    q.push(make_pair(make_pair(curx, cury), make_pair(curstep, status)));
    check[curx][cury] = true;
    check_wall[curx][cury] =true;

    while(!q.empty()) {
        curx = q.front().first.first;
        cury = q.front().first.second;
        curstep = q.front().second.first;
        status = q.front().second.second;
        q.pop();
        if(curx == Ex && cury == Ey) {
            return curstep;
        }
        else {
            for(int i=0;i<4;i++) {
                if(curx+movex[i] >= 1 && curx+movex[i] <= N && cury+movey[i] >= 1 && cury+movey[i] <= M) {
                    if (map[curx+movex[i]][cury+movey[i]]==true) {
                        if (status==0 && check[curx+movex[i]][cury+movey[i]]== false) {
                            check[curx+movex[i]][cury+movey[i]] = true;
                            q.push(make_pair(make_pair(curx+movex[i],cury+movey[i]), make_pair(curstep+1, status)));
                        }
                        else if(status==1 && check_wall[curx+movex[i]][cury+movey[i]] == false) {
                            check_wall[curx+movex[i]][cury+movey[i]] = true;
                            q.push(make_pair(make_pair(curx+movex[i],cury+movey[i]), make_pair(curstep+1, status)));
                        }
                    }
                    else{
                        if(status==0 && check_wall[curx+movex[i]][cury+movey[i]] == false) {
                            check_wall[curx+movex[i]][cury+movey[i]] = true;
                            q.push(make_pair(make_pair(curx+movex[i],cury+movey[i]), make_pair(curstep+1, 1)));
                        }
                    }
                }
            }
        }
    }

    return -1;
}


int main() {
    input();

    cout << BFS();

    return 0;

}