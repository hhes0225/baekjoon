#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    if (s.length() > n) {
        cout << "Impossible" << endl;
        return 0;
    }

    int totalCubes = 0;
    for (char c : s) {
        totalCubes += (c - 'a' + 1); // a = 1, b = 2, ..., z = 26
    }

    cout << totalCubes << endl;
    return 0;
}
