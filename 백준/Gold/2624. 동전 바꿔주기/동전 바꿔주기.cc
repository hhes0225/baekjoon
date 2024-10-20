#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;

int t, k;
vector<pair<int, int>> coins;
vector<int> dpTable;//i원 만드는 경우의 수
vector<vector<int>> dp2Dtb;
//i번째 동전까지 사용했을 때, j원 만들 수 있는 경우의 수


//1차원 배열 사용
void dp() {
    dpTable[0] = 1;  // 0원을 만드는 경우는 1가지 (아무 동전도 사용하지 않음)
    
    for (int i = 0; i < coins.size(); i++) {  // 보유 코인 순회
        //역순: 같은 동전 중복 사용 방지 위함
        for (int j = t; j >= coins[i].first; j--) {  // 목표 금액까지 순회
            for(int amount=1;amount<=coins[i].second;amount++){
                if(j-amount*coins[i].first>=0)
                    dpTable[j] += dpTable[j - amount*coins[i].first];   
            }
        }
    }

    /*
    // DP 테이블 출력
    for (int i = 0; i < dpTable.size(); i++) {
        cout << dpTable[i] << " ";
    }
    cout << "\n";
    */
}


int main() {
    cin>>t>>k;

    dpTable.assign(t+1, 0);

    for(int i=0;i<k;i++){
        int val, amount;
        cin>>val>>amount;

        coins.push_back({val, amount});
    }

    sort(coins.begin(), coins.end());

    dp();

    cout<<dpTable[t]<<"\n";
    
    return 0;
}