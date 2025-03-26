#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> dots;
vector<pair<int, int>> choice;

int minMaxDist=INT_MAX;

//백트래킹+매개변수탐색..?
//이 아니라 백트래킹+완전탐색

int getDist(int x1, int y1, int x2, int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int groupMaxDist(){
    int tmpDist=0;

    // for(auto c:choice) cout<<c.first<<" "<<c.second<<"\n";
    // cout<<"\n";

    for(int i=0;i<m;i++){
        auto [x1, y1]=choice[i];
        for(int j=i+1;j<m;j++){
            auto [x2,y2]=choice[j];
            // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<": "<<getDist(x1,y1,x2,y2)<<"\n";
            tmpDist=max(tmpDist, getDist(x1,y1,x2,y2));
        }
    }
    return tmpDist;
}



void backtracking(int idx, int choiceCnt){
    if(idx==n){
        if(choiceCnt==m){
            // for(auto c:choice) cout<<c.first<<" "<<c.second<<"\n";
            // cout<<"\n";
            // cout<<groupMaxDist()<<"\n";
            // cout<<"----------\n";

            //최댓값의 최소화
            minMaxDist=min(minMaxDist, groupMaxDist());
            
        }

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

    //for(auto d:dots)cout<<d.first<<" "<<d.second<<"\n";
    backtracking(0, 0);

    cout<<minMaxDist<<"\n";

    return 0;
}
