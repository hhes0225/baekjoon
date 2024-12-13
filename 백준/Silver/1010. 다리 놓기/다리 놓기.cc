#include <bits/stdc++.h>
using namespace std;

/*
    서쪽보다 동쪽 다리 개수가 더 많을 때, 
    동쪽과 서쪽 다리를 잇자
    이때, 순서는 중요하지 않음.
    -> 조합으로 풀까?

    n(동쪽다리)Cr(서쪽다리)
    이 조합을 dp로 풀자.
    30!는 어마무시하게 큰 수가 나오므로

    조합의 성질인

    (n k) = (n-1 k) + (n-1 k-1)
    을 이용하자.
*/



int dp(vector<vector<int>>&comb, int w, int e){
    //init
    for(int i=0;i<=e;i++){
        comb[i][0]=1;
    }

    //점화식
    for(int i=1;i<=e;i++){
        for(int j=1;j<=w;j++){
            comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
        }
    }


    /*
    //dp테이블출력
    for(auto it: comb){
        for(auto it2:it){
            cout<<it2<<" ";
        }
        cout<<"\n";
    }
    */

    return comb[e][w];
}

int main() {
    int tCase;

    cin>>tCase;

    for(int i=0;i<tCase;i++){
        vector<vector<int>> combination;
        int w, e;
        cin>>w>>e;

        combination.assign(e+1, vector<int>(w+1, 0));

        cout<< dp(combination, w, e)<<"\n";
        
    }
    return 0;
}