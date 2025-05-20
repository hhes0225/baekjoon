#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
int main() {
    int n, l;
    cin>>n>>l;

    vector<pair<int, int>> pool(n);
    for(auto &p: pool){
        cin>>p.first>>p.second;
    }

    //정렬
    sort(pool.begin(), pool.end());

    vector<PII> rerange;

    rerange.push_back(pool[0]);
    for(int i=1;i<n;i++){
        auto [from, to]=rerange.back();
        int prevLen=to-from;
        // cout<<prevLen<<" "<<prevLen%l<<"\n";
        // cout<<pool[i].first-to<<"\n";

        //이전 널빤지가 이미 남는 공간 없이 완벽 커버한 경우
        if(prevLen % l == 0){
            // cout<<"완벽 커버\n";
            rerange.push_back(pool[i]);
        }
        //이전 널빤지에 남는 공간 있지만, 다음 거 커버할 정도로 길진 않음
        else if(pool[i].first - to > (l-(prevLen % l))){
            // cout<<"다음거 커버 불가\n";
            rerange.push_back(pool[i]);
        }
        //이전 널빤지 남는 공간 있고 다음 거 커버 가능하면, 덮자->범위 연장
        else{
            rerange.back().second=pool[i].second;
        }
        
    }

    int minWood=0;
    
    for(auto r:rerange){
        int len=r.second-r.first;
        // cout<<r.first<<"~"<<r.second<<":"<<len<<"\n";
        // cout<<len/l<<"\n";

        if(len%l!=0) minWood+=(len/l+1);
        else         minWood+=(len/l);
    }
    cout<<minWood<<"\n";
    
    return 0;
}