#include <iostream>
#include <vector>
using namespace std;

int n, s;
vector<int> nums;


int twoPointer(){
    int j=0;
    int sum=0;
    int result=1e5;
    //cout<<result<<"\n";

    for(int i=0;i<nums.size();i++){

        //j가 배열 크기 이내, 이전까지의 합+j의 합이 s 이상이어야 함
        while(j<n && sum<s){
            sum+=nums[j];
            j++;
        }

        //cout<<i<<"일때, "<<sum<<"\n";
        if(sum>=s)  
            result=min(result, j-i);
        sum-=nums[i];

    }

    return result;
}



int main() {
    cin>>n>>s;
    nums.resize(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int result = twoPointer();

    if(result == 1e5){
        cout<<-1<<"\n";
    }
    else
        cout<<twoPointer()<<"\n";

    return 0;
}