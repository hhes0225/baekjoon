#include <bits/stdc++.h>
using namespace std;
const int MAX= 202;

int n;
vector<pair<int, int>> inputs;
vector<int> simul;
vector<int> dotMap;

void getMaxDup(){
    for(auto i:inputs){
        auto [from, to]=i;

        int newF=lower_bound(dotMap.begin(), dotMap.end(), from)-dotMap.begin();
        int newT=lower_bound(dotMap.begin(), dotMap.end(), to)-dotMap.begin();
        //cout<<newF<<" "<<newT<<"\n";

        for(int j=newF;j<=newT;j++) simul[j]++;
    }
}

int main() {
    cin >> n;

    inputs.resize(n);
    simul.assign(MAX, 0);

    for (auto& i:inputs) {
        cin>>i.first>>i.second;

        dotMap.push_back(i.first);
        dotMap.push_back(i.second);
    }

    sort(dotMap.begin(), dotMap.end());
    dotMap.erase(unique(dotMap.begin(), dotMap.end()), dotMap.end());

    //for(auto d:dotMap) cout<<d<<" ";
    //cout<<"\n";
    getMaxDup();
    //for(auto s:simul) cout<<s<<" ";

    cout<<*max_element(simul.begin(), simul.end());

    return 0;
}