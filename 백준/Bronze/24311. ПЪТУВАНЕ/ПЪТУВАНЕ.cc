#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int t1, t2; // 회의 시작 시각 (시, 분)
    cin >> t1 >> t2;

    int t3;     // 등록 시간 (분)
    cin >> t3;

    int t4, t5; // 이동 시간 (시, 분)
    cin >> t4 >> t5;

    int br;     // 학생 수
    cin >> br;

    int t6;     // 한 명 숙소 체크인 시간 (분)
    cin >> t6;

    // 1) 회의 시작 10분 전까지 도착해야 함
    int arrival_deadline = t1 * 60 + t2 - 10;

    // 2) 전체 소요 시간 계산
    int travel_time      = t4 * 60 + t5;
    int checkin_time     = (br + 1) * t6; // 학생(br) + 감독(1) 모두 포함!
    int registration_time = t3;

    int total_needed = travel_time + checkin_time + registration_time;

    // 3) 출발 시각 = 도착 기한 - 전체 소요 시간
    int depart = arrival_deadline - total_needed;
    int hour   = depart / 60;
    int minute = depart % 60;

    // 4) 두 자리 형식으로 출력
    cout << setfill('0') << setw(2) << hour << " "
         << setfill('0') << setw(2) << minute << "\n";
    return 0;
}
