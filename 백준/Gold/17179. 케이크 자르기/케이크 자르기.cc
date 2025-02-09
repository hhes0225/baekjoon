#include <bits/stdc++.h>
using namespace std;

vector<int> cutPoint;
int n, m, l;

int cutCakeMinLength(int minLen){
    int startPoint=0;
    int totalCuts=0;
    
    for(int i=0;i<cutPoint.size();i++){
        int pieceLength=cutPoint[i]-startPoint;
        if(pieceLength >= minLen){
            startPoint=cutPoint[i];
            totalCuts++;
        }
    }

    if(l-startPoint>=minLen){
        totalCuts++;
    }

    return totalCuts;
}

int binSearch(int len, int cutCount){
    //""최솟값의 최대화""
    //설정한 최솟값(mid)이 최솟값들 중 최댓값이 맞는가?
    //->이분탐색(매개변수 탐색)
    int left=0, right=len;
    int answer=0;

    while(left<=right){
        int mid=(left+right)/2;
        //cout<<left<<" "<<mid<<" "<<right<<"\n";
        //cout<<cutCakeMinLength(mid)<<"\n";


        //mid로 쪼갠 횟수가 목표 카운트보다 많다==너무 짧게 짜잘하게 잘랐다
        //mid(최소 조각 길이)를 좀 더 크게 해볼까?
        if(cutCakeMinLength(mid)>=cutCount+1){
            answer=mid;
            left=mid+1;
        }
        //mid로 쪼갠 횟수가 목표 카운트보다 적다==너무 길게 듬성하게 잘랐다
        //mid(최소 조각 길이)를 좀 더 작게 해볼까?
        else{
            right=mid-1;
        }
    }

    return answer;
}

int main() {
    
    cin >> n >> m >> l;

    cutPoint.resize(m);

    for(auto& c:cutPoint){
        cin>>c;
    }

    
    for(int i=0;i<n;i++){
        int cnt;
        cin>>cnt;
        cout<<binSearch(l, cnt)<<"\n";
    }

    
    
    return 0;
}