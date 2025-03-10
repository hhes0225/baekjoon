#include <bits/stdc++.h>
using namespace std;
const int MAX=100;

int n;
vector<int> simul;
vector<pair<int, int>> lines;
vector<int> dotMap;

void GetMaxDup(){
    for(auto l:lines){
        int newF=lower_bound(dotMap.begin(), dotMap.end(), l.first)-dotMap.begin();
        int newT=lower_bound(dotMap.begin(), dotMap.end(), l.second)-dotMap.begin();

        for(int i=newF;i<newT;i++) simul[i]++;
    }

    //for(auto s:simul) cout<<s<<" ";
}

int main() {
    cin >> n;

    simul.assign(MAX, 0);
    lines.resize(n);

    for(auto &l:lines){
        cin>>l.first>>l.second;
        dotMap.push_back(l.first);
        dotMap.push_back(l.second);
    }

    sort(dotMap.begin(), dotMap.end());
    dotMap.erase(unique(dotMap.begin(), dotMap.end()), dotMap.end());//중복 제거

    GetMaxDup();

    cout<<*max_element(simul.begin(), simul.end());

    return 0;
}