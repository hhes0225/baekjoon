#include <bits/stdc++.h>
using namespace std;

/*
    매개변수탐색(+ 이진탐색) 어렵게 생각했는데 어떻게 하는지 약간 감이 왔다.
    재미(?)를 느껴서 좀 더 풀어보고싶다!
    
    # 매개 변수 탐색
    - 이진 탐색(Binary search)와 상당히 유사
    - 최적화 문제를 "결정 문제"로 풀 수 있는 알고리즘
    - 시간 복잡도(Time complexity): O(log N)

    # 매개 변수 탐색(Parametric Search)을 사용하는 경우
    - 어떤 시점까지는 조건을 만족하지만, 그 후로는 조건을 만족하지 않는 경우. 조건을 만족하는 최대값
    - 어떤 시점까지는 조건을 만족하지 않지만, 그 후로는 조건을 만족하는 경우. 조건을 만족하는 최소값
    -> 조건에 만족하는 최소값/최대값을 찾는 문제

    # 매개변수 param과 결정함수fn(param)
    - param == mid ==  (left + right) / 2
    - fn(param) == param이 조건을 만족하면 true를, 만족하지 않으면 false를 반환, 이후 이 결과에 따라 param이 변경됨
*/

int n, x;
vector<int> duration;

//병렬 처리이지만 실제 중요한 것은 각 공정 라인의 총 작업량
//작업 자체가 중요X, 각 라인의 작업량 X 초과하지 않도록 배치
//->가장 작업량 적은 라인 선택
bool operatable(int lines){
    //최소 작업시간이 필요하므로 최소 힙 사용
    priority_queue<int, vector<int>, greater<int>> pq;

    //lines개(==mid) 의 생산 라인에 초기 작업 추가
    for(int i=0;i<lines;i++){
        pq.push(duration[i]);
    }

    //가장 소요시간 적은 라인에 업무 추가
    for(int i=lines;i<duration.size();i++){
        int newWork=pq.top()+duration[i];
        pq.pop();
        pq.push(newWork);
    }

    //모든 공정 라인 작업량이 x 이하인지 확인
    while(!pq.empty()){
        //cout<<pq.top()<<"\n";
        if(pq.top()>x){
            return false;
        }
        pq.pop();
    }

    return true;
}

int main() {
    cin>>n>>x;
    duration.resize(n);
    
    for(int i=0;i<n;i++){
        cin>>duration[i];
    }

    //이분탐색
    //left == 공정 라인 최소 개수 == 1
    //right == 공정 라인 최대 개수 == n(모든 업무가 서로 다른 라인에서 처리)
    int left=1, right=n;
    int answer=-1;

    while(left<=right){
        int mid=(left+right)/2;

        //현재 라인으로 x 시간 내에 완수 가능하다면,
        //더 적은 라인으로도 완수가능한지 찾기 위해 right 감소
        if(operatable(mid)){
            answer=mid;
            right=mid-1;
        }
        //현재 라인으로 x 시간 내 완수 불가능하다면
        //더 많은 라인을 사용했을 때에는 완수 가능한지 확인->left 증가
        else{
            left=mid+1;
        }
    }
    

    cout<<answer<<"\n";
    
    return 0;
}
