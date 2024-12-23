#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
vector<pair<int, int>> lines;

/*
    https://yabmoons.tistory.com/572
    총평: 두루뭉술하게 꾸민 LIS 문제
    dp[i]=i까지 LIS의 길이

    # 왜 LIS 문제냐?
    lines 기준 왼쪽으로 정렬한다.
    그렇게 되었을 때 오른쪽의 Longest Increasing Subsequence가
    전깃줄이 가장 많이 연결될 수 있는 경우.
    따라서 (총 전선수-전깃줄 가장 많이 연결될 수 있는 경우)=없애야 할 전깃줄 수
    가 된다.
    그러므로 전깃줄의 B side(오른쪽, 목적지)의 LIS를 구하면 된다.

    처음에 정렬하는 것까진 알았는데..
    점화식을 아무리 찾으려고 해도 pair로는 깔끔하게 점화식이 안나왔다.
    이럴 땐 한쪽을 skip하고 다른 쪽만 보는 게 깔끔하고 좋은 것 같다.

    # LIS(O(nlogn?인듯? 아마..))
    - 초기화: 새로운 배열에 lines[0] 넣는다.
    - for(배열 순회)
    - 새로운 배열에 lower_bound해서 lines[i] 이상인 값 있으면 대체
    - 없으면 push_back(lines[i]);
    
*/

int dpFunc(int n){
    vector<int> LIS;

    //초기화
    LIS.push_back(lines[0].second);

    for(int i=1;i<n;i++){
        //해당 컨테이너의 반복자(iterator) 타입.
        //vector<int>::iterator
        auto ptr = lower_bound(LIS.begin(), LIS.end(), lines[i].second);
        
        if(ptr!=LIS.end()){
            // 반복자가 가리키는 위치의 값을 newValue로 변경
            *ptr=lines[i].second;
        }
        else{
            LIS.push_back(lines[i].second);
        }
    }

    /*
    //시험출력
    for(auto it:LIS){
        cout<<it<<" ";
    }
    cout<<"\n";
    */

    return n-LIS.size();
}


int main() {
    int n;

    cin>>n;
    dp.assign(n, 0);

    for(int i=0;i<n;i++){
        int from, to;
        cin>>from>>to;
        lines.push_back({from, to});
    }

    //lower_bound(이분탐색) 사용하기 위해 정렬 필요
    sort(lines.begin(), lines.end());

    cout<<dpFunc(n)<<"\n";
    
    return 0;
}