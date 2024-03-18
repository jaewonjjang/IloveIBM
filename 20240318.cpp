#include <iostream>

using namespace std;

int main() {
    int A, B;
    int temp=0;
    int max=0;
    for (int i=0;i<10;i++) {
        cin >> A >> B;
        temp -= A;
        temp += B;
        max = max > temp ? max : temp;
    }

    printf("%d", max);
    
    return 0;
}