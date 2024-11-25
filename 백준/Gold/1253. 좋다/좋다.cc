#include <bits/stdc++.h>
using namespace std;

int length;
vector<long long> nums; 
int ans=0;

void twoPointer(int i){
    int left=0, right=length-1;

    while(left<right){
        int sum=nums[left]+nums[right];

        //자기 자신 제외 서로 다른 두 수의 합-> 자기 자신 포함할 수 없으므로
        if(left==i){
            left++;
            continue;
        }
        if(right==i){
            right--;
            continue;
        }

        //조건 충족
        if(sum==nums[i]){
            //cout<<sum<<"를 만들 수 있다! "<<left<<"와 "<<right<<"\n";
            ans++;
            break;
        }
        
        //만약 합이 찾고자 하는 값보다 작으면? 더 큰 값 더해야 함->left++
        if(sum<nums[i]){
            left++;
        }
        //만약 합이 찾고자 하는 값보다 크면? 더 작은 값으로 더해야 함->right--
        else{
            right--;
        }
    }
}


int main() {
    cin>>length;

    nums.resize(length);

    for(int i=0;i<length;i++){
        cin>>nums[i];
    }

    sort(nums.begin(), nums.end());
    
    for(int i=0;i<length;i++){
        twoPointer(i);
    }

    cout<<ans<<"\n";
    
    return 0;
}