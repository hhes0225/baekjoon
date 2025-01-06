#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

/*
    일단 형태가 좀 익숙했음(다른 알고리즘이긴 하지만 모기싫어싫어 등등..)
    아 일단 정렬을 해야겠다.
    q에서 인덱스를 받으니까 인덱스도 같이 저장해야겠다.
    
    그러면 {{{x1,x2}},y},idx} 꼴이 되어서 복잡해지겠다.
    다시 보니까 y축은 별로 중요하지 않음.
    경로를 물어보지 않으므로 그냥 x로 연결만 되어 있으면 이동 가능
    따라서 y 저장하지 않고 {{x1,x2}, idx}만 저장

    그런데 이 이후에 disjoint set를 써야 하는 것을 감을 잡지 못했음
    https://davincicoding.co.kr/107
    (또 기존에 썼던 disjoint set는 주로 크루스칼에서 썼는데
    여기는 좌표값이 주어졌으므로 disjoint set를 어떻게 써야 할지 몰랐음
    경험 부족)
*/
vector<pair<PII, int>> lines;
vector<int> parent;

int Find(int x){
    if(parent[x]==x){
        return x;
    }

    return parent[x]=Find(parent[x]);
    //parent[x]에 최신 루트 노드 정보 업데이트
}

void Union(int a, int b){
    a=Find(a);
    b=Find(b);

    if(a<b){//작은 값을 부모로
        parent[b]=a;
    }
    else{
        parent[a]=b;
    }
}


int main() {
    int n, q;
    cin>>n>>q;

    for(int i=0;i<n;i++){
        int x1, x2, y;

        cin>>x1>>x2>>y;

        lines.push_back({{x1, x2}, i+1});
        //i+1==idx
        //y는 결국에 필요하지 않다는 것이 포인트
    }

    sort(lines.begin(), lines.end());

    /*
    for(auto it:lines){
        cout<<it.first.first<<" "<<it.first.second<<" "<<it.second<<"\n";
    }
    */

    parent.resize(n+1);
    for(int i=0;i<parent.size();i++){
        parent[i]=i;
    }

    int start, end;
    start=lines[0].first.first;
    end=lines[0].first.second;

    //Disjoint Set 만들기
    for(int i=1;i<lines.size();i++){
        int nextStart=lines[i].first.first;
        int nextEnd=lines[i].first.second;
        int nextIdx=lines[i].second;
        
        if(end<nextStart){//통나무 연결 끊길 때
            start=nextStart;
            end=nextEnd;
        }
        else{
            int idx = lines[i-1].second;
            Union(idx, nextIdx);
            end=max(end, nextEnd);//선 확장
        }
    }

    /*
    for(auto it:parent){
        cout<<it<<" "; 
    }
    cout<<"\n";
    */

    //Q에 대한 답
    for(int i=0;i<q;i++){
        int from, to;
        cin>>from>>to;

        //만약 루트가 같다면==같은 집합 내라면
        //from에서 to까지 도달 가능
        if(Find(from)==Find(to)){
            cout<<"1\n";
        }
        else{
            cout<<"0\n";
        }
    }

    return 0;
}