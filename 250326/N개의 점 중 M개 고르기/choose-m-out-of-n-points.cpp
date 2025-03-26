#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> dots;
vector<pair<int, int>> choice;

//백트래킹+매개변수탐색..?

int getDist(int x1, int y1, int x2, int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

void getMinDist()

void backtracking(int idx, int choiceCnt){
    if(choiceCnt==m){
        return;
    }

    //선택했을 때
    choice.push_back(dots[idx]);
    backtracking(idx+1, choiceCnt+1);
    choice.pop_back();

    //선택하지 않았을 때
    backtracking(idx+1, choiceCnt);
}



int main() {
    cin >> n >> m;

    dots.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> dots[i].first>>dots[i].second;
    }

    // Please write your code here.
    sort(dots.begin(), dots.end());

    for(auto d:dots)cout<<d.first<<" "<<d.second<<"\n";

    return 0;
}
