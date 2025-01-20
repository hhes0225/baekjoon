#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;
typedef pair<ll, int> PLI;
typedef tuple<ll, int, int> T;//{종료시간, 계산대, 회원id}

/*
    문제를 읽고 자체 태그맞추기: pq 써야겠다

    처음에는(5분 태그맞추기)
    계산대 동시에 빠져나올 때 써야겠다 라고 생각했는데
    예제 입력으로 생각해보니까 어떤 계산대로 배치할까?에 
    pq를 쓰면 좋을 것 같았음
    {0,1} {0,2} {0,3} <-123,4 손님
    {0,2} {0,3} {4,1} 이런식으로..
    
*/

vector<PII> wait;//대기 상태
//vector<deque<PII>> process;//처리 상태
vector<T> process;
vector<PII> complete;//완료, 쇼핑몰 빠져나가기 전

void assignCounter(int n, int k){
    //대기시간 짧고, 카운터 번호 작은 것부터!
    priority_queue<PLI, vector<PLI>, greater<PLI>> pq;

    for(int i=0;i<k;i++){
        pq.push({0LL, i});//{대기시간, 카운터번호}
    }

    for(int i=0;i<n;i++){
        auto [waitTime, counter] = pq.top();
        auto [customer, addTime] = wait[i];
        
        process.push_back({waitTime+addTime, counter, customer});
        pq.push({waitTime+addTime, counter});
        pq.pop();
    }

    /*
    //카운터 배치된 카트 출력
    for(auto i:process){
        auto [a,b,c]=i;
        cout<< a<<" "<<b<<" "<<c<<" | ";
        cout<<"\n";
    }
    cout<<"\n";
    */
}
void payCounter(int k){
    //종료시간: 오름차순
    //카운터: 내림차순
    sort(process.begin(), process.end(), [](T& a, T& b){
        auto &[aFin, aCounter, aId]=a;
        auto &[bFin, bCounter, bId]=b;

        if(aFin!=bFin) return aFin<bFin;
        else return aCounter>bCounter;
    });

    /*
    //카운터 배치된 카트 출력
    for(auto i:process){
        auto [a,b,c]=i;
        cout<< a<<" "<<b<<" "<<c<<" | ";
        cout<<"\n";
    }
    */
}

ll escapeStore(int n){
    ll answer=0;

    for(ll i=0;i<n;i++){
        auto [fin, counter, id]=process[i];
        answer+=((i+1)*id);
    }

    return answer;
}



int main() {
    int n, k;
    cin>>n>>k;
    
    wait.resize(n);

    for(int i=0;i<n;i++){
        cin>>wait[i].first>>wait[i].second;
    }
    
    assignCounter(n, k);
    payCounter(k);
    cout<<escapeStore(n)<<"\n";
    
    return 0;
}

/*
//개삽질 ver. 이것도 맞긴 함.
//틀린 이유는 escapeStore에서 ll i로 안해줘서 그랬음.

void payCounter(int k){
    priority_queue<PII> finish;//{카운터, 회원번호}

    while(1){
        //무한루프 탈출조건
        bool isEmpty=true;
        for(int i=0;i<k;i++){
            if(process[i].size()!=0){
                isEmpty=false;
            }
        }

        if(isEmpty){
            break;
        }

        //[j][0] 인덱스 손님만 본다
        int minTime=100;
        for(int j=0;j<k;j++){
            //이미 손님 다 처리했으면
            if(process[j].size()==0) continue;
            minTime=min(minTime, process[j][0].second);
        }

        //최소시간과 같으면 큐에 넣고 배열에서 제거
        for(int j=0;j<k;j++){
            //이미 손님 다 처리했으면
            if(process[j].size()==0) continue;

            if(process[j][0].second==minTime){
                finish.push({j, process[j][0].first});
                process[j].pop_front();
            }
            else{
                process[j][0].second-=minTime;
            }
        }

        //더 큰 수 카운터에서 나온 순대로 나온 손님 리스트에 추가
        while(!finish.empty()){
            getOut.push_back(finish.top().second);
            finish.pop();
        }

    }   

}
*/
