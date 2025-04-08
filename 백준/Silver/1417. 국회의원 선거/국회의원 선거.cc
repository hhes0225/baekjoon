#include <bits/stdc++.h>
using namespace std;

vector<int> candidates;

int main() {
    int n;
    cin>>n;

    if(n==1){
        cout<<0<<"\n";
        return 0;
    }

    priority_queue<int> pq;//가장 득표수 많은 후보로 자동정렬

    candidates.resize(n);

    for(auto &c:candidates){
        cin>>c;
    }

    int dasom=candidates[0];

    for(int i=1;i<n;i++){
        pq.push(candidates[i]);
    }

    int bribe=0;

    //가장 득표 수 많은 후보가 다솜이가 아닐 경우
    //가장 득표 수 많은 후보가 다솜보다 작을 경우,
    //굳이 매수할 필요 없음
    while(dasom<=pq.top()){
        dasom++;//다솜 up
        int mostCand=pq.top(); pq.pop();//해당 후보 표 매수
        pq.push(mostCand-1);
        bribe++;
    }

    cout<<bribe<<"\n";
    
    return 0;
}