#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> lines;
int maxChoice=0;
vector<pair<int, int>> chosenLine;

bool isDup(int x, int y, int u, int v){
    if(x>=u||x<=v||y>=u||y<=v){
        return true;
    }
    return false;
}

void backtracking(int idx){   
    auto [curS, curE]=lines[idx];
    //겹치면 종료
    for(auto c:chosenLine){
        if(isDup(curS, curE, c.first, c.second)){
            maxChoice=max(maxChoice, chosenLine.size());
        }
    }

    //안겹칠 때, 이 선을 선택하는 경우
    chosenLine.push_back(lines[idx]);

    backtracking(idx+1);

    //데이터 원복
    chosenLine.pop_back();
    //chosenLine.erase(find(chosenLine.begin(), chosenLine.end(), lines[idx]));

    //안겹칠 때, 이 선을 선택하지 않는 경우
    backtracking(idx+1);
}


int main() {
    cin >> n;

    for (auto& l: lines) {
        cin >>l.first>>l.second;
    }

    // Please write your code here.
    backtracking(0);

    cout<<maxChoice<<"\n";

    return 0;
}
