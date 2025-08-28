#include <bits/stdc++.h>
using namespace std;

vector<int> ribbon;
vector<int> compressed;

int main() {
    int n;
    cin>>n;

    int result=0;
    
    ribbon.resize(n);
    for(auto& r:ribbon) cin>>r;

    compressed=ribbon;

    sort(compressed.begin(), compressed.end());
    //중복 값 없음->unique 안해도 됨

    for(auto&r:ribbon){
        auto compressedVal = lower_bound(compressed.begin(), compressed.end(), r);

        // cout<<compressedVal-compressed.begin()<<" ";
        r=compressedVal-compressed.begin();
    }

    for(int i=1;i<n;i++){
        //연속 수가 아니라면
        //숫자 조각의 순서 뒤집을 수 있으므로(ex_1 2 -> 2 1)
        //비교 숫자가 현 숫자보다 1만 크거나 1만 작아야 한다.
        if(ribbon[i-1]!=ribbon[i]-1 && ribbon[i-1]!=ribbon[i]+1){
            // cout<<i<<"에서 끊어\n";
            result++;
        }
    }

    cout<<result<<"\n";
    
    return 0;
}