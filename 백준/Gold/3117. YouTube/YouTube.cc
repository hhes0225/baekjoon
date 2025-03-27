#include <bits/stdc++.h>
using namespace std;
const int MAX=31;//2^30까지 검사

vector<vector<int>> st;
vector<int> watchVid;

//학생이 처음 본 영상 vidNum에서 min번 이동(1분에 1개만 보기 때문)
int getVidNum(int vidNum, int min){
    for(int i=0;i<MAX;i++){
        if(min&(1<<i)) vidNum=st[i][vidNum];
    }

    return vidNum;
}

int main() {
    int n,k,m;
    cin>>n>>k>>m;

    watchVid.resize(n);
    st.resize(MAX, vector<int> (k+1));

    for(auto &w:watchVid) cin>>w;
    //초기 간선 정보 저장
    for(int i=1;i<=k;i++) cin>>st[0][i];

    // sparse table 채우기
    for(int p=1;p<MAX;p++){
        for(int i=1;i<=k;i++) st[p][i]=st[p-1][st[p-1][i]];
    }

    for(auto w:watchVid){
        cout<<getVidNum(w, m-1)<<" ";
        //m분에 접어들었을 때 시청하는 영상==0분에서 m-1분에서 동영상이 이동하는 결과
        //m분 후에는 m+1분에 시청할 동영상으로 바뀔 것임
    }
    cout<<"\n";
    
    return 0;
}