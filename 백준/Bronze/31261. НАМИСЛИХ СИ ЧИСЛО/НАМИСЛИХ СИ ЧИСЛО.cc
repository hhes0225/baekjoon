#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int result = a * a * (b + a + 1);
    cout << result << '\n';

    return 0;
}
