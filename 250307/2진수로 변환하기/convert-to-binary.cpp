#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    cin >> n;
    vector<int> decToBin;

    while(n>1){
        decToBin.push_back(n%2);
        n/=2;
    }

    decToBin.push_back(n);

    reverse(decToBin.begin(), decToBin.end());

    for(auto d:decToBin){
        cout<<d;
    }

    return 0;
}