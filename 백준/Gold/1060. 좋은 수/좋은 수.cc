#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;

/*
    https://github.com/devxb/JJUNalgo/blob/master/1060%20%EC%A2%8B%EC%9D%80%20%EC%88%98/main.cpp
    
    5 11 18일 경우
    1~4, 6~10, 12~17, 19~INF의 범위가 나올 수 있음
    이때 s에 있는 모든 요소(5,11,18)는 좋은 구간
    ->좋은 구간의 크기가 0이기 때문(구간에 포함될 수 없음)


    이제 이 범위들을 탐색하며 좋은 수를 찾기
    n = 1 일 경우 1을 포함하는 좋은 범위:
    1 ~ 4
    1 ~ 3
    1 ~ 2
    정수 1 의 좋은 범위는 3개이며, 1은 3만큼 좋은 수


    n = 2 일 경우 2를 포함하는 좋은 범위:
    1 ~ 4
    1 ~ 3
    1 ~ 2
    2 ~ 4
    2 ~ 3
    정수 2의 좋은 범위는 5개 이며, 2는 5만큼 좋은 수 이다.

    이때, A~INF 인 경우 좋은 범위도 무한대, 굳이 탐색하지 X

    
*/
int l, n;
set<ll> used;
priority_queue<PLL, vector<PLL>, greater<PLL>> goodNums;//{cnt, 수}

void findGoodNums(ll left, ll right){
    ll rangeCnt= right-left;//구간 길이
    ll inc = rangeCnt-1;//
    ll pushCnt=0;//현재까지 넣은 개수

    ll mid=(left+right)/2;//중앙값 기준으로 좌우 대칭 삽입
    //중앙을 기준으로 왼쪽에서 i만큼, 오른쪽에서 i만큼 떨어진 값을 양쪽으로 삽입

    for(ll i=0;i<=mid;i++){
        if(pushCnt>n||right-i<left+i) break;
        //출력할 개수 초과하거나 탐색 범위 끝날 경우

        ll a=left+i;
        ll b=right-i;

        goodNums.push({rangeCnt, left+i});//왼쪽 i만큼 떨어진 수 추가
        pushCnt++;

        if(a!=b){//같으면 중복이므로 생략
            goodNums.push({rangeCnt, right-i});
            pushCnt++;
        }

        rangeCnt+=inc;
        inc-=2;//좌우대칭으로 넣으므로 2씩 감
    }
}


int main() {
    vector<ll> s;//중복 수 없음 보장

    cin>>l;
    s.resize(l);

    for(auto &i:s){
        cin>>i;
        goodNums.push({0, i});//S에 있는 수는 무조건 좋은 구간 0
    }
    cin>>n;

    sort(s.begin(), s.end());
    //구간 확인하기 위함
    //5 11 18일 경우
    //1~4, 6~10, 12~17, 19~1'000'000'000의 범위가 나올 수 있음


    findGoodNums(1, s[0]-1);
    
    for(ll i=0;i<l-1;i++){
        findGoodNums(s[i]+1, s[i+1]-1);
    }

    int cnt=0;
    set<ll> printedSet;
    while(!goodNums.empty()&&cnt<n){
        ll val=goodNums.top().second;
        goodNums.pop();

        if(printedSet.count(val)) continue;
        cout<<val<<" ";
        printedSet.insert(val);
        
        cnt++;
    }

    //부족한 경우 1부터 추가
    for(ll val=1;cnt<n;val++){
        if(printedSet.count(val)) continue;
        cout<<val<<" ";
        cnt++;
    }
    
    cout<<"\n";
    
    
    return 0;
}