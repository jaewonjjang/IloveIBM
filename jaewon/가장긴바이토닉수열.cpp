#include <iostream>

using namespace std;

int N;
int bitonic[1005];
int maxval1[1005];
int maxval2[1005];

void input() {
    cin >> N;
    int temp;
    for(int i=0;i<N;i++) {
        cin >> temp;
        bitonic[i] = temp;
    }
    memset(maxval1, 0, sizeof(int)*1005);
    memset(maxval2, 0, sizeof(int)*1005);
    maxval1[0]=1;
    maxval2[N-1]=1;
}

int cal() {
    int max=0;
    for(int i=1;i<N;i++) {
        max=0;
        for(int j=0;j<i;j++) {
            if(bitonic[i]> bitonic[j]) {
                if(maxval1[j] > max) max = maxval1[j];
            }
        }
        maxval1[i]=max+1;
    }

    max=0;
    for(int i=N-2;i>=0;i--) {
        max=0;
        for(int j=N-1;j>i;j--) {
            if(bitonic[i] > bitonic[j]) {
                if(maxval2[j] > max) max = maxval2[j];
            }
        }
        maxval2[i] = max+1;
    }

    max=0;
    for(int i=0;i<N;i++) {
        if(max < maxval1[i] + maxval2[i]) max = maxval1[i] + maxval2[i];
    }

    return max;
}

int main() {
    input();

    cout << cal()-1;

    return 0;

}