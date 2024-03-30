#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
int price[11][11];
int real_price[11][11];
int candi[11];
int min_temp=1000000000;
void input() {
    cin >> N;

    memset(price, 0, sizeof(int)*11*11);
    memset(real_price, 0, sizeof(int)*11*11);
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> price[i][j];
        }
    }

    for(int i=1;i<N-1;i++) {
        for(int j=1;j<N-1;j++) {
            real_price[i][j] = price[i-1][j] + price[i+1][j] + price[i][j-1] + price[i][j+1] + price[i][j];
        }
    }
}

bool check() {
    int x1 = candi[0]/(N-2);
    int x2 = candi[1]/(N-2);
    int x3 = candi[2]/(N-2);

    int y1 = candi[0]%(N-2);
    int y2 = candi[1]%(N-2);
    int y3 = candi[2]%(N-2);

    if(((abs(x1-x2)==0) && abs(y1-y2) <= 2) || ((abs(y1-y2)==0) && abs(x1-x2) <= 2) || (abs(x1-x2)<=1 && abs(y1-y2) <=1)) {
        return false;
    }
    if(((abs(x1-x3)==0) && abs(y1-y3) <= 2) || ((abs(y1-y3)==0) && abs(x1-x3) <= 2) || (abs(x1-x3)<=1 && abs(y1-y3) <=1)) {
        return false;
    }
    if(((abs(x3-x2)==0) && abs(y3-y2) <= 2) || ((abs(y3-y2)==0) && abs(x3-x2) <= 2) || (abs(x3-x2)<=1 && abs(y3-y2) <=1)) {
        return false;
    }

    return true;
}

void pick(int n, int r) {
    //심을 수 있으면 갱신
    if(n==3) {
        if(check()) {
            //cout << candi[0] << candi[1] << candi[2] << endl;
            int min_val = real_price[(candi[0]/(N-2))+1][candi[0]%(N-2)+1] + real_price[(candi[1]/(N-2))+1][candi[1]%(N-2)+1] + real_price[(candi[2]/(N-2))+1][candi[2]%(N-2)+1];
            if(min_temp > min_val) {
                //cout << candi[0] << candi[1] << candi[2] << endl;
                min_temp = min_val;
            }
        }
        else return;
    }
    else {
        for(int i=r;i<(N-2)*(N-2);i++) {
            candi[n] = i;
            pick(n+1, i+1);
        }
    }
}

int main() {
    input();

    pick(0, 0);

    cout << min_temp;

    return 0;

}