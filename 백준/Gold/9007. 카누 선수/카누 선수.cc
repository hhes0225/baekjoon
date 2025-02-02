#include <bits/stdc++.h>
#define C 4
using namespace std;

/*
    자체 태그맞추기 : 이분탐색
    이유: 어느 시점부터 조건을 만족하는데, 그 조건을 만족하게 되는 최소 시점이 어디인가?
    + 4중 for문 돌리면 O(n^4)인데, 시간초과 날 것 같아서 일단 브루트포스는 아닌 것 같았

    그런데 1차원 배열에서만 이분탐색을 했었는데
    nxn 의 경우에는 어떻게 해야 할지..
    https://khu98.tistory.com/120 
*/

//두 벡터의 요소 합에 대한 모든 경우의 수
vector<int> vectorSum(vector<int>& a, vector<int> b){
    vector<int> sums;

    for(auto i:a){
        for(auto j:b){
            sums.push_back(i+j);
        }
    }

    sort(sums.begin(), sums.end());
    //중복 제거
    sums.erase(unique(sums.begin(), sums.end()), sums.end());

    /*출력
    for(auto it:sums){
        cout<<it<<" ";
    }
    cout<<"\n";
    */
    
    return sums;
}

int getBestWeight(const int k, const vector<int>& a, const vector<int>& b){
    int goal=k;
    int minDiff=INT_MAX;
    int bestWeight=0;

    for(auto i:a){
        int rest=k-i;//0~1반 합을 뺐을 때 남은 값
        int bIdx;

        auto it = lower_bound(b.begin(), b.end(), rest);

        if(it!=b.end()){
            int candidate=i+*it;
            int diff=abs(k-candidate);

            if(diff<minDiff || (diff==minDiff&&candidate<bestWeight)){
                minDiff=diff;
                bestWeight=candidate;
            }
        }
        if(it!=b.begin()){
            int candidate=i+*(it-1);
            int diff=abs(k-candidate);
            if(diff<minDiff||(diff==minDiff&&candidate<bestWeight)){
                minDiff=diff;
                bestWeight=candidate;
            }
        }
    }

    return bestWeight;
}

int main() {
    int tCase;
    cin>>tCase;

    for(int i=0;i<tCase;i++){
        int k, n;
        cin>>k>>n;

        vector<vector<int>> classes;
        classes.resize(C, vector<int>(n));

        for(auto& i:classes){
            for(auto& j:i){
                cin>>j;
            }
        }

        vector<int> sum0_1;
        vector<int> sum2_3;

        //0반, 1반에 대한 합들의 경우의 수
        sum0_1=vectorSum(classes[0], classes[1]);
        //2반, 3반에 대한 합들의 경우의 수
        sum2_3=vectorSum(classes[2], classes[3]);

        int ans=getBestWeight(k, sum0_1, sum2_3);

        cout<<ans<<"\n";
    }

    
    return 0;
}