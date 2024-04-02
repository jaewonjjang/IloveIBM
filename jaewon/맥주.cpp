#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int T, cno;
//int songdo[65536][65536];
int x, y;

pair<int, int> sanggun;
pair<int, int> pentaport;
vector<pair<int, int>> convi;
queue<pair<pair<int, int>, int>> q;
bool check[101];

bool cango(int x, int y, int xx, int yy, int beer) {
    if((abs(xx-x) + abs(yy-y)) > (beer*50)) {
        return false;
    }
    return true;
}

int BFS() {

    q.push(make_pair(sanggun, 20));

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int b = q.front().second;
        q.pop();

        for(int i=0;i<cno;i++) {
            if(cango(x, y, convi[i].first, convi[i].second, b) && check[i] == false) {
                q.push(make_pair(convi[i], 20));
                check[i] = true;
            }
        }
        if(cango(x, y, pentaport.first, pentaport.second, b)) {
            return 1;
        }
    }
    return 0;
}

//상근이 위치 1, 편의점 2, 도착점 3
void input() {
    
    cin >> T;

    for(int i=0;i<T;i++) {
        //init
        memset(check, false, sizeof(check));
        while(!q.empty())   q.pop();
        convi.clear();

        cin >> cno;

        cin >> sanggun.first >> sanggun.second;
        //songdo[x][y] = 1;

        for(int c=0;c<cno;c++) {
            cin >> x >> y;
            convi.push_back(make_pair(x, y));
            //songdo[x][y] = 2;
            // convi[c].first = x;
            // convi[c].second = y;
        }

        cin >> pentaport.first >> pentaport.second;
        //songdo[x][y] = 3;
        // pentaport.first = x;
        // pentaport.second = y;

        int result = BFS();

        if(result) {
            cout << "happy" << endl;
        }
        else cout << "sad" << endl;
    }
}

int main() {
    input();


    return 0;
}

