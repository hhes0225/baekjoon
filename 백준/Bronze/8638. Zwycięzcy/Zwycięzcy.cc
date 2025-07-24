#include <iostream>
#include <vector>
#include <algorithm> // for max_element
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> scores(N);
    for (int i = 0; i < N; ++i) {
        cin >> scores[i];
    }

    // 최고 점수 찾기
    int maxScore = *max_element(scores.begin(), scores.end());

    // 최고 점수를 받은 선수의 식별자 출력
    for (int i = 0; i < N; ++i) {
        if (scores[i] == maxScore) {
            cout << static_cast<char>('A' + i);
        }
    }

    cout << endl;
    return 0;
}
