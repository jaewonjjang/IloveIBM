#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N, M, K;
int map[1002][1002];
bool check[1002][1002];
bool check_wall[12][1002][1002];
queue<pair<pair<int, int>, pair<int, int>>> q;
int movex[4] = {0, -1, 0, 1};
int movey[4] = {1, 0, -1, 0};

void input() {
    memset(map, 0, sizeof(int)*1001*1001);
    memset(check, false, sizeof(bool)*1002*1002);
    memset(check_wall, false, sizeof(bool)*12*1002*1002);
    cin >> N >> M >> K;

    int temp;
    for(int i=1;i<=N;i++) {
        cin >> temp;
        for(int j=M;j>=1;j--) {
            map[i][j] = temp%10;
            temp = temp/10;
        }
    }

    // for(int i=1;i<=N;i++) {
    //     for(int j=1;j<=M;j++) {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}

int BFS() {
    int curx=1;
    int cury=1;
    int status=0;
    int count=0;

    q.push(make_pair(make_pair(1, 1), make_pair(1, 0)));
    check[1][1] = true;
    check_wall[0][1][1] = true;

    while(!q.empty()) {
        curx = q.front().first.first;
        cury = q.front().first.second;
        count = q.front().second.first;
        status = q.front().second.second;
        q.pop();
        
        if(curx==N && cury==M){
            return count;
        }
        else {
            for(int i=0;i<4;i++) {
                if(curx+movex[i] >= 1 && curx+movex[i] <= N && cury+movey[i] >= 1 && cury+movey[i] <= M) {
                    if (map[curx+movex[i]][cury+movey[i]] == 0) {
                        if(check[curx+movex[i]][cury+movey[i]]==false && status==0) {
                            // curx += movex[i];
                            // cury += movey[i];
                            q.push(make_pair(make_pair(curx+movex[i], cury+movey[i]), make_pair(count+1, status)));
                            check[curx+movex[i]][cury+movey[i]]=true;
                        }
                        else if(check_wall[status][curx+movex[i]][cury+movey[i]]==false && status) {
                            // curx += movex[i];
                            // cury += movey[i];
                            q.push(make_pair(make_pair(curx+movex[i], cury+movey[i]), make_pair(count+1, status)));
                            check_wall[status][curx+movex[i]][cury+movey[i]]=true;
                        }
                    }
                    else {
                        //벽을 깨는 경우
                        if(status < K && check_wall[status+1][curx+movex[i]][cury+movey[i]]==false) {
                            q.push(make_pair(make_pair(curx+movex[i], cury+movey[i]), make_pair(count+1, status+1)));
                            check_wall[status+1][curx+movex[i]][cury+movey[i]]=true;
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