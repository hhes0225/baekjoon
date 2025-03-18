#include <bits/stdc++.h>
using namespace std;
const int MAX=4000;
const int OFFSET=2000;


struct Rect{
    int x1, y1, x2, y2;
};
vector<Rect> rects;
vector<vector<int>> axis;

int main() {
    rects.resize(3);

    for(auto &r:rects){
        cin>>r.x1>>r.y1>>r.x2>>r.y2;
    }

    axis.resize(MAX, vector<int>(MAX, 0));

    for(int i=rects[0].x1;i<rects[0].x2;i++){
        for(int j=rects[0].y1;j<rects[0].y2;j++){
            axis[i+OFFSET][j+OFFSET]++;
        }
    }

    for(int i=rects[1].x1;i<rects[1].x2;i++){
        for(int j=rects[1].y1;j<rects[1].y2;j++){
            axis[i+OFFSET][j+OFFSET]++;
        }
    }

    for(int i=rects[2].x1;i<rects[2].x2;i++){
        for(int j=rects[2].y1;j<rects[2].y2;j++){
            axis[i+OFFSET][j+OFFSET]=0;
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