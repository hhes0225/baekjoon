#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
    풀이법:
    숫자가 n개 주어질 때, 그 중 1~n개 숫자를 골라
    그 원소를 다 더한 값이 S가 되는 경우의 수

    재귀 탈출조건:  인덱스 탐색 마지막 인덱스일 경우
    현재까지의 합과 인덱스를 매개변수로 넘겨주기

    sum==S 일 떄는 리턴하지 않음!!!
    target이 0일때,
    -1 1 -2 2

    여기서 -1+1, -2+2, -1+1-2+2 세 가지 고려해야 하는데
    sum==S에서 리턴하면 -1+1, -2+2 두 가지로, 0 되자마자 바로
    리턴 때려버려서 -1+1-2+2처럼 나중에 0이 되는 경우 기록을 못함

    원복시킬 때에는 경우의 수 카운트는 그대로 두고
    합에서 현재 대상 값을 빼고 visited[현재 인덱스] false로
    
    
    시간복잡도:
    최대 depth==20
    n!일거같은데... 근데 20!은 너무 커서 어떻게 되는지 모르겠음.
    2초면 20억인데..20!은 20억 넘는달까..?

    자료구조:
    - 인풋 vector
    - visited vector
    - 합: 최대 나올 수 있는 합이 100,000*20 2백만 정도로,
    long long 필요 없음. int만으로 충분(20억)
    - 경우의 수: int..? 안되면 long long...?
    경우의 수 몇 번이 나올지 모르겠네.
*/

int n, s;
vector<int> nums;
vector<int> visited;
ll ans=0;
int depth=0;

void recur(int curSum, int idx){
    if(curSum==s){
        //cout<<idx<<": 합이 target이므로 리턴\n";
        ans++;
    }
    if(idx==nums.size()) {
        //cout<< "마지막 인덱스 탐색으로 리턴\n";
        return;
    }

    //cout<<"depth: "<<depth<<"\n";
    
    for(int i=idx+1;i<nums.size();i++){
        int nextSum=curSum;
        if(!visited[i]){
            visited[i]=true;
            nextSum+=nums[i];
            //cout<<"더해지는 값: "<<nums[i]<<" new 합: "<<nextSum<<"\n";

            //depth++;
            //재귀
            recur(nextSum, i);
            //cout<<depth<<"끝! pop!\n";

            //데이터 원복
            visited[i]=false;
            //depth--;
        }
    }
}

int main() {
    cin>>n>>s;
    
    nums.resize(n);
    visited.assign(n, false);

    for(auto& it:nums){
        cin>>it;
    }


    for(int i=0;i<n;i++){
        recur(nums[i], i);
    }
    

    cout<<ans<<"\n";
    
    return 0;
}