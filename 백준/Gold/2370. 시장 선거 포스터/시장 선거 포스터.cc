#include <bits/stdc++.h>
#define MAX 20'000
using namespace std;
typedef pair<int, int> PII;

/*
    좌표 압축)
    https://chocochoco348.tistory.com/54
    https://ezeun.tistory.com/81
    
    
    좌표의 총 개수
    좌표 자체는 최대 10'000개
    그러나 가장 많을 경우,
    왼쪽 좌표와 오른쪽 좌표 모두 다를 때,
    ex) (1,2) (3,4) (5,6)... 
    나올 수 있는 최대 좌표값의 개수는 20'000개

    따라서 100'000'000까지 범위의 좌표를
    20'000으로 압축할 수 있다.
*/

vector<PII> posters;
vector<int> compress;
vector<int> wall;
set<int> visiblePoser;//set 쓰는게 더 나았을듯


int main() {
    int n;
    cin>>n;

    posters.resize(n);
    wall.assign(MAX, -1);

    for(int i=0;i<n;i++){
        cin>>posters[i].first>>posters[i].second;
        compress.push_back(posters[i].first);
        compress.push_back(posters[i].second);
    }

    //1. 포스터의 좌, 우가 위치하는 지점 정렬
    sort(compress.begin(), compress.end());
    //2. unique로 중복제거
    compress.erase(unique(compress.begin(), compress.end()), compress.end());
    
    

    for(int i=0;i<n;i++){
        //3. lower_bound로 압축된 좌표로 변환
        int left=lower_bound(compress.begin(), compress.end(), posters[i].first)-compress.begin();
        int right=lower_bound(compress.begin(), compress.end(), posters[i].second)-compress.begin();

        //압축 좌표 영역(벽)에 붙여질 포스터 표시
        for(int j=left;j<=right;j++){
            wall[j]=i+1;
        }
    }

    for(int i=0;i<MAX;i++){
        if(wall[i]!=-1){
            visiblePoser.insert(wall[i]);
        }
    }

    //같은 포스터인데 다른 포스터 위에 일부 가린 경우 중복 제거
    //ex. 11122111
    //unique 사용하기 위해 정렬되어 있어야 함
    //sort(visiblePoser.begin(), visiblePoser.end());
    //visiblePoser.erase(unique(visiblePoser.begin(), visiblePoser.end()), visiblePoser.end());

    /*
    for(auto it:visiblePoser){
        cout<<it<<"\n";
    }
    */

    cout<<visiblePoser.size()<<"\n";

    
    return 0;
}