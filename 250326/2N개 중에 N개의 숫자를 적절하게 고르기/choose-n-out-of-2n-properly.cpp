#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> num;
vector<int> group1;
vector<int> group2;
int minDiff=INT_MAX;

void backtracking(int idx){
    //탈출조건: 마지막 원소까지 다 넣었을 때
    //각 그룹 간 원소 합 구하기
    //각 그룹 합 빼기
    //최소 차 갱신

    if(idx==2*n){
        // for(auto g:group1) cout<<g<<" ";
        // cout<<"\n";
        // for(auto g:group2) cout<<g<<" ";
        // cout<<"\n";
        if(group1.size()==n&&group2.size()==n){
            int sum1=0, sum2=0;

            for(auto g:group1) sum1+=g;
            for(auto g:group2) sum2+=g;

            minDiff=min(minDiff, abs(sum1-sum2));
        }
        return;
    }


    //그룹 1에 넣었을 때
    group1.push_back(num[idx]);
    backtracking(idx+1);
    group1.pop_back();

    //그룹 2에 넣었을 때
    group2.push_back(num[idx]);
    backtracking(idx+1);
    group2.pop_back();
}


int main() {
    cin >> n;
    num.resize(n*2);

    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
    }

    // Please write your code here.
    backtracking(0);

    cout<<minDiff<<"\n";

    return 0;
}
