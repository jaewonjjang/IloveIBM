#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int aqua[50][101];
int copyaqua[50][101];
int ahang[101];
int N, K, temp;
int row=1;
int col=1;
void input();
int cal();
void fishinmin();
int main() {

    input();
    int result = cal();

    for(int i=0;i<N;i++) {
        cout << ahang[i] << " ";
    }
    return 0;
}

void input() {
    memset(aqua, 0, sizeof(int)*50*101);
    memset(copyaqua, 0, sizeof(int)*50*101);
    cin >> N >> K;

    for(int i=0;i<N;i++) {
        cin >> temp;
        ahang[i] = temp;
        aqua[0][i] = temp;
    }
}

int cal() {
    int res=0;
    int start_row=0;
    int start_col=0;
    //최소인 어항에 한마리씩 추가
    int max=0;
    int min=10000;

    for(int i=0;i<N;i++) {
        if(ahang[i] > max) {
            max = ahang[i];
        }
        if(ahang[i] < min) {
            min = ahang[i];
        }
    }

    while(max-min >= K) {
        fishinmin();

        //90도 회전시키면서 쌓는다.
        while(N-(row*col) >= row) {

            //앞쪽 회전
            for(int i=0;i<row;i++) {
                for(int j=0;j<col;j++) {
                    copyaqua[j][i] = aqua[i][j];
                }
            }

            //회전된 부분 위로 쌓기

            //row, col 업데이트
        }
    }
    

    return res;
}

void fishinmin() {
    int start=ahang[0];
    vector<int> min;
    min.push_back(0);
    for(int i=0;i<N;i++) {
        if(start > ahang[i]) {
            min.clear();
            min.push_back(i);
            start = ahang[i];
        }
        else if(start == ahang[i]) {
            min.push_back(i);
        }
        else continue;
    }
    for(int i=0;i<min.size();i++) {
        ahang[min[i]]++;
    }
}