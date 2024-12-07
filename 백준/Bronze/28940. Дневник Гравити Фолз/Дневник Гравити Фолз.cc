#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int w, h;
    cin >> w >> h;
    int n, a, b;
    cin >> n >> a >> b;

    int lettersPerLine = w / a;
    int linesPerPage = h / b;

    if (lettersPerLine == 0 || linesPerPage == 0) {
        cout << -1 << "\n";
        return 0;
    }

    int lettersPerPage = lettersPerLine * linesPerPage;
    int pages = (n + lettersPerPage - 1) / lettersPerPage; // 올림 구현

    cout << pages << "\n";

    return 0;
}
