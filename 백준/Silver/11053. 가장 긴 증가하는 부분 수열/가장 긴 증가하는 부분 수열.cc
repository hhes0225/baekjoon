#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dpTable;
//가장 긴 증가하는 부분 수열
//dpTable[i]: i번째 원소를 마지막으로 두었을 때의 LIS의 길이를 저장
//즉, nums[i]를 마지막 원소로 하는 가장 긴 증가하는 부분 수열
//돌면서 자기보다 작은 원소의 dp값 max 값을 +1한 값
//만약
//1 2 1 3 2 5 일 때, 3 이전 dp 값은 1 2 1 _ 이 될 것. 이때 2번째 값은 3보다 작으면서 dp 최대값을 가지고
//있기 때문에 3은 2+1=3 dp값을 가지게 될 것임
vector<int> nums;

void memoi(){
    dpTable[0]=1;

    if(nums[1]>nums[0]){
        dpTable[1]=dpTable[0]+1;
    }
    else{
        dpTable[1]=1;
    }

    for(int i=2;i<nums.size();i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                dpTable[i]=max(dpTable[i], dpTable[j]);
            }
        }
        
        dpTable[i]++;
    }
}

int main() {
    int tCase;
    

    cin>>tCase;
    nums.resize(tCase);
    dpTable.assign(tCase, 0);

    for(int i=0;i<tCase;i++){
        cin>>nums[i];
    }

    memoi();

    
    /*for(int i=0;i<tCase;i++){
        cout<<dpTable[i]<<" ";
    }*/
    

    cout<<*max_element(dpTable.begin(), dpTable.end())<<"\n";

    
    return 0;
}