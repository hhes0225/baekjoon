#include <bits/stdc++.h>
using namespace std;

static inline int to_mm(int cm, int mm) {
    return cm * 10 + mm; // 1cm = 10mm
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 책 입력
    int a_cm, a_mm, b_cm, b_mm;
    if (!(cin >> a_cm >> a_mm >> b_cm >> b_mm)) return 0;
    int A = to_mm(a_cm, a_mm);
    int B = to_mm(b_cm, b_mm);
    int book_w = min(A, B);
    int book_h = max(A, B);

    // 표지 1
    int c1_cm, c1_mm, d1_cm, d1_mm;
    cin >> c1_cm >> c1_mm >> d1_cm >> d1_mm;
    int C1 = to_mm(c1_cm, c1_mm);
    int D1 = to_mm(d1_cm, d1_mm);
    int cov1_w = min(C1, D1);
    int cov1_h = max(C1, D1);

    // 표지 2
    int c2_cm, c2_mm, d2_cm, d2_mm;
    cin >> c2_cm >> c2_mm >> d2_cm >> d2_mm;
    int C2 = to_mm(c2_cm, c2_mm);
    int D2 = to_mm(d2_cm, d2_mm);
    int cov2_w = min(C2, D2);
    int cov2_h = max(C2, D2);

    auto ok1 = (cov1_w >= book_w + 10) && (cov1_h >= book_h);
    auto ok2 = (cov2_w >= book_w + 10) && (cov2_h >= book_h);

    int pick = 0;
    int pw = 0, ph = 0; // 선택한 표지의 가로/세로(mm)

    if (!ok1 && !ok2) {
        cout << 0 << "\n";
        return 0;
    } else if (ok1 && !ok2) {
        pick = 1; pw = cov1_w; ph = cov1_h;
    } else if (!ok1 && ok2) {
        pick = 2; pw = cov2_w; ph = cov2_h;
    } else {
        // 둘 다 적합: 가로 작은 것 우선, 같으면 세로 작은 것 선택
        if (cov1_w < cov2_w || (cov1_w == cov2_w && cov1_h <= cov2_h)) {
            pick = 1; pw = cov1_w; ph = cov1_h;
        } else {
            pick = 2; pw = cov2_w; ph = cov2_h;
        }
    }

    cout << pick << "\n";
    cout << fixed << setprecision(1)
         << (pw / 10.0) << ' ' << (ph / 10.0) << "\n";
    return 0;
}
