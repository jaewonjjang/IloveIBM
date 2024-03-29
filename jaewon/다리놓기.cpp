#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, R;
int T;
int combresult[31][31];


vector<pair<int, int>> tc;

int comb(int n, int r) {
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=i;j++) {
            if(i==0 || j==0 || i==1 || i==j) {
                combresult[i][j] = 1;
            }
            else {
                combresult[i][j] = combresult[i-1][j-1] + combresult[i-1][j];
            }
            
        }
    }

    return combresult[n][r];
}


int main() {
    memset(combresult, 1, sizeof(int)*31*31);

    cin >> T;

    for(int i=0;i<T;i++) {
        cin >> N >> R;
        tc.push_back(make_pair(R, N));
    }

    
    for(int i=0;i<T;i++) {
        cout << comb(tc[i].first, tc[i].second) << "\n";
    }
    return 0;
}

