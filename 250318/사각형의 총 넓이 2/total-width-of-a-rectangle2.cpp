#include <bits/stdc++.h>
using namespace std;
const int OFFSET=200;
const int MAX=400;

int N;
struct Square{
    int x1, y1, x2, y2;
};

vector<Square> rects;
vector<vector<int>> axis;
int area=0;

int main() {
    cin >> N;
    rects.resize(N);
    axis.assign(MAX, vector<int>(MAX, 0));

    for(auto &r:rects){
        cin>>r.x1>>r.y1>>r.x2>>r.y2;
    }

    for(auto r:rects){
        for(int i=r.x1+OFFSET;i<r.x2+OFFSET;i++){
            for(int j=r.y1+OFFSET;j<r.y2+OFFSET;j++){
                axis[i][j]++;
            }
        }
    }

    for(auto i:axis){
        for(auto j:i){
            if(j>0) area++;
        }
    }

    cout<<area<<"\n";

    return 0;
}