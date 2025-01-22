#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

vector<PII> lines;
vector<int> lisLen;
//오직 길이만 맞다! 요소와 순서는 틀릴 수 있는 배열
vector<int> dp;
//B 위치에서의 i번째 전선줄의 LIS,
//i 번째 전선줄까지의 최장 길이는?
vector<PII> lisLines;//LIS에 포함되는 선들

void LIS(int n){
    dp[0]=1;
    lisLen.push_back(lines[0].second);

    //길이 구하기+dp 배열 채우기
    for(int i=1;i<n;i++){
        auto&[a, b]=lines[i];

        auto it = lower_bound(lisLen.begin(), lisLen.end(), b);

        if(it!=lisLen.end()){//최댓값이 아니면
            *it=b;
            dp[i]=it-lisLen.begin()+1;
        }
        else{
            lisLen.push_back(b);
            dp[i]=lisLen.size();
        }
    }

    /*for(auto it:dp){
        cout<<it<<" ";
    }
    cout<<"\n";
    for(auto it:lisLen){
        cout<<it<<" ";
    }
    cout<<"\n";*/

    //LIS의 최대 지점 구하기
    int maxIdx=max_element(dp.begin(), dp.end())-dp.begin();
    lisLines.push_back(lines[maxIdx]);

    //LIS 요소로서 포함되는 지점 구하기(lines 전깃줄로 원복)
    //여기서는 lisLines를 출력하는 것이 아니라
    //lines에서 lisLines에 없는 것을 탐색할 예정이므로
    //reverse할 필요 없음
    for(int i=maxIdx-1; i>=0;i--){
        if(dp[i]+1==dp[maxIdx]){
            maxIdx=i;
            lisLines.push_back(lines[i]);
        }
    }
    
    /*for(auto it:lisLines){
        cout<<it.first<<" "<<it.second<<"\n";
    }
    cout<<"\n";*/

    
    //최종 결과 출력
    cout<<lines.size()-lisLen.size()<<"\n";
    for(auto it:lines){
        if(find(lisLines.begin(), lisLines.end(), it)==lisLines.end()){
            cout<<it.first<<"\n";
        }
    }

    
}

int main() {
    int n;
    cin>>n;

    lines.resize(n);
    dp.resize(n);

    for(auto& it:lines){
        cin>>it.first>>it.second;
    }

    sort(lines.begin(), lines.end());
    
    LIS(n);
    
    return 0;
}