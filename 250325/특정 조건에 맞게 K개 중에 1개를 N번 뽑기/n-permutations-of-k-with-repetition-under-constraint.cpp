#include <bits/stdc++.h>

using namespace std;

int K, N;
unordered_map<int, int> dic;//연속 n번
vector<int> choice;

void backtracking(int n){
    if(n==0){
        for(auto c:choice){
            cout<<c<<" ";
        }
        cout<<"\n";

        return;
    }

    for(int i=1;i<=K;i++){
        if(dic[i]+1<3){//같은거 또 추가하면 3번이 되니까, 같은 건 0,1번까진 괜춘
            dic[i]++;//연속 누적 카운트
            choice.push_back(i);

            backtracking(n-1);
            
            //데이터 원복
            dic[i]--;
            choice.pop_back();
        }

    }
}

int main() {
    cin >> K >> N;

    for(int i=1;i<=K;i++){
        dic[i]=0;
    }

    backtracking(N);

    

    return 0;
}
