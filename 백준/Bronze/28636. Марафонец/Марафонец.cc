#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int n;
    cin >> n;  // 노래의 개수 입력
    
    int totalMinutes = 0, totalSeconds = 0;
    
    for (int i = 0; i < n; i++) {
        string songTime;
        cin >> songTime;  // 노래의 시간 입력
        
        // songTime은 "mm:ss" 형식
        int minutes, seconds;
        // 문자열을 ":"을 기준으로 분리
        stringstream ss(songTime);
        char colon;
        ss >> minutes >> colon >> seconds;
        
        // 분과 초를 각각 합산
        totalMinutes += minutes;
        totalSeconds += seconds;
    }
    
    // 초가 60 이상이면 분을 증가시킴
    totalMinutes += totalSeconds / 60;
    totalSeconds = totalSeconds % 60;
    
    // 분이 60 이상이면 시간을 증가시킴
    int hours = totalMinutes / 60;
    totalMinutes = totalMinutes % 60;
    
    // 시간, 분, 초를 두 자릿수 형식으로 출력
    printf("%02d:%02d:%02d\n", hours, totalMinutes, totalSeconds);
    
    return 0;
}
