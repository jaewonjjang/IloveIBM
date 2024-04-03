#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct Node{
    int x;
    int y;
    int total_cnt;
};

int N, M;
int tomato[1001][1001];
bool check[1001][1001];
queue<Node> q;
int tcnt;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input() {
    tcnt=0;
    memset(check, false, sizeof(check));
    cin >> M >> N;

    int temp;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> temp;
            tomato[i][j] = temp;
            if(temp == 1) {
                Node temp;
                temp.x = i;
                temp.y = j;
                temp.total_cnt=0;
                q.push(temp);
                check[i][j] = true;
                tcnt++;
                //cout << "q.size()=" << q.size() << endl;

            }
            else if(temp == 0) {
                tcnt++;
            }
        }
    }
}

int BFS() {
    int tomatono=0;

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().total_cnt;
        q.pop();
        tomatono++;

        if(tomatono == tcnt) {
            return cnt;
        }
        else {
            for(int i=0;i<4;i++) {
                if(x+dx[i] >= 0 && y+dy[i] >= 0 && x+dx[i] < N && y+dy[i] < M && tomato[x+dx[i]][y+dy[i]] == 0 && check[x+dx[i]][y+dy[i]] == false) {
                    Node temp;
                    temp.x = x+dx[i];
                    temp.y = y+dy[i];
                    temp.total_cnt = cnt+1;
                    q.push(temp);
                    check[x+dx[i]][y+dy[i]] = true;
                    // if(x+dx[i] == 0 && y+dy[i] == 1) {
                    //     cout << "OMG";
                    //     cout << cnt;
                    // }
                }
            }
        }
    }
    return -1;
}

int main() {

    input();
    //cout << tomato[1][0];

    //cout << "total_tomato=" << tcnt << endl;

    cout << BFS();

    return 0;
}