#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> coins;
vector<int> dpTable;
//k원일때 사용되는 최소 동전 개수

void dp(){
    //dpTable[0]=0;
    
    for(int i=0;i<coins.size();i++){
        dpTable[coins[i]]=1;
        //coins[i]원을 만들기 위한 최소 동전 개수는 1개
    }

    for(int i=1;i<=k;i++){
        for(int j=0;j<coins.size();j++){
            if(i-coins[j]>=0)
                //만약 coins[j] 동전으로 표현 가능하다면
                dpTable[i]=min(dpTable[i], dpTable[i-coins[j]]+1);
                //현 총액i-coins[j] 금액(이전 금액)에 해당 동전인 coins[j]를 한 개를 추가하므로 +1
        }
    }

    /* dp 테이블 출력
    for(int j=1;j<=k;j++){
        cout<<dpTable[j]<<" ";
    }
    cout<<"\n";
    */
    
}


int main() {
    cin>>n>>k;

    //k+1로 설정해야 무게 k까지 확인할 수 있음
    dpTable.assign(k+1, 1e5);
    coins.resize(n);

    for(int i=0;i<n;i++){
        cin>>coins[i];     
    }

    dp();

    if(dpTable[k] != 1e5)
        cout<<dpTable[k]<<"\n";
    else
        cout<<"-1\n";
    
    return 0;
}