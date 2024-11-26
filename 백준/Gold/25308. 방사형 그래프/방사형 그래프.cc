#include <bits/stdc++.h>
using namespace std;

// 상수로 점의 개수를 정의
const int NUM_POINTS = 8;

// 점의 좌표를 계산하는 함수
pair<double, double> getPoint(int a, int k) {
    double angle = 45.0 * k * M_PI / 180.0; // 라디안으로 변환
    return {a * cos(angle), a * sin(angle)};
}

// 교차곱을 계산하는 함수
double crossProduct(pair<double, double> O, pair<double, double> P1, pair<double, double> P2) {
    double OA_x = P1.first - O.first;
    double OA_y = P1.second - O.second;
    double OB_x = P2.first - O.first;
    double OB_y = P2.second - O.second;
    return OA_x * OB_y - OA_y * OB_x;
}

bool checkConvex(const vector<int>& status) {
    vector<pair<double, double>> points(NUM_POINTS);
    for (int i = 0; i < NUM_POINTS; i++) {
        points[i] = getPoint(status[i], i);
    }

    double prevCross = 0;
    for (int i = 0; i < NUM_POINTS; i++) {
        int next_i = (i + 1) % NUM_POINTS;
        int next_next_i = (i + 2) % NUM_POINTS;
        double cross = crossProduct(points[i], points[next_i], points[next_next_i]);
        if (cross != 0) {
            if (prevCross == 0) {
                prevCross = (cross > 0) ? 1 : -1;
            } else {
                if ((cross > 0 && prevCross < 0) || (cross < 0 && prevCross > 0)) {
                    return false; // 볼록이 아님
                }
            }
        }
    }
    return true; // 모든 교차곱이 동일한 부호를 가짐
}

int main() {
    vector<int> status(NUM_POINTS);
    for (int i = 0; i < NUM_POINTS; i++) cin >> status[i];

    int ans = 0;
    vector<int> indices(NUM_POINTS);
    for (int i = 0; i < NUM_POINTS; i++) indices[i] = i;

    do {
        vector<int> perm(NUM_POINTS);
        for (int i = 0; i < NUM_POINTS; i++) {
            perm[i] = status[indices[i]];
        }
        if (checkConvex(perm)) {
            ans++;
        }
    } while (next_permutation(indices.begin(), indices.end()));

    cout << ans << "\n";
    return 0;
}
