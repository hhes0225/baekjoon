#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a,b;
    int init=0;
    vector<int> nums;
    
    cin>>a>>b;

    for(int i=1;i<=a;i++){
        init+=i;
    }

    nums.push_back(init);

    for(int i=a+1;i<=b;i++){
        nums.push_back(nums[i-a-1]+i);
    }

    

    int mul=1;

    for(int i=a;i<=b;i++){
        mul = (mul * nums[i-a])%14579;
    }

    cout<<mul<<endl;
    
    
    return 0;
}