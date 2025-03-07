#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> LCS;
string s1, s2;

void dp(int n, int m){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s2[i-1]==s1[j-1]){
                LCS[i][j]=LCS[i-1][j-1]+1;
            }
            else{
                LCS[i][j]=max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }

    /*
    for(auto i:LCS){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";*/
}

int main() {
    cin>>s1>>s2;

    LCS.assign(s2.size()+1, vector<int>(s1.size()+1, 0));

    dp(s2.size(), s1.size());
    int maxLCSLen=*max_element(LCS[s2.size()].begin(), LCS[s2.size()].end());
    cout<<maxLCSLen<<"\n";

    if(maxLCSLen==0){
        return 0;
    }
    
    //DP에서 LCS 복원
    int s1Idx=s1.size();
    int s2Idx=s2.size();
    string ans="";

    //LCS dp 배열에서 경로 역추적
    while(s1Idx>0&&s2Idx>0){
        if(s1[s1Idx-1]==s2[s2Idx-1]){
            ans+=s1[s1Idx-1];//매칭되면 해당 문자 추가
            s1Idx--;s2Idx--;//대각선 이전으로 이동
        }
        else{//더 큰 값이 있는 방향으로 이동
            if(LCS[s2Idx-1][s1Idx]>=LCS[s2Idx][s1Idx-1]){
                s2Idx--;
            }
            else{
                s1Idx--;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    cout<<ans<<"\n";
    
    return 0;
}