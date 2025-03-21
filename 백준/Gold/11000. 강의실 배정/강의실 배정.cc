#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

//https://eunsun-zizone-zzang.tistory.com/64
//위 링크에 반례 있다
//https://velog.io/@akimcse/%EB%B0%B1%EC%A4%80-C-11000%EB%B2%88-%EA%B0%95%EC%9D%98%EC%8B%A4-%EB%B0%B0%EC%A0%95

//문제 접근은 맞았는데(우선순위 큐 활용하는 방식)
//정렬을 끝나는 시간으로 정렬하는 바람에 틀렸다(이 경우 백준 질문게시판의 반례에서 3이 나와야 하는데 5가 나온다)
//이유: 빨리 끝나는 순으로 정렬하면 뒤에 나오는 값의 시작 시간이 더 빠를수도 있기 때문

vector<PII> classes;
priority_queue<int, vector<int>, greater<int>> minClass;

int main() {
    int n;
    cin>>n;

    classes.resize(n);

    for(auto &c:classes){
        cin>>c.first>>c.second;
    }

    //시작 시간 기준으로 오름차순 정렬
    sort(classes.begin(), classes.end(), [](PII a, PII b){
        if(a.first!=b.first){
            return a.first<b.first;
        }
        else{
            return a.second<b.second;
        }
    });

    minClass.push(classes[0].second);

    for(int i=1;i<n;i++){
        int endTime=minClass.top();

        //가장 빨리 끝나는 시간보다 시작 시간이 작거나 같을 때,
        //수업 들을 수 있음
        if(endTime<=classes[i].first){
            minClass.pop();
        }
        minClass.push(classes[i].second);
    }

    cout<<minClass.size()<<"\n";

    /*
    while(!minClass.empty()){
        cout<<minClass.top()<<" ";
        minClass.pop();
    }*/
    
    return 0;
}