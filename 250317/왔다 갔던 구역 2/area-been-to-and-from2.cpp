#include <bits/stdc++.h>
using namespace std;

const int SIZE = 10001; 
const int OFFSET = 5000;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    vector<pair<int, char>> command(n);
    for(auto &c : command) {
        cin >> c.first >> c.second; 
    }

    // "구간" 방문 횟수를 기록할 배열
    // visit[x] = "좌표 (x - OFFSET)에서 (x - OFFSET + 1)로 이어지는 구간"의 방문 횟수
    static int visit[SIZE] = {0};  

    int cur = 0;  // 실제 좌표계에서 시작을 0으로 가정

    for(auto &cmd : command){
        int dist = cmd.first;
        char dir = cmd.second;

        if(dir == 'R'){
            // 오른쪽으로 dist만큼 이동
            // cur → cur+1 → cur+2 → ... → cur+dist
            for(int i = 0; i < dist; i++){
                // (cur, cur+1) 구간을 방문
                visit[cur + OFFSET]++; 
                cur++;
            }
        }
        else { // dir == 'L'
            // 왼쪽으로 dist만큼 이동
            // cur → cur-1 → cur-2 → ... → cur-dist
            for(int i = 0; i < dist; i++){
                // 먼저 왼쪽으로 이동한 뒤, (cur, cur+1) 구간을 체크
                cur--;
                visit[cur + OFFSET]++; 
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < SIZE; i++){
        if(visit[i] >= 2) ans++;
    }

    cout << ans << "\n";
    return 0;
}
