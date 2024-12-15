#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

vector<int> dp;
vector<int> arr;

/*
    가장 긴 감소하는 부분 수열
    LIS 문제 유형... 근데 까뭇다
    처음에는 2차원배열해서 [i][0]은 선택할 경우, [i][1]은 안선택할 경우 이런식으로
    했었는데 이렇게 하면 너무 복잡해짐

    그래서 현재 인덱스 기준 자기보다 더 큰 애들을 세어줌.
    이때, 자기보다 큰 값을 찾으면 그 값을 기준으로 해서
    20 20 10 일 경우 20을 1번만 큰 수로 카운트함.

    O(n^2)인데 개수 max 기준 1,000 *1,000 = 1,000,000회 이므로
    1초 안에 돌아갈 수 있음.
*/

int dpFunc(int n){
    dp[0]=1;

    for(int i=1;i<n;i++){
        int lastNum=arr[i];
        int bigger=1;
        
        for(int j=i-1;j>=0;j--){
            if(lastNum<arr[j]){
                bigger++;
                lastNum=arr[j];
            }
        }

        dp[i]=max(dp[i], bigger);
    }

    /*
    //dp 테이블 출력
    for(auto it:dp){
        cout<<it<<" ";
    }
    cout<<"\n";
    */

    
    return dp[n-1];
}

//이진 탐색 기반으로 시간복잡도를 O(nlogn)까지 줄일 수 있다.
int dpFunc2(int n){
    vector<int> lds;

    for(int x:arr){
        //현재 숫자보다 작은 숫자가 처음 나타나는 위치를 찾음
        auto it = lower_bound(lds.begin(), lds.end(), x, greater<int>());

        if(it==lds.end()){
            //적절한 위치가 없으면 배열에 추가
            lds.push_back(x);
        }
        else{
            *it=x;
        }
        
    }

    /*
    for(auto it:lds){
        cout<<it<<" ";
    }
    cout<<"\n";
    */

    return lds.size();
}

int main() {
    int n;
    cin>>n;

    dp.assign(n, 1);
    arr.resize(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<dpFunc2(n)<<"\n";
    return 0;
}