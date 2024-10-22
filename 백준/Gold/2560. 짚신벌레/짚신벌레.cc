#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b, d, N;
    cin >> a >> b >> d >> N;

    const int MOD = 1000;

    vector<long long> new_born(N + d + 1, 0);
    vector<long long> alive(N + d + 1, 0);
    vector<long long> reproduce(N + d + 1, 0);

    new_born[0] = 1; // 처음에는 한 마리가 태어남
    alive[0] = 1;

    for(int i = 1; i <= N; i++) {
        // i일째에 번식을 시작하는 벌레 수
        long long start_reproduce = 0;
        if(i - a >= 0) {
            start_reproduce = new_born[i - a] % MOD;
        }

        // i일째에 번식을 종료하는 벌레 수
        long long end_reproduce = 0;
        if(i - b >= 0) {
            end_reproduce = new_born[i - b] % MOD;
        }

        // i일째에 번식 가능한 벌레 수 업데이트
        reproduce[i] = (reproduce[i - 1] + start_reproduce - end_reproduce + MOD) % MOD;

        // i일째에 태어나는 새로운 벌레 수 (번식 가능한 벌레들이 한 마리씩 낳음)
        new_born[i] = reproduce[i] % MOD;

        // i일째에 죽는 벌레 수
        long long deaths = 0;
        if(i - d >= 0) {
            deaths = new_born[i - d] % MOD;
        }

        // i일째에 살아있는 벌레 수 업데이트
        alive[i] = (alive[i - 1] + new_born[i] - deaths + MOD) % MOD;
    }

    cout << alive[N] % MOD << endl;

    return 0;
}
