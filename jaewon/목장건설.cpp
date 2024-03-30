#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int land[1005][1005];
int max_land[1005][1005];
int max_result;

void input() {
    memset(land, 0, sizeof(int)*1005*1005);
    memset(max_land, 0, sizeof(int)*1005*1005);
    max_result=0;
    int temp;

    cin >> M >> N;

    for(int i=1;i<=M;i++) {
        for(int j=1;j<=N;j++) {
            cin >> temp;
            land[i][j] = temp;
        }
    }
}

void cal() {
    for(int i=1;i<=M;i++) {
        for(int j=1;j<=N;j++) {
            if(land[i][j]!=0) {
                max_land[i][j] = 0;
            }
            else {
                if (max_land[i-1][j-1]!=0 && max_land[i][j-1]!=0 && max_land[i-1][j]!=0) {
                    if(max_land[i-1][j-1]== max_land[i-1][j] && max_land[i-1][j] == max_land[i][j-1]) {
                        max_land[i][j] = max_land[i-1][j-1]+1;
                        if(max_land[i][j] > max_result) {
                            max_result = max_land[i][j];
                        }
                    }
                    else {
                        int min_val=1000000000;
                        if(max_land[i-1][j-1] < min_val) {
                            min_val = max_land[i-1][j-1];
                        }
                        if(max_land[i][j-1] < min_val) {
                            min_val = max_land[i][j-1];
                        }
                        if(max_land[i-1][j] <min_val) {
                            min_val = max_land[i-1][j];
                        }
                        max_land[i][j] = min_val+1;
                        if(max_land[i][j] > max_result) {
                            max_result = max_land[i][j];
                        }
                    }
                }
                else {
                    max_land[i][j] =1;
                    if(max_land[i][j] > max_result) {
                        max_result = max_land[i][j];
                    }
                }                
            }
        }
    }
}

int main() {
    input();

    cal();

    cout << max_result;

    return 0;

}