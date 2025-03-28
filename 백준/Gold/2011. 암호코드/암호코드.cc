#include <bits/stdc++.h>
using namespace std;
const int MOD=1'000'000;

vector<int> dp;
//i번째 숫자에서 가능한 암호 해석 경우의 수

void getPwCases(string pw){
    int sLen=pw.size();
    dp[0]=1;//2번째를 위함
    
    if(pw[0]=='0') dp[1]=0;//0으로 시작하는 경우 예외 처리
    else    dp[1]=1;//1번째 숫자에서 가능한 암호 해석은 1가지 뿐

    //dp는 1base, pw는 0base이므로 idx-1해야 함
    for(int i=2;i<=sLen;i++){
        // dp[i]=dp[i-1];//우선 최대 경우의 수 상속? 이어가기

        string twoDigit=pw.substr(i-2, 2);

        //1자리 수 가능한가?(본인만)
        //A가 1부터 시작하므로 0만 아니면 1자리 수 가능
        if(pw[i-1]!='0') dp[i]=(dp[i]+dp[i-1])%MOD;
        
        //2자리 수 가능한가?(이전+본인)
        if(stoi(twoDigit)>=10&&stoi(twoDigit)<=26) 
            dp[i]=(dp[i]+dp[i-2])%MOD;  
    }

    /*
    for(auto it:dp){
        cout<<it<<" ";
    }
    cout<<"\n";*/
    
}

int main() {
    string pw;
    cin>>pw;

    dp.assign(pw.size()+1, 0);

    getPwCases(pw);
    cout<<dp[pw.size()]<<"\n";

    
    return 0;
}