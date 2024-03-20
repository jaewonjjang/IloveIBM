#include <iostream>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;


void input();
int cal();
int pno;
int startp, endp;
int a, b, m;
bool map[101][101];
bool check[101];
queue<pair<int, int>> q;
int main() {

    input();

    
    cout << cal();


    return 0;
}

void input(){
    memset(map, false, sizeof(bool)*101*101);
    memset(check, false, sizeof(bool)*101);

    cin >> pno;
    cin >> startp >> endp;
    cin >> m;

    for(int i=0;i<m;i++) {
        cin >> a >> b;
        map[a][b] = true;
        map[b][a] = true;
    }
}

int cal(){

    q.push(make_pair(startp, 0));
    check[startp] = true;

    while(!q.empty()){
        int cur = q.front().first;
        int cur_res = q.front().second+1;
        q.pop();

        for(int i=1;i<=pno;i++) {
            if(map[cur][i]==true && check[i]==false) {
                if(i==endp) {
                    return cur_res;
                }
                q.push(make_pair(i, cur_res));
                check[i] = true;
            }
        }
    }

    return -1;
}