#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

vector<PII> scores;
vector<bool> success;

bool comp(const PII&a, const PII&b){
    return a.second<b.second;
}

int main() {
    int tCase;
    cin>>tCase;

    for(int i=0;i<tCase;i++){
        int n;
        int employed=0;
        cin>>n;
        

        scores.resize(n);
        success.assign(n, false);

        for(auto& s:scores){
            cin>>s.first>>s.second;
        }

        //정렬
        sort(scores.begin(), scores.end());

        employed++;//첫번째 사람은 항상 합격
        int bestInterview=scores[0].second;//서류 1등의 면접점수

        //2번째 사람부터 인터뷰 등수 비교
        for(int i=1;i<n;i++){
            if(scores[i].second<bestInterview){
                employed++;
                bestInterview=scores[i].second;
            }
        }

        
        cout<<employed<<"\n";
    }
    return 0;
}