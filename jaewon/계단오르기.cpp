#include <iostream>
#include <deque>

using namespace std;

int stno;
int stair[301];
bool check[301];
int maxi;
int result;
void input() {
    memset(check, false, sizeof(bool)*301);
    cin >> stno;

    int temp;
    for(int i=1;i<=stno;i++) {
        cin >> temp;
        stair[i] = temp;
    }
    maxi=0;
    result=0;
}

void cal(int cur) {
    if(cur==stno) {
        maxi = result > maxi ? result : maxi;
    }
    else {
        for(int i=1;i<=2;i++) {
            if(cur>1 && i==1 && check[cur-1]==true) {
                continue;
            }
            else {
                if(cur+i <= stno && check[cur+i]==false) {
                    result += stair[cur+i];
                    check[cur+i]=true;
                    cal(cur+i);
                    result -= stair[cur+i];
                    check[cur+i] = false;
                }
            }
        }
    }
}
int main() {
    input();

    cal(0);

    cout << maxi; 
}

