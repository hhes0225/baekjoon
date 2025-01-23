#include <bits/stdc++.h>
#define MAX 100'001
using namespace std;

vector<int> nums;

int main() {
    int n, s;

    cin>>n>>s;

    nums.resize(n+1, 0);

    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        nums[i]=nums[i-1]+tmp;//누적합 저장
    }

    int minLen=MAX;
    int end=1;

    for(int start =0;start<n;start++){
        while(end<=n&&nums[end]-nums[start]<s){
            end++;//부분합이 s 이상 될 때까지 end 증가
        }

        if(end<=n){//범위 내에서 부분합이 s 이상인 경우
            minLen=min(minLen, end-start);
        }
    }

    cout<<(minLen==MAX?0:minLen)<<"\n";
    
    return 0;
}