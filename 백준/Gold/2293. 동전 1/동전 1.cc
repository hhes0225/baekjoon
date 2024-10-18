#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//coinDp[i] 의미
//i원이 되는 동전 조합의 경우의 수
vector<int> coinDp;
vector<int> coins;
int n, k;

void dp(){
    //중복 제거
    //동전 리스트를 순회하면서
    for (int i = 0; i < coins.size(); i++) {
        //j원을 만드는 경우의 수 더해감
        for (int j = coins[i]; j <= k; j++) {
            coinDp[j] += coinDp[j - coins[i]];  // 현재 동전으로 만들 수 있는 경우 추가
        }
    }

    /*
    for(int i=0;i<coins.size();i++){
        coinDp[coins[i]]++;
    }

    //중복 포함
    //i원까지 만들 수 있는 경우의 수 찾겠어
    for(int i=0;i<coinDp.size();i++){
        //동전 리스트 순회하면서 i원 만들 수 있도록 하겠어
        for(int j=0;j<coins.size();j++){
            if(i-coins[j]>0){
                coinDp[i]+=coinDp[i-coins[j]];
            }
        }
    }
    

    for(int i=0;i<coinDp.size();i++){
        cout<<coinDp[i]<<" ";
    }
    cout<<"\n";
    */
}

int main() {

    cin>>n>>k;

    coinDp.assign(k+1, 0);
    coinDp[0]=1;
    coins.resize(n);
    
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    sort(coins.begin(), coins.end());
    dp();

    cout<<coinDp[coinDp.size()-1];
    
    return 0;
}
