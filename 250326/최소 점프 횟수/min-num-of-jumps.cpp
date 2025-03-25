#include <bits/stdc++.h>

using namespace std;

int n;
int num[10];
int minJump=INT_MAX;

void backtracking(int idx, int jump){
    if(idx==n-1){
        minJump=min(minJump, jump);
        return;
    }

    for(int i=0;i<num[idx];i++){
        backtracking(idx+i+1, jump+1);
    }

}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    // Please write your code here.
    backtracking(0,0);
    
    if(minJump==INT_MAX) cout<<-1<<"\n";
    else cout<<minJump<<"\n";

    return 0;
}
