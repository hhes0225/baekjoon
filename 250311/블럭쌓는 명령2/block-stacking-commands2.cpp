#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> blocks;
vector<pair<int, int>> inputs;

int main() {
    cin >> N >> K;

    blocks.assign(N, 0);
    inputs.resize(K);

    for (auto &i:inputs) {
        cin >> i.first >> i.second;
        i.first--;
        i.second--;
    }

    for(auto i:inputs){
        auto [from, to]=i;

        for(int j=from;j<to+1;j++) blocks[j]++;
    }


    cout<<*max_element(blocks.begin(), blocks.end());

    return 0;
}