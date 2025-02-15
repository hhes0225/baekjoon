#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; // 사진(파일) 개수

    vector<string> files(n);
    for(int i = 0; i < n; i++){
        cin >> files[i]; // i번째 사진의 파일 이름
    }

    int m;
    cin >> m; // 인터벌(구간) 개수

    // 각 구간 [l, r]에 대해, l부터 r까지의 파일 이름을 출력
    // (1-based index이므로, 내부적으로 0-based로 변환)
    while(m--){
        int l, r;
        cin >> l >> r;
        for(int i = l; i <= r; i++){
            cout << files[i-1] << "\n";
        }
    }

    return 0;
}
