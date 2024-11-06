#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 vector<vector<int>> scores;

bool compare(vector<int> a, vector<int> b){
    if(a[1]!=b[1]){
        return a[1]>b[1];
    }
    else if(a[2]!=b[2]){
        return a[2]>b[2];
    }
    else{
        return a[3]>b[3];
    }
}

int main() {
    int len, country;
    cin>>len>>country;
    int rank=1;

    scores.assign(len, vector<int>(4));

    for(int i=0;i<len;i++){
        for(int j=0;j<4;j++){
            cin>>scores[i][j];
        }
    }

    sort(scores.begin(), scores.end(), compare);

    for (int i = 0; i < len; i++) {
        // 이전 국가와 메달 수가 다를 때에만 rank를 업데이트
        if (i > 0 && (scores[i][1] != scores[i - 1][1] || scores[i][2] != scores[i - 1][2] || scores[i][3] != scores[i - 1][3])) {
            rank = i + 1;
        }

        // 찾고자 하는 국가의 등수를 출력하고 종료
        if (scores[i][0] == country) {
            cout << rank << "\n";
            return 0;
        }
    }

    
    return 0;
}