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
    for (int i = 0; i < coins.size(); i++) {
        for (int j = coins[i]; j <= k; j++) {
            coinDp[j] += coinDp[j - coins[i]];  // 현재 동전으로 만들 수 있는 경우 추가
        }
    }

    /*
    for(int i=0;i<coins.size();i++){
        coinDp[coins[i]]++;
    }

    
    for(int i=0;i<coinDp.size();i++){
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