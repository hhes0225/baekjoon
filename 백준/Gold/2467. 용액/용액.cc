#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<long long> liquid;
    liquid.resize(n);

    for(int i=0;i<n;i++){
        cin>>liquid[i];
    }

    int liq1=0, liq2=n-1;
    long long minSum=2e9;
    //범위에서 가능한 최댓값은 2e9
    //left=1e9, right=1e9일 경우, 최댓값은 2e9
    int left=0, right=n-1;

    while(left<right){
        //cout<<liquid[left]<<" "<<liquid[right]<<"\n";
        long long sum = liquid[right]+liquid[left];
        long long absSum=abs(sum);
        //cout<<sum<<"\n";
        
        if(sum==0){
            liq1=left;
            liq2=right;
            break;
        }

        if(absSum<minSum){
            minSum=absSum;
            liq1=left;
            liq2=right;
        }
        
        if(sum>0){//차가 양수면, 0이 되기 위해서는 더 작은 양수가 필요하다
            right--;
        }
        else{//차가 음수면, 0으로 만들기 위해 더 작은 음수가 필요하다.
            left++;
        }

        
        
    }

    cout<<liquid[liq1]<<" "<<liquid[liq2]<<"\n";
    
    return 0;
}