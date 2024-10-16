#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nums;

int main() {
    int len;
    cin>>len;
    nums.resize(len);

    for(int i=0;i<len;i++){
        cin>>nums[i];
    }

    sort(nums.begin(), nums.end());

    int ans=50;
    
    
    for(int left=0;left<nums.size();left++){//left 포인터
        int right = left+1;//right 포인터: 이게 움직일것임
        
        // right 포인터가 배열의 범위를 벗어나지 않으면서, 
        // 현재 값과 이전 값의 차가 1이어야 함: 연속이어야 함
        //중간에 숫자가 누락되었더라도, 최대한 적게 숫자를 추가해서 연속된 5개의 숫자를 만들 수 있어야 함
        while(right<nums.size() && nums[right]-nums[left]<=4){
            right++;
        }

        int continuous=right-left;
        
        ans=min(ans, 5-continuous);
    }

    cout<<ans<<"\n";
    
    return 0;
}