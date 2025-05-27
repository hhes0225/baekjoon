#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
vector<bool> visited;
vector<int> comb;
set<vector<int>> combList;

void backtracking(int idx, int m){
    if(m==0){
        //set에 추가함으로써 중복되는 수열 제거
        combList.insert(comb);


        return;
    }

    for(int i=0; i<nums.size();i++){
        //미방문일 때만 조합에 추가
        if(!visited[i]){
            visited[i]=true;
            comb.push_back(nums[i]);

            backtracking(i+1, m-1);

            //원복
            visited[i]=false;
            comb.pop_back();
        }
    }
}

int main() {
    int n, m;
    cin>>n>>m;

    nums.resize(n);
    visited.assign(n, false);

    for(auto &n:nums) cin>>n;

    sort(nums.begin(), nums.end());

    backtracking(0, m);

    // combList에서 모든 조합을 출력
    for(const auto &c : combList){
        for(const auto &x : c){
            cout << x << " ";
        }
        cout << "\n";
    }
    
    return 0;
}