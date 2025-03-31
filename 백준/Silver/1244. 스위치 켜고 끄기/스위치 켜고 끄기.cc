#include <bits/stdc++.h>
using namespace std;
const int Boy=1;
const int Girl=2;

vector<int> switches;
vector<pair<int, int>> command;

void changeState(int sNum){
    switches[sNum]= (switches[sNum]==1? 0:1);
}

void boyFunc(int total, int num){
    for(int i=1;i<=total;i++){
        if(i%num==0){
            changeState(i);
        }
    }
}

void girlFunc(int total, int num){
    //num 중심으로 대칭이면서 가장 많이 스위치 포함하는 구간 찾기
    int left=num-1;
    int right=num+1;
    int minLeft=num;
    int maxRight=num;
    while(left>=1 && right<=total){
        if(switches[left]==switches[right]){
            minLeft=left;
            maxRight=right;
        }
        else{
            break;
        }
        left--;
        right++;
    }

    //cout<<minLeft<<" "<<maxRight<<"\n";

    if(minLeft==maxRight){
        changeState(num);
    }
    else{
        for(int i=minLeft;i<=maxRight;i++){
            changeState(i);
        }
        
    }
    
    
}


int main() {
    int n, m;
    cin>>n;
    switches.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>switches[i];
    }


    cin>>m;
    command.resize(m);

    for(auto &c:command){
        cin>>c.first>>c.second;
    }

    for(auto c:command){
        auto [stuType, sNum]=c;

        if(stuType==Boy){
            boyFunc(n, sNum);
        }
        else{
            girlFunc(n, sNum);
        }

        // for(auto s:switches) cout<<s<<" ";
        // cout<<"\n==================\n";
    }

    for(int i=1;i<=n;i++){
        cout<<switches[i]<<" ";
        if(i%20==0) cout<<"\n";
    }
    
    return 0;
}