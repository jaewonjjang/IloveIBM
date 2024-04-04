#include <iostream>
#include <queue>
#include <cstring>
#include <deque>

using namespace std;

int N;
int field[21][21];
int copyfield[21][21];
int maxfield;

void rotate90right() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            copyfield[N-1-j][i] = field[i][j];
        }
    }
    memcpy(field, copyfield, sizeof(int)*21*21);
    memset(copyfield, 0, sizeof(copyfield));
}

void rotate90left() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            copyfield[j][N-1-i] = field[i][j];
        }
    }
    memcpy(field, copyfield, sizeof(int)*21*21);
    memset(copyfield, 0, sizeof(copyfield));
}

void move_left() {
    deque<int> copyleft;
    deque<int> fieldleft;

    for(int i=0;i<N;i++) {

        //0 이 아닌 값만 fieldleft에 넣는다.
        for(int j=0;j<N;j++) {
            if(field[i][j] != 0) {
                fieldleft.push_back(field[i][j]);
            }
        }

        //앞쪽부터 연산하면서 뒤에 값이랑 같으면 덧셈 값을 copyeleft에 넣고, 다르면 ~~
        for(int k=0;k<fieldleft.size();k++) {
            if (k== fieldleft.size()-1) {
                copyleft.push_back(fieldleft[k]);
                break;
            }
            else if(fieldleft[k] == fieldleft[k+1]) {
                copyleft.push_back(fieldleft[k] + fieldleft[k+1]);
                k++;
            }
            else {
                copyleft.push_back(fieldleft[k]);
            }
        }

        // for(auto a: copyleft) {
        //     cout << a << " ";
        // }
        // cout << "\n\n";

        memset(field[i], 0, sizeof(field[i]));
        for(int l=0;l<copyleft.size();l++) {
            field[i][l] = copyleft[l];
        }
        copyleft.clear();
        fieldleft.clear();
    }
}

void move_right() {
    deque<int> copyright;
    deque<int> fieldright;

    for(int i=0;i<N;i++) {

        //0 이 아닌 값만 fieldleft에 넣는다.
        for(int j=0;j<N;j++) {
            if(field[i][j] != 0) {
                fieldright.push_front(field[i][j]);
            }
        }

        //앞쪽부터 연산하면서 뒤에 값이랑 같으면 덧셈 값을 copyeleft에 넣고, 다르면 ~~
        for(int k=0;k<fieldright.size();k++) {
            if (k== fieldright.size()-1) {
                copyright.push_back(fieldright[k]);
                break;
            }
            else if(fieldright[k] == fieldright[k+1]) {
                copyright.push_back(fieldright[k] + fieldright[k+1]);
                k++;
            }
            else {
                copyright.push_back(fieldright[k]);
            }
        }

        // for(auto a: copyright) {
        //     cout << a << " ";
        // }
        // cout << "\n\n";

        memset(field[i], 0, sizeof(field[i]));
        for(int l=0;l<copyright.size();l++) {
            field[i][l] = copyright[l];
        }

        for(int m=0;m<N/2;m++) {
            int temp;
            temp = field[i][m];
            field[i][m] = field[i][N-1-m];
            field[i][N-1-m] = temp;
        }
        copyright.clear();
        fieldright.clear();
    }
}

void move_up() {

    rotate90right();
    move_left();
    rotate90left();
}

void move_down() {

    rotate90left();
    move_left();
    rotate90right();

}

void input(){
    maxfield = 0;
    cin >> N;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> field[i][j];
        }
    }
}

int checkmaxi() {
    int maxi=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(maxi < field[i][j]) {
                maxi = field[i][j];
            }
        }
    }

    return maxi;
}

void recur(int cnt) {
    int copycopyfield[21][21];
    if (cnt == 5) {
        if(maxfield < checkmaxi()) {
            maxfield = checkmaxi();
        }
        return;
    }
    else {
        for(int i=0;i<4;i++) {
            if(i==0) {
                memcpy(copycopyfield, field, sizeof(field));
                move_left();
                recur(cnt+1);
                memcpy(field, copycopyfield, sizeof(field));
            }
            else if(i==1) {
                memcpy(copycopyfield, field, sizeof(field));
                move_right();
                recur(cnt+1);
                memcpy(field, copycopyfield, sizeof(field));
            }
            else if(i==2) {
                memcpy(copycopyfield, field, sizeof(field));
                move_up();
                recur(cnt+1);
                memcpy(field, copycopyfield, sizeof(field));
            }
            else {
                memcpy(copycopyfield, field, sizeof(field));
                move_down();
                recur(cnt+1);
                memcpy(field, copycopyfield, sizeof(field));
            }
        }
    }
}
int main() {

    input();

    recur(0);
    // move_left();


    cout << maxfield;

    return 0;
    
}