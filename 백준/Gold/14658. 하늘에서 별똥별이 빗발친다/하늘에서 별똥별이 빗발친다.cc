#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, l, k;
vector<pair<int, int>> stars;

/*
    https://astrid-dm.tistory.com/463
    배열 전체를 순회하려면 500,000*500,000 으로 시간초과가 발생
    대신 별똥별의 갯수는 100개이므로
    100*100*100 3중 for문 돌아도 시간초과 발생 X

    트램펄린을 모든 위치에 설치하여 확인하는 방식이 아닌, 
    별똥별의 위치를 트램펄린 가장자리에 설치하여 
    모든 별똥별의 위치를 기준으로 트램펄린을 설치
*/

int main() {
    cin>>n>>m>>l>>k;
    int preventableStars=0;


    //별똥별 좌표를 pair로 벡터에 저장
    for(int i=0;i<k;i++){
        int x, y;
        cin>>x>>y;
        stars.push_back({x, y});
    }


    for(int i=0;i<k;i++){//별똥별의 x좌표 순회
        for(int j=0;j<k;j++){//별똥별의 y좌표 순회
            int tmpstar=0;
            int x=stars[i].first;
            int y=stars[j].second;
            //별똥별이 없는 위치도 포함하여 탐색하는 이유는, 
            //별똥별이 없는 위치에 트램펄린을 배치했을 때도 
            //다른 별똥별을 튕겨낼 수 있기 때문

            //현재 트램펄린 위치 (x, y)에서
            //(x+l, y+l) 범위 내 별똥별을 카운트
            for(int z=0;z<k;z++){
                int nx=stars[z].first;
                int ny=stars[z].second;

                //입력한 별들 순회하며
                //x~x+l && y~y+l 범위 내라면 카운트 처리
                if(x<=nx&&nx<=x+l&&y<=ny&&ny<=y+l){
                    tmpstar++;
                }
            }
            preventableStars=max(preventableStars, tmpstar);
        }
    }
    
    cout<<k-preventableStars<<"\n";
    
    return 0;
}