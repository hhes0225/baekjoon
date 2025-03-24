#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> lines;
int maxChoice=0;
vector<pair<int, int>> chosenLine;

bool isDup(int x, int y, int u, int v){
    if((x>=u&&x<=v)||(y>=u&&y<=v)){
        return true;
    }
    return false;
}

void backtracking(int idx){   
    auto [curS, curE]=lines[idx];
    bool canChoose=true;

    //인덱스 벗어나면 현재 상태 저장하고 종료
    if(idx>=n){
        // for(auto c:chosenLine){
        //     cout<<c.first<<" "<<c.second<<" 선택되었다\n";
            
        // }
        // cout<<"\n";

        maxChoice=max(maxChoice, (int)chosenLine.size());
        return;
    }

    //겹치면 종료 XXXXX 다음 경우도 봐야 하기 때문에 선택하지 않도록 bool만 관리해준다
    for(auto c:chosenLine){
        if(isDup(curS, curE, c.first, c.second)){
            // cout<<curS<<", "<<curE<<"는 "<<c.first<<", "<<c.second<<"와 겹친다\n";
            canChoose=false;
        }
    }

    if(canChoose){
        //안겹칠 때, 이 선을 선택하는 경우
        chosenLine.push_back(lines[idx]);

        backtracking(idx+1);

        //데이터 원복
        chosenLine.pop_back();
        //chosenLine.erase(find(chosenLine.begin(), chosenLine.end(), lines[idx]));
    }
    

    //겹치거나 안 겹치거나, 이 선을 선택하지 않는 경우
    backtracking(idx+1);
}


int main() {
    cin >> n;

    lines.resize(n);

    for (auto& l: lines) {
        cin >>l.first>>l.second;
    }


    // Please write your code here.
    backtracking(0);

    cout<<maxChoice<<"\n";

    return 0;
}
