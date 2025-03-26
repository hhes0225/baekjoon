#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> A;
vector<int> choice;
int maxXOR=0;

void backtracking(int curIdx, int pickCnt){
    if(pickCnt==m){
        int tmpResult=0;

        for(auto c:choice){
            tmpResult^=c;
        }

        maxXOR=max(maxXOR, tmpResult);
    }

    for(int i=curIdx+1;i<n;i++){
        choice.push_back(A[i]);

        backtracking(i, pickCnt+1);

        choice.pop_back();
    }
}

int main() {
    cin >> n >> m;

    A.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Please write your code here.
    backtracking(-1, 0);
    cout<<maxXOR<<"\n";

    return 0;
}