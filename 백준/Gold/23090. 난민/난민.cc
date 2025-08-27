#include <bits/stdc++.h>
using namespace std;


/* 
    정수 시설의 x축 위치는 0으로 고정
    x 축 위치는 단순 |x위치|의 총합
    정수 시설 위치에 전혀 영향을 주지 않음.

    정수 시설의 y축 위치는 median일 때 거리 최소.

    1) y축 갱신될 때마다 정렬
    nlogn(정렬) * n(최대 난민 수) = n^2logn
    n max = 100'000 이므로 시간 초과 확정

    2) max heap pq, min heap pq 
    
*/
typedef long long ll;
typedef pair<ll, ll> PLL;

int main() {
    int n;
    cin>>n;

    ll xSum=0;

    vector<PLL> refugee;
    priority_queue<int> left;
    //큰->작(가장 큰 값이 top)
    //중앙값 이하 값들을 담음
    priority_queue<int, vector<int>, greater<int>> right;
    //작->큰(가장 작은 값이 top)
    //중앙값 초과 값들을 담음
    ll sumL=0, sumR=0;
    
    auto rebalance = [&](){
        //left.size>=right.size 유지

        //right->left로
        if(left.size()<right.size()){
            ll v=right.top();right.pop();
            sumR-=v; sumL+=v;
            left.push(v);
        }
        //left->right로
        else if(left.size()>right.size()+1){
            //"짝수일 때는 항상 작은 쪽 중앙값을 골라야 하므로"
            ll v = left.top(); left.pop();
            sumL-=v; sumR+=v;
            right.push(v);
        }
    };
    
    refugee.resize(n);

    for(auto& [x, y]:refugee){
        cin>>x>>y;
    }
    
    for(auto [x, y]:refugee){
        xSum+=abs(x);

        if(left.empty()||y<=left.top()){
            left.push(y);
            sumL+=y;
        }
        else{
            right.push(y);
            sumR+=y;
        }

        rebalance();

        //하위 중앙값        
        //"짝수일 때는 항상 작은 쪽 중앙값을 골라야 하므로" left의 top
        ll m=left.top();

        ll cntL = (ll)left.size();
        ll cntR = (ll)right.size();

        ll sumAbsY=m*cntL-sumL+sumR-m*cntR;

        ll total=xSum+sumAbsY;
        cout<<m<<" "<<total<<"\n";

    }
    
    return 0;
}