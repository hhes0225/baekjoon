#include <bits/stdc++.h>
using namespace std;

/*
    문제를 깔끔하게 정리할 수 있고
    학생마다 블록을 0~1개만 낼 수 있음
    블록 내는 순서는 고정되어있음
    탑 높이만큼 쌓아야 할 때 경우의 수 구해야 함->dp같다

    dp테이블 정의
    dp[i][h]: i번째 학생까지 블록 쌓았을 때, h 높이 만드는 경우의 수 
    
    내가 가진 블록으로 해당 수 만들 수 없을 경우
    ->내가 가진 블록이 h 높이를 초과할 경우
    dp[i][h]+=dp[i-1][h]: 이전 학생까지 블록 쌓은 경우 가져오기

    내가 가진 블록으로 해당 수 만들 수 있을 경우
    dp[i][h]+=dp[i-1][h-제출할 블록 높이]
*/

int n, m, h;
vector<vector<int>> dp;
vector<vector<int>> block;//[i]번째 학생들이 보유한 블록들


int dpFunc(){
    //높이 0을 만드는 경우의 수는 1가지, 전부 내지 않는 것
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }

    

    for(int i=1;i<=n;i++){//i번째 학생 순회
        for(int j=1;j<=h;j++){//높이 j 만드는 경우 순회
            //높이 제한, 학생이 가진 블록에 관계없이 이전 값 계승
            dp[i][j]+=dp[i-1][j];
            dp[i][j]%=10'007;
            
            //i번째 학생이 가진 블록 순회하며 높이 i 만들기
            for(int k=0;k<block[i].size();k++){
                //내가 가진 블록이 높이 제한 이내라면
                if(j-block[i][k]>=0){
                    dp[i][j]+=dp[i-1][j-block[i][k]];
                    dp[i][j]%=10'007;
                }
            }
        }
    }

    /*
    //dp 테이블 출력
    for(auto i:dp){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    */
    
    return dp[n][h];
}

int main() {
    cin>>n>>m>>h;
    cin.ignore();
    
    dp.assign(n+1, vector<int>(h+1, 0));
    block.resize(n+1);

    string input;
    for(int i=1;i<=n;i++){
        getline(cin, input);

        string tmp="";
        for(int j=0;j<input.size();j++){
            if(input[j]!=' '){
                tmp+=input[j];
            }
            else{
                block[i].push_back(stoi(tmp));
                tmp="";
            }

            if (j == input.size() - 1 && !tmp.empty()) {
                block[i].push_back(stoi(tmp));
            }
        }
    }

    /*
    for(auto i:block){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    */

    cout<<dpFunc()<<"\n";
    
    return 0;
}