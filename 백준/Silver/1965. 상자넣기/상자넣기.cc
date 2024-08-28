#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> boxes;
vector<int> dp;

/*
    dp[i]가 의미하는 것
    : i 번째 상자가 최대로 담을 수 있는 상자 개수
    1로 초기화 -> 각 상자는 최소 자기 자신 하나 포함

    점화식(잘못생각함)
    만약 boxes[i]가 boxes[i-1]보다 클 경우
    : boxes[i-1]을 넣는다

    그렇지 않고 boxes[i]가 boxes[i-1]보다 같거나 작을 경우
    : i-1이전 박스 중에서 넣을 수 있으면서 가장 작은 값을 찾아서
    그 때의 dp값+1을 한다. 
    즉, 탐색으로 나온 상자를 i번째 상자에 넣는다

    반례)
    6
    1 2 1 10 4 5

    올바른 dp 테이블
    1 2 1 3 3 4

    위 점화식으로 나오는 dp 테이블
    1 2 1 2 3 4
    (최적의 해가 나오지 않음)

    최장 증가 부분 수열 (LIS, Longest Increasing Subsequence) 알고리즘
    이중 for 문으로 수행
    for (int k = 0; k < n; k++){
    	length[k] = 1;
        for (int i = 0; i < k; i++){
            if(arr[i] < arr[k]){
                length[k] = max(length[k], length[i] + 1);
            }
        }
    }
    
    i-1이전 박스 중에서 넣을 수 있으면서 가장 작은 값을 찾아서
    그 때의 dp값+1을 한다.
    else문에 넣은 것과 동일. 단지 if로 필터링하지 않고
    모든 경우에 대해 else에서 수행하던 것을 수행함

    단, dp로 풀 경우 시간복잡도가 O(n^2)

    
*/
bool changed=false;

int memoi(){
    //dp[0]=1;

    for(int i=1;i<boxes.size();i++){
        //이전 상자 탐색
        for(int j=i-1;j>=0;j--){
            if(boxes[i]>boxes[j]){
                dp[i]=max(dp[i], dp[j]+1);
            }
        }
        /*
        for(auto it:dp){
            cout<<it<<" ";
        }
        cout<<endl;
        */
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    int tCase;
    cin>>tCase;

    boxes.resize(tCase);
    dp.assign(tCase,1);

    for(int i=0;i<tCase;i++){
        cin>>boxes[i];
    }

    int result = memoi();

    /*
    for(auto it:dp){
        cout<<it<<" ";
    }
    cout<<endl;
    */

    cout<<result<<"\n";
    
    return 0;
}