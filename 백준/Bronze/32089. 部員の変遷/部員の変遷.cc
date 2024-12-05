#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;

        if (n == 0) break; // 입력이 0이면 종료

        vector<int> new_members(n);
        for (int i = 0; i < n; i++) {
            cin >> new_members[i];
        }

        // 최대 부원 수 계산
        int max_members = 0;
        int current_members = 0;

        for (int i = 0; i < n; i++) {
            current_members += new_members[i]; // 현재 연도의 신입 부원 추가

            // 3년을 초과하면 졸업하는 부원 수를 뺌
            if (i >= 3) {
                current_members -= new_members[i - 3];
            }

            // 최대 부원 수 갱신
            max_members = max(max_members, current_members);
        }

        cout << max_members << endl; // 결과 출력
    }

    return 0;
}
