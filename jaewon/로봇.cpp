#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int R, C;
int K;
int b_r[1001];
int b_c[1001];
int sr, sc;
int dir[4];
int movex[4] = {-1, 1, 0, 0};
int movey[4] = {0, 0, -1, 1};
bool visited[1001][1001];
int map[1001][1001];


void input() {
    memset(visited, false, sizeof(bool)*1001*1001);
    memset(map, 0, sizeof(int)*1001*1001);
    cin >> R >> C;
    cin >> K;

    for(int i=0;i<K;i++) {
        cin >> b_r[i] >> b_c[i];
        map[b_r[i]][b_c[i]]=1;
    }

    cin >> sr >> sc;
    int dirtemp;
    for(int i=0;i<4;i++) {
        cin >> dirtemp;
        dir[i] = dirtemp-1;
    }
}

pair<int, int> cal() {
    int curx = sr;
    int cury = sc;
    int diridx=0;
    int cur_dir = dir[diridx];
    int failcount=0;
    visited[sr][sc] = true;
    //int nextdir = dir[0];

    while(1) {
        if(curx+movex[cur_dir] >=0 && curx+movex[cur_dir] < R && cury+movey[cur_dir] >= 0 && cury+movey[cur_dir] < C && visited[curx+movex[cur_dir]][cury+movey[cur_dir]]==false && map[curx+movex[cur_dir]][cury+movey[cur_dir]] != 1) {
            visited[curx+movex[cur_dir]][cury+movey[cur_dir]]= true;
            curx += movex[cur_dir];
            cury += movey[cur_dir];
            failcount = 0;
            //cout << "방문성공 " << "cx:" << curx << " " << "cy : " << cury << endl;
        }
        //이동못하는경우
        else {
            if(failcount==3) {
                return make_pair(curx, cury);
                break;
            }
            else {
                diridx++;
                failcount++;
                cur_dir = dir[diridx%4];
            }
        }
    }
    return make_pair(curx, cury);
}
int main() {
    input();

    pair<int, int> p = cal();
    cout << p.first << " " << p.second;

    return 0;
}