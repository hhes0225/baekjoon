#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
vector<int> compressed;

int main() {
    int n;
    cin>>n;

    nums.resize(n);

    //1-또 다른 배열 compressed에 추가로 입력받는다
    for(int i=0;i<n;i++){
        cin>>nums[i];
        compressed.push_back(nums[i]);
    }

    //2-compressed 배열 압축하기 위해 정렬
    sort(compressed.begin(), compressed.end());

    //3-unique 사용하여 compressed 배열의 중복 제거하여 압축
    //값이 아니라 인덱스를 보고 맵핑하기 위해 압축한다
    //값이 중요한 것이 아니라 상대적인 값만 보면 되기 때문
    //이로 인해 좌표 range를 축소할 수 있다.
    compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());

    /*
    for(auto it:compressed){
        cout<<it<<" ";
    }
    cout<<"\n";
    */

    for(int i=0;i<n;i++){
        int val = lower_bound(compressed.begin(), compressed.end(), nums[i])-compressed.begin();
        cout<<val<<" ";
    }
    cout<<"\n";

    

    return 0;
}