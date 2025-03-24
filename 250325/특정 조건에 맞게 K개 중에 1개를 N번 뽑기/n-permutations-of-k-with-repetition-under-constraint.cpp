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
        if(choice.size()>=2&&choice.back()==i&&choice[choice.size()-2]==i){
            continue;
        }
        

        choice.push_back(i);

        backtracking(n-1);
        
        //데이터 원복
        choice.pop_back();

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
