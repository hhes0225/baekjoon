#include <bits/stdc++.h>
using namespace std;
const int MAX=4000;
const int OFFSET=2000;

struct Rect{
    int x1, y1, x2, y2;
};

vector<vector<int>> axis;


int main() {
    vector<Rect> r;
    r.resize(2);
    axis.assign(MAX, vector<int>(MAX, 0));

    cin>>r[0].x1>>r[0].y1>>r[0].x2>>r[0].y2;
    cin>>r[1].x1>>r[1].y1>>r[1].x2>>r[1].y2;

    for(int i=r[0].x1;i<r[0].x2;i++){
        for(int j=r[0].y1;j<r[0].y2;j++){
            axis[i+OFFSET][j+OFFSET]++;
        }
    }

    for(int i=r[1].x1;i<r[1].x2;i++){
        for(int j=r[1].y1;j<r[1].y2;j++){
            axis[i+OFFSET][j+OFFSET]--;
        }
    }

    int left=INT_MAX, right=0, down=INT_MAX, up=0;
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            if(axis[i][j]==1){
                left=min(left, j);
                right=max(right, j);
                down=min(down, i);
                up=max(up, i);
            }
        }
    }

    int area=(right-left+1)*(up-down+1);
    cout<<area<<"\n";

    return 0;
}