#include <bits/stdc++.h>
using namespace std;
const int MAX=400;
const int OFFSET=200;
const int RED=1;
const int BLUE=-1;

struct Rect{
    int x1, y1, x2, y2;
};

int n;
vector<Rect> rects;
vector<vector<int>> axis;


int main() {
    cin >> n;

    rects.resize(n);
    axis.assign(MAX, vector<int>(MAX, 0));

    for(auto& r:rects){
        cin>>r.x1>>r.y1>>r.x2>>r.y2;
    }

    for(int i=0;i<n;i++){
        if(i%2==0){
            for(int j=rects[i].x1;j<rects[i].x2;j++){
                for(int k=rects[i].y1;k<rects[i].y2;k++){
                    axis[j+OFFSET][k+OFFSET]=RED;
                }
            }
        }
        else{
            for(int j=rects[i].x1;j<rects[i].x2;j++){
                for(int k=rects[i].y1;k<rects[i].y2;k++){
                    axis[j+OFFSET][k+OFFSET]=BLUE;
                }
            }
        }
    }

    int area=0;

    for(auto i:axis){
        for(auto j:i){
            if(j==BLUE) area++;
        }
    }

    cout<<area<<"\n";
    
    return 0;
}