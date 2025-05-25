#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int> cards(n);
    for(auto &c:cards) cin>>c;

    /*
        효율적인 비교 방법:
        적은 카드 묶음부터 뽑아서 비교하기
        
        10,20,100일 때,
        10+20, 10+20+100 처럼 누적되므로
        큰 카드 묶음은 최대한 마지막에 비교하는 것이 좋다.
        
        비교한 것도 pq에 넣어주어야 한다.(비교한 결과가 최소라는 보장이 없음)
        예를 들어, [13 14 18 24 73]일 때
        13+14=27, 그러나 27은 위에서 최소값이 아니므로
        [18 24 27 73] 으로 한번 더 넣어서 진짜 최소값끼리 연산되도록 해야 한다.
    */
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto c:cards) pq.push(c);

    int minCompare=0;

    //2묶음씩 뺄 수 있을 때까지 합치기 진행
    while(pq.size()>1){
        //카드를 ""두 묶음"" 씩 골라 서로 합쳐나간다.
        int a, b;
        a=pq.top(); pq.pop();
        b=pq.top(); pq.pop();
        // cout<<a+b<<"\n";
        
        minCompare+=(a+b);
        pq.push(a+b);
        //비교한 것도 pq에 넣어주어야 한다.(비교한 결과가 최소라는 보장이 없음)
    }

    cout<<minCompare<<"\n";
    
    return 0;
}