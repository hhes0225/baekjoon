#include <iostream>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    int count = 0;

    for (int i = 1; i <= N; ++i) {
        bool divA = (i % A == 0);
        bool divB = (i % B == 0);

        // A 또는 B 중 하나만 나누어떨어질 때
        if (divA != divB) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
