#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    if (A == B + C || B == A + C || C == A + B) {
        cout << 1;
    } else {
        cout << 0;
    }

    return 0;
}
