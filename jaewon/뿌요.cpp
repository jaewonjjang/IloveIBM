#include <iostream>
#include <queue>
#include <vector>

using namespace std;


char bbuyo[12][6];
bool check[12][6];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<pair<int, int>>> group;

void input() {
    memset(check, false, sizeof(bool)*12*6);
    for(int i=11;i>=0;i--) {
        for(int j=0;j<6;j++) {
            cin >> bbuyo[i][j];
        }
    }
}

int make_group(int i, int j) {
    int curi=i;
    int curj=j;
    queue<pair<int, int>> q;
    vector<pair<int, int>> temp;

    q.push(make_pair(i, j));
    check[i][j] = true;


    while(!q.empty()) {
        curi = q.front().first;
        curj = q.front().second;
        q.pop();
        temp.push_back(make_pair(curi, curj));
        for(int i=0;i<4;i++) {
            int movei = curi+dx[i];
            int movej = curj+dy[i];

            if(movei >= 0 && movei<12 && movej >= 0 && movej < 6 && check[movei][movej] ==false) {
                //색이 같으면 enqueue
                if(bbuyo[movei][movej] == bbuyo[curi][curj]) {
                    q.push(make_pair(movei, movej));
                    check[movei][movej] = true;
                }
            }
        }
    }
    group.push_back(temp);

    return temp.size();
}

int findbbuyo() {
    int max_size=0;
    int temp;
    for(int i=0;i<12;i++) {
        for(int j=0;j<6;j++) {
            if(check[i][j]==false && bbuyo[i][j] != '.') {
                temp = make_group(i, j);
                if(temp > max_size) {
                    max_size = temp;
                }
            }
        }
    }
    memset(check, false, sizeof(bool)*12*6);
    return max_size;
}

void explode() {
    for(int i=0;i<group.size();i++) {
        if(group[i].size() >= 4) {
            for(int j=0;j<group[i].size();j++) {
                bbuyo[group[i][j].first][group[i][j].second] = '.';
            }
        }
    }
    group.clear();
}

void godown() {
    char copybbuyo[12][6];
    int tempidx = 0;
    memset(copybbuyo, '.', sizeof(char)*12*6);
    for(int j=0;j<6;j++) {
        for(int i=0;i<12;i++) {
            if(bbuyo[i][j] != '.') {
                copybbuyo[tempidx][j] = bbuyo[i][j];
                tempidx++;
            }
        }
        tempidx = 0;
    }
    memcpy(bbuyo, copybbuyo, sizeof(char)*12*6);
}

int game() {
    int count=0;
    int t_size;

    while(1) {
        t_size = findbbuyo();
        //cout << t_size << endl;

        if(t_size < 4) {
            return count;
        }

        explode();

        godown();

        count++;
        // for(int i=11;i>=0;i--) {
        //     for(int j=0;j<6;j++) {
        //         cout << bbuyo[i][j];
        //     }
        //     cout << "\n" << "\n";
        // }
    }
}

int main() {
    input();

    // findbbuyo();

    // explode();

    // godown();

    // for(int i=11;i>=0;i--) {
    //     for(int j=0;j<6;j++) {
    //         cout << bbuyo[i][j];
    //     }
    //     cout << "\n";
    // }
    cout << game();
    // for(int i=0;i<group.size();i++) {
    //     for(int j=0;j<group[i].size();j++) {
    //         cout << group[i][j].first<< group[i][j].second << " ";
    //     }
    //     cout << "\n";
    // }
    return 0;
}
