#include <bits/stdc++.h>
using namespace std;

int to_minutes(const string& s){
    // "hh:mm"
    int h = stoi(s.substr(0,2));
    int m = stoi(s.substr(3,2));
    return h*60 + m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y;
    if(!(cin >> n >> x >> y)) return 0;

    vector<int> sw(n);
    for(int i=0;i<n;i++){
        string t; cin >> t;
        sw[i] = to_minutes(t);
    }

    const int DAY_END = 23*60 + 59; // 1439
    double charge_rate = 100.0 / y; // % per minute when charging
    double drain_rate  = 100.0 / x; // % per minute when discharging

    double bat = 100.0;   // 시작 100%
    bool charging = true; // 시작은 어댑터(충전)
    int prev_t = 0;       // 00:00

    auto advance = [&](int next_t){
        int dt = next_t - prev_t;          // 이번 구간의 분 수
        if (dt <= 0) return;
        double delta = (charging ? +charge_rate : -drain_rate) * dt;
        bat += delta;
        // 포화 처리
        if (bat > 100.0) bat = 100.0;
        if (bat < 0.0)   bat = 0.0;
        prev_t = next_t;
    };

    // 각 스위치 시각까지 진행 후 토글
    for(int t : sw){
        advance(t);
        charging = !charging;
    }
    // 마지막으로 23:59까지
    advance(DAY_END);

    // 특수 저지: 소수점 3자리 이상 정확도면 OK
    cout.setf(std::ios::fixed);
    cout << setprecision(3) << bat << "\n";
    return 0;
}
