#include <iostream>
#include <deque>

using namespace std;

int stno;
int stair[301];
int maxi[301][3];
int result;
void input() {
    cin >> stno;

    int temp;
    for(int i=1;i<=stno;i++) {
        cin >> temp;
        stair[i+1] = temp;
    }
    result=0;
}

int maximo(int a) {
    int ma=0;
    for(int i=0;i<3;i++) {
        if(ma < maxi[a][i]) ma = maxi[a][i];
    }
    return ma;
}

void cal() {
    maxi[0][0] = 0;
    maxi[0][1] = 0;
    maxi[0][2] = 0;

    maxi[1][0] = 0;
    maxi[1][1] = stair[1];
    maxi[1][2] = stair[1];

    for(int i=2;i<=stno;i++) {
        // 이번칸을 밟지 않을 경우의 최대값 -> 저번 계단은 밟았어야함
        int temp = maxi[i-1][1] > maxi[i-1][2] ? maxi[i-1][1] : maxi[i-1][2];
        maxi[i][0] = temp;

        // 이번칸만 밟은 경우(이전 계단 밟지 않은 경우)
        maxi[i][1] = maxi[i-1][0] + stair[i];

        // 이번칸과 저번칸을 모두 밟은 경우
        // temp = maxi[i-1][0] > maxi[i-1][1] ? maxi[i-1][0] : maxi[i-1][1];
        maxi[i][2] = maxi[i-1][1] + stair[i];
    }
    
}
int main() {
    input();

    cal();

    cout << maximo(stno); 

    return 0;
}

