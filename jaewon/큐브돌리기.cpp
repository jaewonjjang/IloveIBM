#include <iostream>

using namespace std;

int N, M;
void printcube();
void printcopycube();
void rotate90cube(int, int);
void rotate180cube(int, int);
int cube[4][8];
int copycube[4][8];
int copycopycube[4][8];

int main() {
    int start=0;
    int row=1;
    int col=1;
    int nth=1;
    N=4;
    M=8;
    memset(cube, -1, sizeof(int)*4*8);
    memset(copycube, -1, sizeof(int)*32);
    memset(copycopycube, -1, sizeof(int)*32);

    int temp;
    for(int i=0;i<8;i++) {
        cin >> temp;
        cube[0][i] = temp;
    }


    printcube();
    printf("\n");

    // rotate90cube();
    // printcopycube(3, 4);
    // printf("\n");

    // for(int i=0;i<N;i++) {
    //     for(int j=0;j<M;j++) {
    //         cube[i][j] = N*i+j+1;
    //     }
    // }

    // rotate180cube();
    // printcube();

    
    while(M-(row*col) >= row) {
        //앞쪽 복사
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++) {
                copycube[i][j] = cube[i][start+j];
                // cube[i][row*col+j-1] = -1;
            }
        }
        // 앞쪽 회전
        rotate90cube(row, col);
        printf("copycube:\n");
        printcopycube();
        printf("\n");

        //회전된 부분 위로 쌓기
        for(int i=0;i<col;i++) {
            for(int j=0;j<row;j++) {
                cube[i+1][row*col+j] = copycube[i][j];
            }
        }
        printf("cube:\n");
        printcube();
        //row, col 업데이트
        start +=col;
        if(nth%2) row++;
        else col++;

        nth++;
    }

    // for(int i=0;i<row;i++){
    //         for(int j=0;j<col;j++) {
    //             copycube[i][j] = cube[i][row*col+j-1];
    //             // cube[i][row*col+j-1] = -1;
    //         }
    //     }
    //     // printcopycube(row, col);
    //     // 앞쪽 회전
    //     rotate90cube(row, col);

    //     //회전된 부분 위로 쌓기
    //     for(int i=0;i<col;i++) {
    //         for(int j=0;j<row;j++) {
    //             cube[i+1][row*col+j] = copycube[i][j];
    //         }
    //     }
    //     //row, col 업데이트
    //     if(nth%2) row++;
    //     else col++;

    //     nth++;
    //     printcube(4, 8);
    // printf("\n");


    // printf("row: %d, col: %d", row, col);

    //     for(int i=0;i<row;i++){
    //         for(int j=0;j<col;j++) {
    //             copycube[i][j] = cube[i][row*col+j-1];
    //             // cube[i][row*col+j-1] = -1;
    //         }
    //     }
    //     printf("copycube:\n");
    //     printcopycube(row, col);
    //     // 앞쪽 회전
    //     rotate90cube(row, col);

    //     //회전된 부분 위로 쌓기
    //     for(int i=0;i<col;i++) {
    //         for(int j=0;j<row;j++) {
    //             printf("%d\n",copycube[i][j]);
    //             cube[i+1][row*col+j] = copycube[i][j];
    //         }
    //     }
    //     //row, col 업데이트
    //     if(nth%2) row++;
    //     else col++;

    //     nth++;
    
    // printcube();
    // printf("\n");
    return 0;
}

void printcube() {
    for(int i=3;i>=0;i--) {
        for(int j=0;j<8;j++) {
            printf("%3d", cube[i][j]);
        }
        printf("\n");
    }
}

void printcopycube() {
    for(int i=3;i>=0;i--) {
        for(int j=0;j<8;j++) {
            printf("%3d", copycube[i][j]);
        }
        printf("\n");
    }
}

void rotate90cube(int N, int M) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            copycopycube[M-1-j][i] = copycube[i][j];
        }
    }
    memcpy(copycube, copycopycube, sizeof(int)*32);
}

void rotate180cube(int N, int M) {
    int copycube[3][3];
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            copycube[N-1-i][M-1-j] = cube[i][j];
        }
    }
    memcpy(cube, copycube, sizeof(int)*N*M);
}