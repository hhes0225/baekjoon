#include <bits/stdc++.h>
using namespace std;
const int LEN=8;
const int MAX =400;
const int OFFSET =200;

int N;
vector<vector<int>> axis;
vector<pair<int, int>> papers;

int main() {
    cin >> N;

    papers.resize(N);
    axis.assign(MAX, vector<int>(MAX, 0));

    for(auto&p:papers){
        cin>> p.first>>p.second;
    }

    for(auto p:papers){
        auto [x, y]=p;

        for(int i=x;i<x+LEN;i++){
            for(int j=y;j>y-LEN;j--){
                axis[i+OFFSET][j+OFFSET]++;
            }
        }
    }

    int area=0;
    for(auto i:axis){
        for(auto j:i){
            if(j>0) area++;
        }
    }

    cout<<area<<"\n";

    return 0;
}