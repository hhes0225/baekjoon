#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    LCS 알고리즘(Longest Common Subsequence)
    : 공통 부분 문자열 중 가장 길이가 긴 문자열

    substring: 전체 문자열에서 **연속된** 부분 문자열
    subsequence: 전체 문자열에서 **꼭 연속되지는 않은** 부분 문자열
    (단, 순서는 역순 X 기존 문자열 순서를 따름)

    LCS 알고리즘 -> DB로 해결
    2차원 배열로 i(세로축)은 원 문자열
    j(가로축)은 비교할 문자열

    만약 string[i]==string[j] 면? dp[i][j]++
    만약 다르면?
    뒤집어진 ㄴ으로 비교
    max(dp[i-1][j], dp[i][j-1])(왼쪽 칸, 위쪽 칸 비교해서 최대값)
    이렇게 하면 i축, j 축(세로, 가로 축) 전부 비교 가능
    
*/
string a, b;
vector<vector<int>> lcs;

void dp(){
    //2차원 배열 순회
    for(int i=1;i<lcs.size();i++){
        for(int j=1;j<lcs[i].size();j++){
            //a, b는 인덱스 0부터 시작
            //lcs 배열은 인덱스 1부터 시작
            if(a[i-1]==b[j-1]){
                lcs[i][j]=lcs[i-1][j-1]+1;
                //이전까지의 LCS길이 + 1
            }
            else{
                lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
    }
}


int main() {
    cin>>a>>b;

    lcs.resize(a.size()+1, vector<int>(b.size()+1, 0));

    dp();

    /*
    for(int i=1;i<lcs.size();i++){
        for(int j=1;j<lcs[i].size();j++){
            cout<<lcs[i][j]<<" ";
        }
        cout<<"\n";
    } */

    cout<<lcs[a.size()][b.size()]<<"\n";
    //마지막 인덱스까지 갈수록 계속 값이 누적되기 때문에(감소 X)
    //배열의 가장 마지막 값이 LCS의 최대값(최대길이)가 됨
    
    return 0;
}