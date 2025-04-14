#include <iostream>
#include <algorithm> // sort를 사용하기 위한 헤더

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    // 세 값을 배열에 저장
    int scores[3] = {A, B, C};

    // 오름차순 정렬
    sort(scores, scores + 3);

    // 가장 높은 두 수의 합 (뒤에서 두 번째와 세 번째)
    int result = scores[1] + scores[2];

    cout << result << endl;

    return 0;
}
