#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

/*
    풀이과정
    태그: 그리디
    가장 큰 자릿수의 알파벳이 가장 큰 숫자가 되어야
    합이 가장 큼
    알파벳 스트링의 가장 긴 길이: len이라고 하면
    반복1==i:len-1~0까지(8)
        반복 2: 주어진 모든 스트링에 대해(10)
            만약 i값이 주어진 스트링의 길이보다 크면 continue;
            주어진 스트링에 i로 접근가능하면 숫자 할당
        반복 3:
    이때, unordered_map으로 이미 숫자 배정된 알파벳이면 가져다 쓰기

    잘못됨!!! ACC, CCC 같은 경우 더 빈번히 등장하는 C가 더 큰 수를 할당받아야 함
    ->가중치 주는 방식으로 변경

    시간복잡도
    O(n^2)
    최대 8(길이)*주어진 모든 스트링(10) -> 가능할듯?


    자료구조
    알파벳 스트링 저장하는 vector
    숫자 변환 후 저장하는 vector
    알파벳-숫자 매핑 map
*/

vector<string> alpha;
vector<string> num;
unordered_map<char, int> alphaToNum;
unordered_map<char, int> weightMap;
vector<pair<char, int>> weight;
int maxSum=0;
int assignedNum=9;

int maxStrLen(vector<string>&alpha){
    int maxLen=0;

    for(auto a:alpha){
        maxLen=max(maxLen, (int)a.size());
    }

    return maxLen;
}

int main() {
    int n;
    cin>>n;
    
    alpha.resize(n);
    num.resize(n);

    for(auto &a:alpha){
        cin>>a;
    }

    int maxLen=maxStrLen(alpha);

    
    for(auto word:alpha){
        int len=word.size();
        int powVal=1;
        for(int i=len-1;i>=0;i--){
            char c=word[i];

            weightMap[c]+=powVal;
            powVal*=10;
        }    
    }

    //가중치 map->가중치 vector
    for(auto it:weightMap){
        weight.push_back({it.first, it.second});
    }

    //가중치 vector 가중치 기준으로 내림차순 정렬
    sort(weight.begin(), weight.end(), [](PII a, PII b){
        if(a.second!=b.second)
            return a.second>b.second;
    });

    //가중치 순위 기반으로 숫자 할당    
    for(auto w: weight){
        //cout<<w.first<<" "<<w.second<<"\n";
        alphaToNum[w.first]=assignedNum;
        assignedNum--;
    }

    //alpha->num
    for(int i=0;i<n;i++){
        for(int j=0;j<alpha[i].size();j++){
            num[i]+=alphaToNum[alpha[i][j]]+'0';
        }
        //cout<<num[i]<<"\n";
    }

    for(auto i:num){
        maxSum+=stoi(i);
    }
    
    

    /*
    for(auto it=alphaToNum.begin();it!=alphaToNum.end();it++){
        cout<<it->first<<": "<<it->second<<"\n";
    }
    
    */

    

    cout<<maxSum<<"\n";
    
    
    return 0;
}