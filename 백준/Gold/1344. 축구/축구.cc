#include <cstdio>

/*
    DP 배열 dp[cur][a][b]는 cur번째 시간 간격까지 진행했을 때 A팀이 a골, B팀이 b골을 득점할 확률

    dp[cur][a][b]는 cur번째 시간 간격에서 가능한 모든 득점 조합을 고려하여 이전 상태에서 현재 상태로의 전이를 계산

    ret += A * B * sol(cur - 1, a - 1, b - 1); : A팀과 B팀 모두 득점하는 경우
    ret += (1 - A) * B * sol(cur - 1, a, b - 1); : B팀만 득점하는 경우
    ret += A * (1 - B) * sol(cur - 1, a - 1, b); : A팀만 득점하는 경우
    ret += (1 - B) * (1 - A) * sol(cur - 1, a, b); : 두 팀 모두 득점하지 않는 경우

    dp[cur][a][b] 배열을 -1.0으로 초기화하여 메모이제이션
    cur == 0인 경우, 즉 첫 번째 간격인 경우에는 1을 반환하여 초기 상태를 설정
*/



// A팀과 B팀의 득점 확률
double A, B;
// DP 배열
double dp[19][19][19];
// 소수가 아닌 득점 수
int k[12] = {0, 1, 4, 6, 8, 9, 10, 12, 14, 15, 16, 18};

// DP 함수
double sol(int cur, int a, int b) {
    // 현재 간격보다 득점이 많거나 득점이 음수인 경우
    if (cur < a || cur < b || a < 0 || b < 0) return 0;
    // 첫 번째 간격인 경우
    if (cur == 0) return 1;

    // 메모이제이션
    double& ret = dp[cur][a][b];
    if (ret != -1.0) return ret;
    ret = 0.0;

    // 점화식
    ret += A * B * sol(cur - 1, a - 1, b - 1);       // A팀과 B팀 모두 득점
    ret += (1 - A) * B * sol(cur - 1, a, b - 1);     // B팀만 득점
    ret += A * (1 - B) * sol(cur - 1, a - 1, b);     // A팀만 득점
    ret += (1 - B) * (1 - A) * sol(cur - 1, a, b);   // 두 팀 모두 득점하지 않음

    return ret;
}

int main() {
    // A팀과 B팀의 득점 확률 입력
    scanf("%lf%lf", &A, &B);
    A /= 100, B /= 100;

    // DP 배열 초기화
    for (int i = 0; i <= 18; i++)
        for (int j = 0; j <= 18; j++)
            for (int k = 0; k <= 18; k++) dp[i][j][k] = -1.0;

    // DP 배열 채우기
    for (int i = 0; i <= 18; i++)
        for (int j = 0; j <= 18; j++) sol(18, i, j);

    // 소수가 아닌 득점 수를 제외한 확률 계산
    double ans = 1;
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++) ans -= dp[18][k[i]][k[j]];

    // 결과 출력
    printf("%.7lf", ans);
}
