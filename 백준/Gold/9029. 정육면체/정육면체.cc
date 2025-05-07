#include <bits/stdc++.h>
using namespace std;
const int MAX=201;
int cube[MAX][MAX][MAX];

//dp[w][l][h]: w*l*h 크기 직육면체를 정육면체로 나눌 때 최소 조각 수
int dp(int w, int l, int h){
    if(w==l&&l==h) return 1;//이미 정육면체이면 나눌 필요 없음

    if(cube[w][l][h]) return cube[w][l][h];//이미 계산했다면 또 계산 X

    int minPiece=INT_MAX;

    //w/2, l/2, h/2로 범위 설정하여 중복 계산 줄이기(이거 안하면 시간초과)
    // dp(1,l,h)+dp(9,l,h)==dp(9,l,h)+dp(1,l,h) 이므로
    //w방향 자르기
    for(int i=1;i<=w/2;i++){
        minPiece=min(minPiece, dp(i,l,h)+dp(w-i,l,h));
    }

    //L방향 자르기
    for(int i=1;i<=l/2;i++){
        minPiece=min(minPiece, dp(w,i,h)+dp(w,l-i,h));
    }

    //h방향 자르기
    for(int i=1;i<=h/2;i++){
        minPiece=min(minPiece, dp(w,l,i)+dp(w,l,h-i));
    }

    cube[w][l][h]=minPiece;

    return cube[w][l][h];
}



int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++){
        int width, length, height;
        cin>>width>>length>>height;
        cout<<dp(width, length, height)<<"\n";
    }

    
    return 0;
}