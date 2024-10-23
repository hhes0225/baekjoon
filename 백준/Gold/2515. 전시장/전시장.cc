#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s;
vector<pair<int, int>> paintings;
vector<int> dp;
vector<int> heights;
//dp[i]: i번째 그림까지 배치했을 때 최대 가격의 합
//그림 선택하지 않는 경우: 값 dp[i-1] 유지
//그림 선택하는 경우: dp[i-1]+paintings[i].second


//시간복잡도 줄이기 위해 이분탐색 적용 - O(nlogn)
void dpFunc(){
    dp[0]=paintings[0].second;

    for(int i=1;i<n;i++){
        dp[i]=dp[i-1];

        //이분 탐색으로 이전 그림들 중 S 이상의 높이 차이가 나는 최초의 그림 찾기
        int left =0, right=i-1, best=-1;
        while(left<=right){
            int mid=(left+right)/2;

            if(paintings[i].first-paintings[mid].first>=s){
                best=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        if(best!=-1){
            dp[i]=max(dp[i], dp[best]+paintings[i].second);
        }
        else{//현재 그림만 선택
            dp[i]=max(dp[i], paintings[i].second);
        }
    }

}

/*시간초과-날거같긴했음 O(n^2)
void dpFunc(){
    dp[0]=paintings[0].second;
    //heights[0]=paintings[0].first;

    for(int i=1;i<n;i++){
        dp[i]=dp[i-1];
        
        for(int j=i-1;j>=0;j--){
            //높이 s 이상일 경우만
            if(paintings[i].first-paintings[j].first>=s){
                dp[i]=max(dp[i], dp[j]+paintings[i].second);
            }
        }  
    }

    
    for(int i=0;i<dp.size();i++){
        cout<<dp[i]<<"\n";
    }
    
}
*/

int main() {
    cin>>n>>s;

    dp.assign(n, 0);
    heights.resize(n);

    for(int i=0;i<n;i++){
        int height, price;
        cin>>height>>price;

        paintings.push_back({height, price});
    }

    //키 기준으로 정렬
    sort(paintings.begin(), paintings.end());

    dpFunc();

    cout<<dp[n-1]<<"\n";
    
    return 0;
}
