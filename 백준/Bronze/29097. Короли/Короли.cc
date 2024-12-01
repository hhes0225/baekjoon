#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // 입력 변수 선언
    int n, m, k, a, b, c;
    cin >> n >> m >> k >> a >> b >> c;

    // 각 왕의 총 병사 수 계산
    int joffrey_soldiers = n * a;
    int robb_soldiers = m * b;
    int stannis_soldiers = k * c;

    // 최대 병사 수 찾기
    int max_soldiers = max({joffrey_soldiers, robb_soldiers, stannis_soldiers});

    // 결과 저장용 벡터
    vector<string> strongest_kings;

    // 최대 병사 수를 가진 왕 추가
    if (joffrey_soldiers == max_soldiers) {
        strongest_kings.push_back("Joffrey");
    }
    if (robb_soldiers == max_soldiers) {
        strongest_kings.push_back("Robb");
    }
    if (stannis_soldiers == max_soldiers) {
        strongest_kings.push_back("Stannis");
    }

    // 사전 순서로 정렬
    sort(strongest_kings.begin(), strongest_kings.end());

    // 결과 출력
    for (size_t i = 0; i < strongest_kings.size(); ++i) {
        if (i > 0) cout << " ";
        cout << strongest_kings[i];
    }
    cout << endl;

    return 0;
}
