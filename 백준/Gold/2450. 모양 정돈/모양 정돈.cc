#include <bits/stdc++.h>
using namespace std;
const int ALLCASE=6;
const int TRIANGLE=1;
const int SQUARE=2;
const int CIRCLE=3;

vector<int> inputs;
vector<int> compare;
vector<int> cnt;
int minChange=INT_MAX;


int main() {
    int n;
    cin>>n;

    inputs.resize(n);
    cnt.resize(4);

    for(auto &i:inputs){
        cin>>i;
        cnt[i]++;
    }

    compare.push_back(TRIANGLE);
    compare.push_back(SQUARE);
    compare.push_back(CIRCLE);
    
    
    do{
        //diffCnt[shapeA][shapeB]:
        //shapeA 구역에 속해있는 shapeB의 개수
        vector<vector<int>> diffCnt(4, vector<int>(4, 0));

        int shapeIdx=0;

        for(int i=0;i<3;i++){
            int curCnt=cnt[compare[i]];

            for(int j=shapeIdx;j<shapeIdx+curCnt;j++){
                diffCnt[compare[i]][inputs[j]]++;
            }
            shapeIdx+=curCnt;
        }

        int tmpChange=0;

        //도형 1 위치 도형 2, 3을 도형 1로 바꾸기 위한 교체 횟수
        tmpChange+=diffCnt[1][2]+diffCnt[1][3];
        tmpChange+=max(diffCnt[2][3], diffCnt[3][2]);
        //도형2가 들어가야 하는 위치에 도형 3이 들어있는 도형 3,
        //도형 3이 들어가야 하는 위치에 도형 2가 들어있는 도형 2 교환

        minChange=min(minChange, tmpChange);
        
    } while(next_permutation(compare.begin(), compare.end()));

    
    cout<<minChange<<"\n";
    
    
    return 0;
}